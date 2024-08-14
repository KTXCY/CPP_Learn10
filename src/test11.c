// // //
// // // Created by kitsc on 2024/8/10.
// // //
// //
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <stdbool.h>
// //
// // typedef int QElemType;
// //
// // typedef struct QNode {
// //     QElemType data;
// //     struct QNode *next;
// // } QNode, *QuenePtr;
// //
// // typedef struct {
// //     QuenePtr front;
// //     QuenePtr rear;
// // } LinkQueue;
// //
// // bool IniQueue(LinkQueue *Q) {
// //     Q->front = Q->rear = (QuenePtr) malloc(sizeof(QNode));
// //     if (Q->front == NULL) {
// //         return false;
// //     }
// //     Q->front->next = NULL;
// //     return true;
// // }
// //
// // bool DestroyQueue(LinkQueue *Q) {
// //     while (Q->front != NULL) {
// //         QNode *p = Q->front;
// //         Q->front = Q->front->next;
// //         free(p);
// //     }
// //     return true;
// // }
// //
// // bool EnQueue(LinkQueue *Q, QElemType e) {
// //     QNode *p = (QNode *) malloc(sizeof(QNode));
// //     if (p == NULL) {
// //         return false;
// //     }
// //     p->data = e;
// //     p->next = NULL;
// //     Q->rear->next = p;
// //     Q->rear = p;
// //     return true;
// // }
// //
// // bool DeQueue(LinkQueue *Q) {
// //     if (Q->front == Q->rear) {
// //         return false;
// //     }
// //     QNode *p = Q->front->next;
// //     Q->front->next = p->next;
// //     if (Q->rear == p) {
// //         Q->rear = Q->front;
// //     }
// //     free(p);
// //     return true;
// // }
// //
// // bool GetHead(LinkQueue Q, QElemType *e) {
// //     if (Q.front == Q.rear) {
// //         return false;
// //     }
// //     (*e) = Q.front->next->data;
// //     return true;
// // }
// //
// // bool Print(LinkQueue Q) {
// //     if (Q.front == Q.rear) {
// //         return false;
// //     }
// //     QNode *p = Q.front->next;
// //     while (p != NULL) {
// //         printf("%3d", p->data);
// //         p = p->next;
// //     }
// //     printf("\n");
// //     return true;
// // }
// //
// // int main() {
// //     LinkQueue Q;
// //     IniQueue(&Q);
// //     EnQueue(&Q, 1);
// //     EnQueue(&Q, 2);
// //     EnQueue(&Q, 3);
// //     EnQueue(&Q, 4);
// //     EnQueue(&Q, 5);
// //     EnQueue(&Q, 6);
// //     EnQueue(&Q, 7);
// //     Print(Q);
// //     DeQueue(&Q);
// //     Print(Q);
// //     int a;
// //     GetHead(Q, &a);
// //     printf("%d\n", a);
// //     DestroyQueue(&Q);
// //     return 0;
// // }
//
//
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <time.h>
//
// typedef int QElemType;
//
// typedef struct QNode
// {
//     QElemType date;
//     struct QNode *next;
// } QNode, *QueuePtr;
//
// typedef struct
// {
//     QueuePtr front;
//     QueuePtr rear;
// } LinkQueue;
//
// bool InitQueue(LinkQueue *Q)
// {
//     Q->front = Q->rear = (QNode *)calloc(sizeof(QNode), 1);
//     if (Q->front == NULL)
//     {
//         return false;
//     }
//     Q->front->next = NULL;
//     return true;
// }
//
// bool DestroyQueue(LinkQueue *Q)
// {
//     while (Q->front != NULL)
//     {
//         QNode *p = Q->front;
//         Q->front = Q->front->next;
//         free(p);
//     }
//     Q->front = Q->rear = NULL;
//     return true;
// }
//
// bool EnQueue(LinkQueue *Q, QElemType e)
// {
//     if (Q->front == NULL)
//     {
//         return false;
//     }
//     QNode *p = (QNode *)malloc(sizeof(QNode));
//     if (p == NULL)
//     {
//         return false;
//     }
//     p->date = e;
//     p->next = NULL;
//     Q->rear->next = p;
//     Q->rear = p;
//     return true;
// }
//
// bool DeQueue(LinkQueue *Q)
// {
//     if (Q->front == NULL)
//     {
//         return false;
//     }
//     if (Q->front == Q->rear)
//     {
//         return false;
//     }
//     QNode *p = Q->front->next;
//     Q->front->next = p->next;
//     if (Q->rear == p)
//     {
//         Q->rear = Q->front;
//     }
//     free(p);
//     p = NULL;
//     return true;
// }
//
// void Print(LinkQueue Q)
// {
//     if (Q.front == Q.rear)
//     {
//         return;
//     }
//     int a = 0;
//     QNode *p = Q.front->next;
//     while (p != NULL)
//     {
//         printf("%3d", p->date);
//         p = p->next;
//         a++;
//         if (a % 10 == 0)
//         {
//             printf("\n");
//         }
//     }
//     printf("\n");
// }
//
//
// int LengthQueue(LinkQueue Q)
// {
//     if (Q.front == Q.rear)
//     {
//         return 0;
//     }
//     else
//     {
//         int length = 0;
//         QNode *p = Q.front->next;
//         while (p != NULL)
//         {
//             length++;
//             p = p->next;
//         }
//         return length;
//     }
// }
// int main()
// {
//     srand((unsigned int)time(NULL));
//     LinkQueue Q;
//     InitQueue(&Q);
//     for (int i = 0; i < 100; i++)
//     {
//         int a = 1 + rand() % 100;
//         EnQueue(&Q, a);
//     }
//     Print(Q);
//
//     DeQueue(&Q);
//     Print(Q);
//
//     DestroyQueue(&Q);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <time.h>
//
// typedef int QElemType;
//
// typedef struct QNode
// {
//     QElemType date;
//     struct QNode *next;
// } QNode, *QueuePtr;
//
// typedef struct
// {
//     QueuePtr front;
//     QueuePtr rear;
// } LinkQueue;
//
// bool InitQueue(LinkQueue *Q)
// {
//     Q->front = Q->rear = (QNode *)calloc(sizeof(QNode), 1);
//     if (Q->front == NULL)
//     {
//         return false;
//     }
//     Q->front->next = NULL;
//     return true;
// }
//
// bool DestroyQueue(LinkQueue *Q)
// {
//     while (Q->front != NULL)
//     {
//         QNode *p = Q->front;
//         Q->front = Q->front->next;
//         free(p);
//     }
//     Q->front = Q->rear = NULL;
//     return true;
// }
//
// bool EnQueue(LinkQueue *Q, QElemType e)
// {
//     if (Q->front == NULL)
//     {
//         return false;
//     }
//     QNode *p = (QNode *)malloc(sizeof(QNode));
//     if (p == NULL)
//     {
//         return false;
//     }
//     p->date = e;
//     p->next = NULL;
//     Q->rear->next = p;
//     Q->rear = p;
//     return true;
// }
//
// bool DeQueue(LinkQueue *Q)
// {
//     if (Q->front == NULL)
//     {
//         return false;
//     }
//     if (Q->front == Q->rear)
//     {
//         return false;
//     }
//     QNode *p = Q->front->next;
//     Q->front->next = p->next;
//     if (Q->rear == p)
//     {
//         Q->rear = Q->front;
//     }
//     free(p);
//     p = NULL;
//     return true;
// }
//
// void Print(LinkQueue Q)
// {
//     if (Q.front == Q.rear)
//     {
//         return;
//     }
//     int a = 0;
//     QNode *p = Q.front->next;
//     while (p != NULL)
//     {
//         printf("%6d", p->date);
//         p = p->next;
//         a++;
//         if (a % 100 == 0)
//         {
//             printf("\n");
//         }
//     }
//     printf("\n");
// }
//
// int LenghtQueue(LinkQueue Q)
// {
//     if (Q.front == Q.rear)
//     {
//         return 0;
//     }
//     else
//     {
//         int length = 0;
//         QNode *p = Q.front->next;
//         while (p != NULL)
//         {
//             length++;
//             p = p->next;
//         }
//         return length;
//     }
// }
//
// bool GetHead(LinkQueue Q, QElemType *e)
// {
//     if (Q.front == Q.rear)
//     {
//         return false;
//     }
//     (*e) = Q.front->next->date;
//     return true;
// }
//
// int main()
// {
//     srand((unsigned int)time(NULL));
//     LinkQueue Q;
//     InitQueue(&Q);
//     for (int i = 0; i < 200; i++)
//     {
//         int a = 100 + rand() % 10000;
//         EnQueue(&Q, a);
//     }
//     Print(Q);
//
//     DeQueue(&Q);
//     Print(Q);
//     int c = LenghtQueue(Q);
//     printf("%d\n", c);
//
//     int b = 0;
//     GetHead(Q, &b);
//     printf("%d\n",b);
//     DestroyQueue(&Q);
//     // getchar();
//     return 0;
// }
