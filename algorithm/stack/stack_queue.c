/**
 * 两个栈模拟一个队列
 * 
 * 思路：两个栈分别为入队栈与出队栈。
 */

#include "../../Tools_function/head_c.h"

#define MAXN 100

typedef struct stack_t
{
    int stack_container[MAXN];
    int top;
} stack;

typedef struct s_queue_t
{
    stack *st_in;
    stack *st_out;
} s_queue;

/**
 * init_queue - 初始化队列
 * 
 */
void init_queue(s_queue *q)
{
    q->st_in = (stack *)malloc(sizeof(stack));
    if (q->st_in == NULL) {
        printf("malloc st_in failed.\n");
        exit(0);
    }

    q->st_out = (stack *)malloc(sizeof(stack));
    if (q->st_out == NULL) {
        printf("malloc st_out failed.\n");
        exit(0);
    }

    memset(q->st_in->stack_container, 0, MAXN - 1);
    memset(q->st_out->stack_container, 0, MAXN - 1);
    q->st_in->top = -1;
    q->st_out->top = -1;
}

/**
 * destory_queue - 销毁队列
 * 
 */
void destory_queue(s_queue *q)
{
    if (q->st_in != NULL) {
        free(q->st_in);
        q->st_in = NULL;
    }

    if (q->st_out != NULL) {
        free(q->st_out);
        q->st_out = NULL;
    }
}

bool is_stack_empty(stack *st)
{
    return (st->top == -1);
}

bool stack_push(stack *st, int num)
{
    if ((st->top + 1) > MAXN) {
        return false;
    }

    st->stack_container[++st->top] = num;
    return true;
}

int stack_pop(stack *st)
{
    int top_elemnt;

    if (is_stack_empty(st) == true) {
        return -1;
    }

    top_elemnt = st->stack_container[st->top];
    st->stack_container[st->top--] = 0;

    return top_elemnt;
}

/**
 * queue_in - 元素入队列
 * 要求先保障出队列栈为空
 */
void queue_in(s_queue *q, int num)
{
    while (is_stack_empty(q->st_out) != true) {
        stack_push(q->st_in, stack_pop(q->st_out));
    }

    stack_push(q->st_in, num);
}

int queue_out(s_queue *q)
{
    while (is_stack_empty(q->st_in) != true) {
        stack_push(q->st_out, stack_pop(q->st_in));
    }

    return stack_pop(q->st_out);
}

int main()
{
    s_queue q;
    char c;
    int n, i;

    init_queue(&q);
    printf("Input num of element: ");
    scanf("%d", &n);
    getchar();  /* 害，我说怎么一直有个-38，忘记掉这种多行输入要把回车给吞一下 */
    i = n;
    printf("Input num: ");
    while (i > 0) {
        c = getchar();
        if (c == ' ') {
            continue;
        }

        if (c == '\n') {
            break;
        }

        queue_in(&q, c - '0');
        i--;
    }

    i = n;
    printf("Queue out: ");
    while ((i--) > 0) {
        printf("%d ", queue_out(&q));
    }

    printf("\n");
    destory_queue(&q);

    return 0;
}

/*
 * |Test case|
 * [Input]
 * Input num of element: 4
 * Input num: 1 2 3 4
 * [Output]
 * Queue out: 1 2 3 4 
 */
