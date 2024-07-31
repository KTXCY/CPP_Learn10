//
// Created by kitsc on 2024/7/27.
//

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
//
// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0
// #define INFEASIBLE -1
// #define OVERFLOW -2
// #define MAXSIZE 100
// typedef int Status;
// typedef int ElemType;
//
// typedef struct SqList {
//     ElemType *Elem;
//     int length;
// } SqList;
//
// Status InitList(SqList *L) {
//     ElemType *p = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
//     if (p == NULL) {
//         return FALSE;
//     }
//     L->Elem = p;
//     L->length = 0;
//     return TRUE;
// }
//
// Status DestroyList(SqList *L) {
//     if (L == NULL) {
//         return FALSE;
//     }
//     if (L->Elem) {
//         free(L->Elem);
//     }
//     L->length = 0;
//     return TRUE;
// }
//
// Status InsertList(SqList *L, const int i, const ElemType val) {
//     if (L == NULL || L->Elem == NULL) {
//         return FALSE;
//     }
//     if (i < 1 || i > L->length + 1) {
//         return FALSE;
//     }
//     if (L->length == MAXSIZE) {
//         return FALSE;
//     }
//     int j = 0;
//     for (j = L->length - 1; j >= i - 1; j--) {
//         L->Elem[j + 1] = L->Elem[j];
//     }
//     L->Elem[i - 1] = val;
//     L->length++;
//     return OK;
// }
//
// Status DeleteList(SqList *L, const int i) {
//     if (L == NULL || L->Elem == NULL) {
//         return FALSE;
//     }
//     if (i < 1 || i > L->length) {
//         return FALSE;
//     }
//     int j = 0;
//     for (j = i - 1; j <= L->length - 1; j++) {
//         L->Elem[j] = L->Elem[j + 1];
//     }
//     L->length--;
//     return TRUE;
// }
//
// void ClearList(SqList *L) {
//     L->length = 0;
// }
//
// int GetLength(const SqList L) {
//     return L.length;
// }
//
// int IsEmpty(const SqList L) {
//     if (L.length == 0) {
//         return 1;
//     } else {
//         return 0;
//     }
// }
//
// int GetElem(const SqList L, const int i, ElemType *e) {
//     if (i < 1 || i > L.length) {
//         return ERROR;
//     }
//     *e = L.Elem[i - 1];
//     return OK;
// }
//
// void Print(const SqList L) {
//     int i = 0;
//     for (i = 0; i < L.length; i++) {
//         printf("%d ", L.Elem[i]);
//     }
//     printf("\n");
// }
//
// int LocateElem(const SqList L, const ElemType e) {
//     for (int i = 0; i < L.length; i++) {
//         if (L.Elem[i] == e) {
//             return i + 1;
//         }
//     }
//     return 0;
// }
//
//
// int main() {
//     SqList L;
//     srand((unsigned int) time(NULL));
//     InitList(&L);
//     for (int i = 1; i <= 10; i++) {
//         int a = 1 + rand() % 1000;
//         InsertList(&L, i, a);
//     }
//     Print(L);
//     DeleteList(&L, 8);
//     Print(L);
//     int e;
//     GetElem(L, 2, &e);
//     printf("%d\n", e);
//     DestroyList(&L);
//     return 0;
// }


