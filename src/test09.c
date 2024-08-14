//
// Created by kitsc on 2024/8/4.
//

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
//
// typedef int SElemType;
//
// typedef struct StackNode {
//     SElemType data;
//     struct StackNode *next;
// } StackNode, *LinkStack;
//
// bool InitStack(LinkStack *S) {
//     (*S) = NULL;
//     return true;
// }
//
// // bool DestorStack(LinkStack *S) {
// //     if ((*S) != NULL) {
// //         free(*S);
// //     }
// //     return true;
// // }
//
// bool StackEmpty(LinkStack S) {
//     if (S == NULL) {
//         return true;
//     } else {
//         return false;
//     }
// }
//
// bool Push(LinkStack *S, SElemType e) {
//     StackNode *p = (StackNode *) malloc(sizeof(StackNode));
//     if (p == NULL) {
//         return false;
//     }
//     p->data = e;
//     p->next = *S;
//     (*S) = p;
//     return true;
// }
//
// bool Pop(LinkStack *S) {
//     if (S == NULL || *S == NULL) {
//         return false;
//     }
//     StackNode *p = *S;
//     *S = (*S)->next;
//     free(p);
//     return true;
// }
//
// bool DestoryStack(LinkStack *S) {
//     if (S == NULL) {
//         return false;
//     }
//     while ((*S) != NULL) {
//         StackNode *p = (*S);
//         (*S) = (*S)->next;
//         free(p);
//         p = NULL;
//     }
//     (*S) == NULL;
//     return true;
// }
//
// void PrintStack(LinkStack S) {
//     while (S != NULL) {
//         printf("%d ", S->data);
//         S = S->next;
//     }
//     printf("\n");
// }
//
// SElemType GetTop(LinkStack S) {
//     if (S != NULL) {
//         return S->data;
//     }
// }
//
//
// int main() {
//     LinkStack S;
//     InitStack(&S);
//     Push(&S, 1);
//     Push(&S, 2);
//     Push(&S, 3);
//     Push(&S, 4);
//     Push(&S, 5);
//     Push(&S, 6);
//     Push(&S, 7);
//     Push(&S, 8);
//     PrintStack(S);
//     Pop(&S);
//     PrintStack(S);
//     int a = GetTop(S);
//     printf("%d\n", a);
//     DestoryStack(&S);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
//
// typedef int SElemType;
//
// typedef struct StackNode {
//     SElemType data;
//     struct StackNode *next;
// } StackNode, *LinkStack;
//
// bool InitStack(LinkStack *S) {
//     (*S) = NULL;
//     return true;
// }
//
// bool DestroyStack(LinkStack *S) {
//     if (S == NULL) {
//         return false;
//     }
//     while ((*S) != NULL) {
//         StackNode *p = (*S);
//         (*S) = (*S)->next;
//         free(p);
//         p = NULL;
//     }
//     (*S) = NULL;
//     return true;
// }
//
// bool Pust(LinkStack *S, SElemType e) {
//     if (S == NULL) {
//         return false;
//     }
//
//     StackNode *p = (StackNode *) malloc(sizeof(StackNode));
//     if (p == NULL) {
//         return false;
//     }
//     p->data = e;
//     p->next = (*S);
//     (*S) = p;
//     return true;
// }
//
// void Print(LinkStack S) {
//     while (S != NULL) {
//         printf("%d ", S->data);
//         S = S->next;
//     }
//     printf("\n");
// }
//
// int main() {
//     StackNode *S;
//     InitStack(&S);
//     Pust(&S, 1);
//     Print(S);
//     DestroyStack(&S);
//     return 0;
// }
