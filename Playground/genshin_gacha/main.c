/**
 * 5 star 0.6%
 * 4 star 5.1%
 * 
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int u32;

enum character_type {
    XINGQIU = 1,
    CHONGYUN,
    XIANGLIN,
    NINGGUANG
};

void welcome_word()
{
    printf("Wanna get a single gacha?\n");
}

void gacha_result(int rm)
{
    switch (rm) {
    case XINGQIU:
        printf("你获得了行秋\n");
        break;
    case CHONGYUN:
        printf("你获得了重云\n");
        break;
    case XIANGLIN:
        printf("你获得了香菱\n");
        break;
    case NINGGUANG:
        printf("你获得了凝光\n");
        break;
    default:
        printf("很遗憾，什么都没抽到...\n");
        break;
    }
}

int main()
{
    u32 big_random_num;
    u32 result_num;

    srand(time(NULL));
    big_random_num = rand();
    result_num = big_random_num % 10;
    gacha_result(result_num);
    // printf("result_num = %d\n", result_num);
    return 0;
}
