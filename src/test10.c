// //
// // Created by kitsc on 2024/8/9.
// //
//
// // #include <stdio.h>
// // #include <stdbool.h>
// // #include <stdlib.h>
// //
// // #define MAXSIZE 100
// // typedef int QElemType;
// //
// // typedef struct SqQueue {
// //     QElemType *data;
// //     int front;
// //     int rear;
// // } SqQueue;
// //
// // bool InitQueue(SqQueue *Q) {
// //     if (Q == NULL) {
// //         return false;
// //     }
// //     Q->data = (QElemType *) malloc(sizeof(QElemType) * MAXSIZE);
// //     if (Q->data == NULL) {
// //         return false;
// //     }
// //     Q->front = Q->rear = 0;
// //     return true;
// // }
// //
// // int LengthQueue(SqQueue Q) {
// //     return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
// // }
// //
// // bool EnQueue(SqQueue *Q, QElemType e) {
// //     if (Q == NULL || Q->data == NULL) {
// //         return false;
// //     }
// //     if ((Q->rear + 1) % MAXSIZE == Q->front) {
// //         return false;
// //     }
// //     Q->data[Q->rear] = e;
// //     Q->rear = (Q->rear + 1) % MAXSIZE;
// //     return true;
// // }
// //
// // bool DelQueue(SqQueue *Q) {
// //     if (Q == NULL || Q->data == NULL) {
// //         return false;
// //     }
// //     if (Q->front == Q->rear) {
// //         return false;
// //     }
// //     Q->front = (Q->front + 1) % MAXSIZE;
// //     return true;
// // }
// //
// // bool DesQueue(SqQueue *S) {
// //     if (S == NULL) {
// //         return false;
// //     }
// //     if (S->data != NULL) {
// //         free(S->data);
// //     }
// //     S->data = NULL;
// //     return true;
// // }
// //
// // void Print(SqQueue S) {
// //     while ((S.front) % MAXSIZE != S.rear) {
// //         printf("%d ", S.data[S.front]);
// //         S.front = (S.front + 1) % MAXSIZE;
// //     }
// //     printf("\n");
// // }
// //
// // int main() {
// //     SqQueue S;
// //     InitQueue(&S);
// //     EnQueue(&S, 1);
// //     EnQueue(&S, 2);
// //     EnQueue(&S, 3);
// //     EnQueue(&S, 4);
// //     DelQueue(&S);
// //     Print(S);
// //     DesQueue(&S);
// //     return 0;
// // }
//
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
//
// const int MAXSIZE = 100;
//
// typedef int SElemType;
//
// typedef struct SqQueue {
//     SElemType *base;
//     size_t front;
//     size_t rear;
// } SqQueue;
//
// bool InitSqQueue(SqQueue *S) {
//     if (S == NULL) {
//         return false;
//     }
//     S->base = (SElemType *) malloc(sizeof(SElemType) * MAXSIZE);
//     if (S->base == NULL) {
//         return false;
//     }
//     S->front = S->rear = 0;
//     return true;
// }
//
// bool DestroySqQueue(SqQueue *S) {
//     if (S == NULL) {
//         return false;
//     }
//     if (S->base != NULL) {
//         free(S->base);
//         S->base = NULL;
//     }
//     return true;
// }
//
// bool EnQueue(SqQueue *S, SElemType e) {
//     if (S == NULL || S->base == NULL) {
//         return false;
//     }
//     if ((S->rear + 1) % MAXSIZE == S->front) {
//         return false;
//     }
//     S->base[S->rear] = e;
//     S->rear = (S->rear + 1) % MAXSIZE;
//     return true;
// }
//
// bool DeQueue(SqQueue *S) {
//     if (S->front == S->rear) {
//         return false;
//     }
//     S->front = (S->front + 1) % MAXSIZE;
//     return true;
// }
//
// size_t LengthQueue(SqQueue S) {
//     return (S.rear - S.front + MAXSIZE) % MAXSIZE;
// }
//
// void Print(SqQueue S) {
//     while (S.front % MAXSIZE != S.rear) {
//         printf("%4d", S.base[S.front]);
//         S.front++;
//     }
//     printf("\n");
// }
//
// SElemType GetTop(SqQueue S) {
//     if (S.front != S.rear) {
//         return S.base[S.front];
//     }
// }
//
// int main() {
//     SqQueue S;
//     InitSqQueue(&S);
//     EnQueue(&S, 1);
//     EnQueue(&S, 2);
//     EnQueue(&S, 3);
//     EnQueue(&S, 4);
//     EnQueue(&S, 5);
//     Print(S);
//     DeQueue(&S);
//     Print(S);
//     size_t a = LengthQueue(S);
//     printf("%zd\n", a);
//     SElemType c = GetTop(S);
//     printf("%d\n", c);
//     DestroySqQueue(&S);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <time.h>
// const int MAXSIZE = 100;
//
// typedef int SElemTye;
//
// typedef struct SqQueue {
//     SElemTye *base;
//     size_t front;
//     size_t rear;
// } SqQueue;
//
// bool InitSqQueue(SqQueue *Q) {
//     if (Q == NULL) {
//         return false;
//     }
//     Q->base = (SElemTye *) malloc(sizeof(SElemTye) * MAXSIZE);
//     if (Q->base == NULL) {
//         return false;
//     }
//     Q->front = Q->rear = 0;
//     return true;
// }
//
// bool DesSqQueue(SqQueue *Q) {
//     if (Q == NULL)
//         return false;
//
//     if (Q->base != NULL) {
//         free(Q->base);
//         Q->base = NULL;
//         Q->front = Q->rear = 0;
//     }
//     return true;
// }
//
// bool EnQueue(SqQueue *Q, SElemTye e) {
//     if (Q == NULL || Q->base == NULL) {
//         return false;
//     }
//     if ((Q->rear + 1) + MAXSIZE == Q->front) {
//         return false;
//     }
//     Q->base[Q->rear] = e;
//     Q->rear = (Q->rear + 1) % MAXSIZE;
//     return true;
// }
//
// bool DesQueue(SqQueue *Q) {
//     if (Q == NULL || Q->base == NULL) {
//         return false;
//     }
//     if (Q->front == Q->rear) {
//         return false;
//     }
//     Q->front = (Q->front + 1) % MAXSIZE;
//     return true;
// }
//
// void Print(SqQueue S) {
//     if (S.front == S.rear) {
//         return;
//     }
//     int a = 0;
//     while (S.front % MAXSIZE != S.rear) {
//         printf("%4d", S.base[S.front]);
//         S.front = (S.front + 1) % MAXSIZE;
//         a++;
//         if (a % 5 == 0) {
//             printf("\n");
//         }
//     }
//     printf("\n");
// }
//
// int main() {
//     srand((unsigned int) time(NULL));
//     SqQueue Q;
//     InitSqQueue(&Q);
//     for (int i = 0; i < 10; i++) {
//         int a = 1 + rand() % 100;
//         EnQueue(&Q, a);
//     }
//     // EnQueue(&Q, 1);
//     Print(Q);
//     DesSqQueue(&Q);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <time.h>
// const int MAXSIZE = 10;
//
// typedef int SElemTye;
//
// typedef struct SqQueue {
//     SElemTye *base;
//     size_t front;
//     size_t rear;
// } SqQueue;
//
// bool InitSqQueue(SqQueue *Q) {
//     if (Q == NULL) {
//         return false;
//     }
//     Q->base = (SElemTye *) malloc(sizeof(SElemTye) * MAXSIZE);
//     if (Q->base == NULL) {
//         return false;
//     }
//     Q->front = Q->rear = 0;
//     return true;
// }
//
// bool DesSqQueue(SqQueue *Q) {
//     if (Q == NULL)
//         return false;
//
//     if (Q->base != NULL) {
//         free(Q->base);
//         Q->base = NULL;
//     }
//     Q->front = Q->rear = 0;
//     return true;
// }
//
// bool EnQueue(SqQueue *Q, SElemTye e) {
//     if (Q == NULL || Q->base == NULL) {
//         return false;
//     }
//     if ((Q->rear + 1) % MAXSIZE == Q->front) {
//         return false;
//     }
//     Q->base[Q->rear] = e;
//     Q->rear = (Q->rear + 1) % MAXSIZE;
//     return true;
// }
//
// bool DesQueue(SqQueue *Q) {
//     if (Q == NULL || Q->base == NULL) {
//         return false;
//     }
//     if (Q->front == Q->rear) {
//         return false;
//     }
//     Q->front = (Q->front + 1) % MAXSIZE;
//     return true;
// }
//
// void Print(SqQueue S) {
//     if (S.front == S.rear) {
//         return;
//     }
//     int a = 0;
//     while (S.front % MAXSIZE != S.rear) {
//         printf("%4d", S.base[S.front]);
//         S.front = (S.front + 1) % MAXSIZE;
//         a++;
//         if (a % 10 == 0) {
//             printf("\n");
//         }
//     }
//     printf("\n");
// }
//
// int main() {
//     srand((unsigned int) time(NULL));
//     SqQueue Q;
//     InitSqQueue(&Q);
//     for (int i = 0; i < 50; i++) {
//         if (i >= MAXSIZE - 1) {
//             break;
//         }
//         int a = 1 + rand() % 100;
//         EnQueue(&Q, a);
//     }
//     Print(Q);
//     DesSqQueue(&Q);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
const int MAXSIZE = 1000;

typedef int SElemTye;

typedef struct SqQueue
{
    SElemTye *base;
    size_t front;
    size_t rear;
} SqQueue;

bool InitSqQueue(SqQueue *Q)
{
    if (Q == NULL)
    {
        return false;
    }
    Q->base = (SElemTye *)malloc(sizeof(SElemTye) * MAXSIZE);
    if (Q->base == NULL)
    {
        return false;
    }
    Q->front = Q->rear = 0;
    return true;
}

bool DesSqQueue(SqQueue *Q)
{
    if (Q == NULL)
        return false;

    if (Q->base != NULL)
    {
        free(Q->base);
        Q->base = NULL;
    }
    Q->front = Q->rear = 0;
    return true;
}

bool EnQueue(SqQueue *Q, SElemTye e)
{
    if (Q == NULL || Q->base == NULL)
    {
        return false;
    }
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return false;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return true;
}

bool DesQueue(SqQueue *Q)
{
    if (Q == NULL || Q->base == NULL)
    {
        return false;
    }
    if (Q->front == Q->rear)
    {
        return false;
    }
    Q->front = (Q->front + 1) % MAXSIZE;
    return true;
}

void Print(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return;
    }
    int a = 0;
    while (Q.front % MAXSIZE != Q.rear)
    {
        printf("%4d", Q.base[Q.front]);
        Q.front = (Q.front + 1) % MAXSIZE;
        a++;
        if (a % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int LenQueue(SqQueue Q)
{
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

SElemTye GetTop(SqQueue Q)
{
    if (Q.front != Q.rear)
    {
        return Q.base[Q.front];
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    SqQueue Q;
    InitSqQueue(&Q);
    for (int i = 0; i < 100; i++)
    {
        if (i >= MAXSIZE + 1)
        {
            break;
        }
        int a = 1 + rand() % 100;
        EnQueue(&Q, a);
    }
    Print(Q);
    DesQueue(&Q);
    Print(Q);

    int c = LenQueue(Q);
    printf("%d\n", c);


    int d = GetTop(Q);
    printf("%d\n", d);

    DesSqQueue(&Q);
    return 0;
}