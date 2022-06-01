#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int DAY,flag;
    string DAYS;
    char HHs;
    int HH;
    flag=0;

    /*find DAY,hh*/
    for(int i=0;i<s1.size();i++){
        //for(int j=0;j<s2.size();j++){
            if(s1[i]>='A'&&s1[i]<='Z'&&s1[i]==s2[i]&&flag==0){
               // if(s1[i]==s2[j]&&flag==0) {DAY=s1[i]-'A'+1;flag=1;break;}
               DAY=s1[i]-'A'+1;
               flag=1;
               continue;
            }
            if((isdigit(s1[i])||isupper(s1[i]))&&(s1[i]==s2[i]&&flag==1)){
                 HHs=s1[i];
                 flag=2;  
                 break;
            }
        //}
        //if(flag==2) break;
    }

    /*deal with DAY*/
    switch (DAY){
    case 1:DAYS="MON";break;
    case 2:DAYS="TUE";break;
    case 3:DAYS="WED";break;
    case 4:DAYS="THU";break;
    case 5:DAYS="FRI";break;
    case 6:DAYS="SAT";break;
    case 7:DAYS="SUN";break;
    default:
        break;
    }

    /*deal with hh*/
    if(HHs<='A'){
        HH=HHs-'0';
    }
    else{
        HH=HHs-'A'+10;
    }
    //cout<<"HHS: "<<HHs<<endl;

    /*find and deal with mm*/
    int flag2=0;
    int mm;
    int str_size=s3.size()>s4.size()?s4.size():s3.size();
    for(int m=0;m<str_size;m++){
        /*for(int n=0;n<s4.size();n++){
            if(s3[m]>='a'&&s3[m]<='z'&&s4[n]>='a'&&s4[n]<='z'){
                if(s3[m]==s4[n]) {mm=s3[m]-'a'+1;flag2=1;break;}
            }
        }
        if(flag2==1) break;
        */
       if(s3[m]==s4[m]&&islower(s3[m])) {mm=m;break;}
    }
    
    cout<<DAYS<<(HH>10?" ":" 0")<<HH;
    cout<<(mm>10?":":":0")<<mm;
    cout<<endl;
    return 0;
}