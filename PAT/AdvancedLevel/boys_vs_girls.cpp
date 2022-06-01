/**
 * Title: N_A1011 Boys vs Girls
 * 
 * Content:
 * 
 * This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.
 ******************************
 * Input description:
 *
 * Each input file contains one test case.
 * Each case contains a positive integer N, followed by N lines of student information.
 * Each line contains a student's name, gender, ID and grade, separated by a space,
 * where name and ID are strings of no more than 10 characters with no space,
 * gender is either F (female) or M (male), and grade is an integer between 0 and 100.
 * It is guaranteed that all the grades are distinct.
 ******************************
 * Output description:
 * 
 * For each test case, output in 3 lines.
 * The first line gives the name and ID of the female student with the highest grade,
 * and the second line gives that of the male student with the lowest grade.
 * The third line gives the difference gradeF-gradeM.
 * If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.
 * 
 * Input example:
 * 3
 * Joe M Math990112 89
 * Mike M CS991301 100
 * Mary F EE990830 95
 * 
 * Output example:
 * Mary EE990830
 * Joe Math990112
 * 6
 * 
 * Link: https://www.nowcoder.com/pat/1/problem/4023
 * 
 * State: Passed.
 * 
*/

#include<iostream>
#include<cstring>
using namespace std;

struct stu{
    string name;
    char gender;
    string ID;
    int grade;
};

int main(){
    int N;
     cin>>N;
    stu s[N];
   
    for (int i = 0; i < N; i++){
        cin>>s[i].name>>s[i].gender>>s[i].ID>>s[i].grade;
    }
    int F_high,M_low;
    F_high=0;M_low=101;
    int F_high_ID,M_low_ID;
    F_high_ID=M_low_ID=0;
    int F_flag,M_flag;
    F_flag=M_flag=-1;
    for (int j = 0; j < N; j++){
        if(s[j].gender=='M'&&s[j].grade<M_low){
            M_low=s[j].grade;
            M_low_ID=j;
            M_flag=1;
        }
        if (s[j].gender=='F'&&s[j].grade>F_high){
            F_high=s[j].grade;
            F_high_ID=j;
            F_flag=1;
        }
    }
    if(F_flag==-1){
        cout<<"Absent"<<endl;
    }
    else{
        cout<<s[F_high_ID].name<<' '<<s[F_high_ID].ID<<endl;
    }
    if(M_flag==-1){
        cout<<"Absent"<<endl;
    }
    else{
        cout<<s[M_low_ID].name<<' '<<s[M_low_ID].ID<<endl;
    }
    if(M_flag==1&&F_flag==1){
        cout<<s[F_high_ID].grade-s[M_low_ID].grade<<endl;
    }
    else{
        cout<<"NA"<<endl;
    }
    return 0;
}