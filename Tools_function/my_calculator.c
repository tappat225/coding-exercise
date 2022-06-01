#include <stdio.h>
#include <string.h>
#define STR_LEN_MAX 128

enum mode{
    DEF = 0,
    BIN_TO_DEC,
    HEX_TO_DEC
};

static int bin_to_dec_func()
{
    char bin[STR_LEN_MAX];
    int s_len;
    int i;
    int sum;

    sum = 0;
    printf("input binary num: ");
    scanf("%s", bin);
    s_len = strlen(bin);
    if (s_len == 0) {
        printf("empty.\n");
        return -1;
    }

    for (i = 0; i < s_len - 1; i++) {
        sum += (bin[i] - '0');
        sum *= 2;
    }

    sum += (bin[i] - '0');
    printf("decimal: %d\n", sum);
    return 0;
}

static int hex_to_decimal_func()
{
    int hex;

    hex = -1;
    printf("input hex num: ");
    scanf("%x", &hex);
    printf("hex = %d\n", hex);
    return 0;
}

int main()
{
    int type;

    type = 0;
    printf("Input mode: \n");
    printf("mode[1]: binary to decimal.\n");
    printf("mode[2]: hex to decimal.\n");
    printf("choose mode: ");
    scanf("%d", &type);
    switch (type) {
    case BIN_TO_DEC:
        if (bin_to_dec_func() < 0) {
            printf("error!\n");
        }

        break;
    case HEX_TO_DEC:
        hex_to_decimal_func();
        break;
    default:
        break;
    }

    return 0;
}