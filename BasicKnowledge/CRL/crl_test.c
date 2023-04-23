/**
 * Copyright(C) TappaT 2023. All rights reserved.
 * 
 * @author  TappaT
 * @date    4/22/2023
 * 
 */

#include <stdio.h>
#include <openssl/x509.h>
#include <openssl/x509_vfy.h>
#include <openssl/pem.h>

#define CA_FILE             "certsDir/ca-cert.pem"
#define CRL_FILE            "certsDir/crl.pem"
#define CERT_FILE           "certsDir/cert.pem"
#define REVOKED_CERT_FILE   "certsDir/cert-revoked.pem"

static int verify_cert(X509 *ca, X509 *cert, X509_CRL *crl, const char* filePath)
{
    X509_STORE *store;
    X509_STORE_CTX *ctx;
    int ret;

    /* Initialize the X509 store */
    store = X509_STORE_new();
    if (!store) {
        printf("Error: Unable to create X509 store\n");
        return -1;
    }

    /* Add the CA certificate to the X509 store */
    ret = X509_STORE_add_cert(store, ca);
    if (!ret) {
        printf("Error: Unable to add CA certificate to X509 store\n");
        return -1;
    }

    /* Add the CRL to the X509 store */
    ret = X509_STORE_add_crl(store, crl);
    if (!ret) {
        printf("Error: Unable to add CRL to X509 store\n");
        return -1;
    }

    /* Initialize the X509 store context */
    ctx = X509_STORE_CTX_new();
    if (!ctx) {
        printf("Error: Unable to create X509 store context\n");
        return -1;
    }

    /* Set the certificate to be verified in the X509 store context */
    ret = X509_STORE_CTX_init(ctx, store, cert, NULL);
    if (!ret) {
        printf("Error: Unable to set certificate to be verified in X509 store context\n");
        return -1;
    }

    /* Enable CRL checking in the X509 store context */
    X509_STORE_CTX_set_flags(ctx, X509_V_FLAG_CRL_CHECK);

    /* Verify the certificate */
    ret = X509_verify_cert(ctx);

    if (ret == 1) {
        printf("Certificate %s verified\n", filePath);
    } else if (ret == 0) {
        printf("Certificate %s revoked\n", filePath);
    } else {
        printf("Certificate %s verification failed\n", filePath);
    }

    /* Cleanup */
    X509_STORE_CTX_free(ctx);
    X509_STORE_free(store);

    return 0;
}

int main()
{
    X509 *cert, *revoked_cert, *ca;
    X509_CRL *crl;
    FILE *ca_file;
    FILE *crl_file;
    FILE *cert_file;
    FILE *revoked_cert_file;

    /* Load the CA certificate into memory */
    ca_file = fopen(CA_FILE, "r");
    if (!ca_file) {
        printf("Error: Unable to open CA file\n");
        return -1;
    }

    ca = PEM_read_X509(ca_file, NULL, NULL, NULL);
    fclose(ca_file);

    /* Load the CRL into memory */
    crl_file = fopen(CRL_FILE, "r");
    if (!crl_file) {
        printf("Error: Unable to open CRL file\n");
        return -1;
    }

    crl = PEM_read_X509_CRL(crl_file, NULL, NULL, NULL);
    fclose(crl_file);

    /* Load the certificate to be verified into memory */
    cert_file = fopen(CERT_FILE, "r");
    if (!cert_file) {
        printf("Error: Unable to open certificate file\n");
        return -1;
    }

    cert = PEM_read_X509(cert_file, NULL, NULL, NULL);
    fclose(cert_file);

    if (verify_cert(ca, cert, crl, CERT_FILE) != 0) {
        printf("Failed to verify certificate.\n");
        return -1;
    }

    /* Load the revoked certificate into memory */
    revoked_cert_file = fopen(REVOKED_CERT_FILE, "r");
    if (!revoked_cert_file) {
        printf("Error: Unable to open certificate file\n");
        return -1;
    }

    revoked_cert = PEM_read_X509(revoked_cert_file, NULL, NULL, NULL);
    fclose(revoked_cert_file);

    if (verify_cert(ca, revoked_cert, crl, REVOKED_CERT_FILE) != 0) {
        printf("Failed to verify certificate.\n");
        return -1;
    }

    /* Cleanup */
    X509_CRL_free(crl);
    X509_free(ca);
    X509_free(cert);
    X509_free(revoked_cert);

    return 0;
}
