#include "test_header.h"

#define MAX_SIZE 10

typedef struct my_stack
{
    int top;
    char value[MAX_SIZE];
}mstack_t;

void my_stack_init(mstack_t *s)
{
    s->top = 0;
    memset(s->value, 0, MAX_SIZE);
}

int s_push(mstack_t *s, char c)
{
    int i;

    if (s->top >= MAX_SIZE) {
        printf("stack has reached the top!\n");
        return -1;
    }

    i = s->top;
    s->value[i] = c;
    s->top++;
    return 0;
}

char s_pop(mstack_t *s)
{
    int i;

    i = s->top;
    if (i < 0) {
        return '\0';
    }

    s->top--;
    return s->value[i];
}

int main()
{
    const int usr_max_size = 20;
    int str_len;
    char usr_input[usr_max_size];
    mstack_t my_s;
    int i;

    memset(usr_input, 0, usr_max_size);
    printf("Input a string: ");
    scanf("%s", usr_input);
    my_stack_init(&my_s);
    str_len = strlen(usr_input);
    for (i = 0; i < str_len; i++) {
        if (s_push(&my_s, usr_input[i]) < 0) {
            break;
        }
    }

    while (my_s.top >= 0) {
        printf("%c", s_pop(&my_s));
    }

    printf("\n");
    printf("finish.\n");
    return 0;
}
