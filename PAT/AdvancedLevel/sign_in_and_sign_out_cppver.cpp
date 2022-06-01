/**
 * Title: N_A1018 sign_in_and_sign_out cpp version
 * 
 * At the beginning of every day, the first person who signs in the computer room will unlock the door, 
 * and the last one who signs out will lock the door.
 * Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.
 * 
 * Input Specification:
 * Each input file contains one test case. Each case contains the records for one day.
 * The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
 * 
 * ID_number Sign_in_time Sign_out_time
 * where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.
 * 
 * Output Specification:
 * For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.
 * 
 * Note: It is guaranteed that the records are consistent.
 * That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.
 * 
 * Sample Input:
 * 3
 * CS301111 15:30:28 17:00:10
 * SC3021234 08:00:00 11:25:25
 * CS301133 21:45:00 21:58:40
 * 
 * Sample Output:
 * SC3021234 CS301133
 * 
 * Link: https://www.nowcoder.com/pat/1/problem/3998
 * 
 * State: Passed.
*/

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    string ID,time_in,time_out;
    string time_min="23:59:59",time_max="00:00:00";
    string ID_min,ID_max;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>ID>>time_in>>time_out;
        if(time_in<time_min){
            time_min=time_in;
            ID_min=ID;
        }
        if(time_out>time_max){
            time_max=time_out;
            ID_max=ID;
        }
    }
    cout<<ID_min<<' '<<ID_max<<endl;
    return 0;
}