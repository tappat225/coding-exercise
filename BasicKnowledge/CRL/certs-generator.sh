#!/bin/bash

echo "<<<<<<<<<<< Start generating certificates and CRL ... >>>>>>>>>>>>>>>>"

outpath="certsDir"
configFile="openssl.cnf"
cert1="cert"
cert2="cert-revoked"

# Initialize
rm -rf ${outpath}
mkdir ${outpath}
cd ${outpath}

# Prepare configuratoin files
touch index.txt
echo 01 > serial
echo 1000 > crlnumber
chmod 600 index.txt serial crlnumber

cat <<EOF > ${configFile}
[ ca ]
default_ca      = CA_default            # The default ca section

[ CA_default ]
dir             = ./             # Where everything is kept
certs           = ./            # Where the issued certs are kept
crl_dir         = ./              # Where the issued crl are kept
database        = ./index.txt        # database index file.
new_certs_dir   = ./newcerts            # default place for new certs.
certificate     = ./ca-cert.pem         # The CA certificate
serial          = ./serial           # The current serial number
crlnumber       = ./crlnumber        # the current crl number
crl             = ./crl.pem          # The current CRL
private_key     = ./ca-key.pem # The private key
x509_extensions = cert                 # The extensions to add to the cert
name_opt        = ca_default            # Subject Name options
cert_opt        = ca_default            # Certificate field options

# crlnumber must also be commented out to leave a V1 CRL.
# crl_extensions = crl_ext

default_days    = 365                   # how long to certify for
default_crl_days= 30                    # how long before next CRL
default_md      = sha256                # use SHA-256 by default
preserve        = no                    # keep passed DN ordering

policy          = policy_match

# For the CA policy
[ policy_match ]
countryName             = optional
stateOrProvinceName     = optional
organizationName        = optional
organizationalUnitName  = optional
commonName              = supplied
emailAddress            = optional

####################################################################
[ req ]
default_bits            = 2048
default_md              = sha256
default_keyfile         = privkey.pem
distinguished_name      = req_distinguished_name
attributes              = req_attributes
x509_extensions = v3_ca # The extensions to add to the self signed cert

[ req_distinguished_name ]
countryName                     = Country Name (2 letter code)
countryName_default             = IN
stateOrProvinceName             = State or Province Name (full name)
stateOrProvinceName_default     = Karnataka
localityName                    = Locality Name (eg, city)
localityName_default            = Bengaluru
0.organizationName              = Organization Name (eg, company)
0.organizationName_default      = GoLinuxCloud
organizationalUnitName          = Organizational Unit Name (eg, section)
organizationalUnitName_default  = Admin

commonName                      = Common Name (eg, your name or your server\'s hostname)
commonName_max                  = 64

emailAddress                    = Email Address
emailAddress_max                = 64

[ req_attributes ]
challengePassword               = A challenge password
challengePassword_min           = 4
challengePassword_max           = 20
unstructuredName                = An optional company name

[ v3_req ]
# Extensions to add to a certificate request
basicConstraints = CA:FALSE
keyUsage = nonRepudiation, digitalSignature, keyEncipherment

[ v3_ca ]
# Extensions for a typical CA
# PKIX recommendation.
subjectKeyIdentifier=hash
authorityKeyIdentifier=keyid:always,issuer
basicConstraints = critical,CA:true

[ crl_ext ]
# CRL extensions.
# Only issuerAltName and authorityKeyIdentifier make any sense in a CRL.
authorityKeyIdentifier=keyid:always
EOF

echo "<<<<<<<<<<<<<< Generating CA certificate... >>>>>>>>>>>>"
# Generate a self-signed CA certificate
openssl genrsa -out ca-key.pem 2048
openssl req -x509 -new -key ca-key.pem -out ca-cert.pem -days 365 -nodes -subj "/CN=My Root CA"

echo "<<<<<<<<<<<<<< Generating certificate... >>>>>>>>>>>>"
# Generate a certificate signing request (CSR) for a new certificate
openssl genrsa -out cert-key.pem 2048
openssl req -new -key cert-key.pem -out cert.csr -nodes -subj "/CN=example.com"

# Sign the certificate with the CA certificate to create the new certificate
openssl x509 -req -in cert.csr -CA ca-cert.pem -CAkey ca-key.pem -CAcreateserial -out cert.pem -days 365

echo "<<<<<<<<<<<<<< Generating revoked certificate... >>>>>>>>>>>>>>>>"
# Same way to create a new certificate which ready to be revoked
openssl genrsa -out ${cert2}-key.pem 2048
openssl req -new -key ${cert2}-key.pem -out ${cert2}.csr -nodes -subj "/CN=example.com"
openssl x509 -req -in ${cert2}.csr -CA ca-cert.pem -CAkey ca-key.pem -CAcreateserial -out ${cert2}.pem -days 365

echo "<<<<<<<<<<<<<< Generating CRL... >>>>>>>>>>>>>>>>"
# Generate a CRL (Certificate Revocation List) that revokes the new certificate
openssl ca --config ${configFile} -revoke ${cert2}.pem
openssl ca --config ${configFile} -gencrl -out crl.pem
openssl crl -in crl.pem -noout -text
# openssl ca -gencrl -out crl.pem -keyfile ca-key.pem -cert ca-cert.pem -crldays 30 -revoke ${cert2}.pem

echo "Finished."
