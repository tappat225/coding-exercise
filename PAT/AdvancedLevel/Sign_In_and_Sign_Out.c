/**
 * Title: 1006_Sign_In_and_Sign_Out
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
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928
 * 
 * State: Passed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TIME_ROUND 60

typedef struct sign_info
{
    char id[16];
    char sign_in_t[9];
    char sign_out_t[9];
}s_info_t;

typedef struct time_format
{
    int h;
    int min;
    int sec;
}my_time_t;

int time_compare(char *time1, char *time2)
{
    my_time_t t1;
    my_time_t t2;
    int t1_tsec;
    int t2_tsec;
    sscanf(time1,"%d:%d:%d", &t1.h, &t1.min, &t1.sec);
    sscanf(time2,"%d:%d:%d", &t2.h, &t2.min, &t2.sec);
    t1_tsec = t1.h * TIME_ROUND * TIME_ROUND + t1.min * TIME_ROUND + t1.sec;
    t2_tsec = t2.h * TIME_ROUND * TIME_ROUND + t2.min * TIME_ROUND + t2.sec;
    if (t1_tsec == t2_tsec) {
        return 0;
    } else {
        return (t1_tsec > t2_tsec) ? 1 : -1;
    }
}

int main()
{
    int i;
    int num;
    char t_min[9] = "00:00:00";
    char t_max[9] = "23:59:59";
    char *t_early;
    char *t_later;
    s_info_t *usr;
    char *locker;   /* point to id */
    char *unlocker;     /* point to id */

    num = 0;
    t_early = t_max;
    t_later = t_min;
    printf("Input record num: ");
    scanf("%d", &num);
    usr = (s_info_t *)malloc(num * sizeof(s_info_t));
    memset(usr, 0, num * sizeof(s_info_t));
    for (i = 0; i < num; i++) {
        printf("Input record [%d]: \n", i+1);
        scanf("%s", usr[i].id);
        scanf("%s", usr[i].sign_in_t);
        scanf("%s", usr[i].sign_out_t);
        if (time_compare(usr[i].sign_in_t, usr[i].sign_out_t) >= 0) {
            printf("error info.\n");
            goto done;
        }

        if (time_compare(usr[i].sign_in_t, t_early) < 0) {
            t_early = usr[i].sign_in_t;
            unlocker = usr[i].id;
        }

        if (time_compare(usr[i].sign_out_t, t_later) > 0) {
            t_later = usr[i].sign_out_t;
            locker = usr[i].id;
        }
    }

    printf("Unlocker is %s, Locker is %s. \n", unlocker, locker);

done:
    free(usr);
    return 0;
}
