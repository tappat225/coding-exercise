#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char u8;
typedef unsigned int u32;

/* 字符串数字转整型，输出结果不正确，待改进 */
int str2int(char *str)
{   
    int k;
    int i = 0;
    int retval = 0;
    int len = strlen(str);
    if (len < 1) {
        return 0;
    }

    for (k = len - 1; k >= 0; k--) {
        retval += (str[k] - '0') * pow(10, i);
        i++;
    }

    return retval;
}

void U32ToU8Array(u8 *buf, u32 u32Value)
{
    buf[0] = ((u32Value >> 24) & 0xFF);
    buf[1] = ((u32Value >> 16) & 0xFF);
    buf[2] = ((u32Value >> 8) & 0xFF);
    buf[3] = (u32Value & 0xFF);
}

void char2unchar(char *str, unsigned char *unchar)
{
    int i;
    int j;
    int counter;
    char c[2];
    unsigned int bytes[2];

    i = strlen(str);
    counter = 0;
    for (j = 0; j < i; j += 2) {
        if (0 == j % 2) {
            c[0] = str[j];
            c[1] = str[j + 1];
            sscanf(c, "%02x", &bytes[0]);
            unchar[counter] = bytes[0];
            counter++;
        }
    }
}

/* Convert net mask to integer number */
static int net_mask_to_num(char *ip_netmask_s)
{
    unsigned char c1, c2, c3, c4;
    int ip_num;
    int cnt;

    cnt = 0;
    sscanf(ip_netmask_s, "%hhu.%hhu.%hhu.%hhu", &c1, &c2, &c3, &c4);
    ip_num = c1 << 24 | c2 << 16 | c3 << 8 | c4;
    for (int i = 0; i < 32; i++) {
        if ((ip_num << i) & 0x80000000) {
            cnt++;
        } else {
            break;
        }
    }

    return cnt;
}
