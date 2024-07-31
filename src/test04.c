//
// Created by kitsc on 24-7-31.
//

// #include <stdio.h>
// #include <stdlib.h>
//
// #define OK 1
// #define FALSE 0
// #define TURE 1
// #define OVERFLOW -1
//
// typedef int Status;
// typedef int ElemType;
//
// typedef struct CirLinkList {
//     ElemType data;
//     struct CirLinkList *next;
// } LNode, *CirLinkList;
//
// Status InitCirList(CirLinkList *L) {
//     if (L == NULL) {
//         return FALSE;
//     }
//     (*L) = (LNode *) malloc(sizeof(LNode));
//     if ((*L) == NULL) {
//         return FALSE;
//     }
//     (*L)->data = 0;
//     (*L)->next = (*L);
//     return TURE;
// }
//
// Status DestoryList(CirLinkList *L) {
//     if (L == NULL) {
//         return FALSE;
//     }
//     LNode *p = (*L), *q;
//     while (p->next != (*L)) {
//         q = p;
//         p = p->next;
//         free(q);
//     }
//     free(p);
//     (*L) = NULL;
//     return OK;
// }
//
// Status InsertCriList(CirLinkList *L, int i, ElemType e) {
//     if (L == NULL || (*L) == NULL) {
//         return FALSE;
//     }
//     LNode *p = (*L);
//     int j = 0;
//     while (p != (*L) && j < i - 1) {
//         p = p->next;
//         j++;
//     }
//     LNode *s = (LNode *) malloc(sizeof(LNode));
//     if (s == NULL) {
//         return FALSE;
//     }
//     s->data = e;
//     s->next = p->next;
//     p->next = s;
//     return OK;
// }
//
//
// // Status InsertCriList(CirLinkList *L, int i, ElemType e) {
// //     if (L == NULL || (*L) == NULL) {
// //         return FALSE;
// //     }
// //     LNode *p = (*L);
// //     int j = 0;
// //     while (p != (*L) && j < i - 1) {
// //         p = p->next;
// //         j++;
// //     }
// //     LNode *s = (LNode *) malloc(sizeof(LNode));
// //     if (s == NULL) {
// //         return FALSE;
// //     }
// //     s->data = e;
// //     s->next = p->next;
// //     p->next = s;
// //     return OK;
// // }
//
//
// int main() {
//     LNode *p = NULL;
//     InitCirList(&p);
//     InsertCriList(&p, 1, 1);
//     InsertCriList(&p, 1, 2);
//     InsertCriList(&p, 1, 3);
//     InsertCriList(&p, 5, 4);
//     DestoryList(&p);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
//
// #define OK 1
// #define OVERFLOW -1
// #define TRUE 1
// #define FALSE 0
//
// typedef int Status;
// typedef int ElemType;
//
// typedef struct CriLinkList {
//     ElemType data;
//     struct CriLinkList *next;
// } LNode, *CriLinkList;
//
// Status InitCriLinkList(CriLinkList *L) {
//     (*L) = (LNode *) malloc(sizeof(LNode));
//     if ((*L) == NULL) {
//         return FALSE;
//     }
//     (*L)->next = (*L);
//     (*L)->data = 0;
//     return TRUE;
// }
//
// Status DestoryCriList(CriLinkList *L) {
//     if ((*L) == NULL) {
//         return FALSE;
//     }
//     LNode *p = (*L), *q;
//     while (p->next != (*L)) {
//         q = p;
//         p = p->next;
//         free(q);
//     }
//     // free(p);
//     // p = NULL;
//
//     return OK;
// }
//
// Status InsertCriList(CriLinkList *L, int i, ElemType e) {
//     if ((*L) == NULL) {
//         return FALSE;
//     }
//     LNode *p = (*L);
//     int j = 0;
//     while (p != (*L) && j < i - 1) {
//         p = p->next;
//         j++;
//     }
//     if (j > i - 1) {
//         return FALSE;
//     }
//     LNode *S = (LNode *) malloc(sizeof(LNode));
//     if (S == NULL) {
//         return FALSE;
//     }
//     S->data = e;
//     S->next = p->next;
//     p->next = S;
//     if (p == (*L) && S->next == (*L)) {
//         p->next->next = (*L);
//     }
//     return TRUE;
// }
//
//
// int main() {
//     LNode *L;
//     InitCriLinkList(&L);
//     InsertCriList(&L, 1, 8);
//     InsertCriList(&L, 2, 1);
//     DestoryCriList(&L);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
//
// #define MAXSIZE 100
// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define OVERFLOW -1
// typedef int ElemType;
// typedef int Status;
//
// typedef struct Lnode {
//     ElemType data;
//     struct Lnode *next;
// } Lnode, *LinkList;
//
// // 循环单链表的初始化
// Status InitList(LinkList *L) {
//     (*L) = (Lnode *)malloc(sizeof(Lnode));
//     if ((*L) == NULL) {
//         return FALSE;
//     }
//     (*L)->next = (*L);  // 尾节点指向头节点，形成循环
//     (*L)->data = 0;
//     return OK;
// }
//
// // 循环单链表的销毁
// Status DestroyList_L(LinkList *L) {
//     Lnode *p = (*L)->next;  // 从首元节点开始
//     while (p != (*L)) {  // 未到达头节点
//         Lnode *q = p;
//         p = p->next;
//         free(q);
//     }
//     free(*L);  // 最后释放头节点
//     *L = NULL;
//     return OK;
// }
//
// // 在循环单链表指定位置插入元素
// Status ListInsert_L(LinkList *L, const int i, const ElemType e) {
//     Lnode *p = (*L);
//     int j = 0;
//     while (p->next != (*L) && j < i - 1) {  // 寻找第i-1个节点
//         p = p->next;
//         j++;
//     }
//     if (p->next == (*L) || j > i - 1) {  // i小于1或大于表长+1
//         return FALSE;
//     }
//     Lnode *s = (Lnode *)malloc(sizeof(Lnode));
//     if (s == NULL) {
//         return FALSE;
//     }
//     s->data = e;
//     s->next = p->next;
//     p->next = s;
//     return OK;
// }
//
// // 删除循环单链表中指定位置的元素
// Status ListDelete_L(LinkList *L, const int i) {
//     Lnode *p = (*L);
//     int j = 0;
//     while (p->next != (*L) && j < i - 1) {  // 寻找第i-1个节点
//         p = p->next;
//         j++;
//     }
//     if (p->next == (*L) || j > i - 1) {  // i小于1或大于表长
//         return FALSE;
//     }
//     Lnode *q = p->next;
//     p->next = q->next;
//     free(q);
//     return OK;
// }
//
// int main() {
//
//     Lnode *L;
//     InitList(&L);
//     ListInsert_L(&L, 1, 8);
//
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
//
// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
//
// typedef int ElemType;
// typedef int Status;
//
// typedef struct Lnode {
//     ElemType data;
//     struct Lnode *next;
// } Lnode, *LinkList;
//
// // 初始化循环单链表
// Status InitList(LinkList *L) {
//     *L = (LinkList)malloc(sizeof(Lnode)); // 创建头节点
//     if (*L == NULL) {
//         return ERROR;
//     }
//     (*L)->next = *L; // 头节点指向自己，形成循环
//     return OK;
// }
//
// // 销毁循环单链表
// Status DestroyList(LinkList *L) {
//     LinkList p = (*L)->next; // 从首元节点开始
//     while (p != *L) { // 未到达头节点
//         LinkList q = p;
//         p = p->next;
//         free(q);
//     }
//     free(*L); // 最后释放头节点
//     *L = NULL;
//     return OK;
// }
//
// // 在循环单链表指定位置插入元素
// Status ListInsert(LinkList *L, int i, ElemType e) {
//     int j = 0;
//     LinkList p = *L;
//     while (p->next != *L && j < i - 1) { // 寻找第i-1个节点
//         p = p->next;
//         j++;
//     }
//     if (p->next == *L || j > i - 1) { // i小于1或大于表长+1
//         return ERROR;
//     }
//     LinkList s = (LinkList)malloc(sizeof(Lnode)); // 创建新节点
//     if (s == NULL) {
//         return ERROR;
//     }
//     s->data = e;
//     s->next = p->next;
//     p->next = s;
//     return OK;
// }
//
// // 删除循环单链表中指定位置的元素
// Status ListDelete(LinkList *L, int i) {
//     int j = 0;
//     LinkList p = *L;
//     while (p->next != *L && j < i - 1) { // 寻找第i-1个节点
//         p = p->next;
//         j++;
//     }
//     if (p->next == *L || j > i - 1) { // i小于1或大于表长
//         return ERROR;
//     }
//     LinkList q = p->next;
//     p->next = q->next;
//     free(q);
//     return OK;
// }
//
// // 打印循环单链表
// void PrintList(LinkList L) {
//     LinkList p = L->next; // 从首元节点开始
//     while (p != L) { // 未到达头节点
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }
//
// int main() {
//     LinkList L;
//     InitList(&L);
//     ListInsert(&L, 1, 10);
//     ListInsert(&L, 2, 20);
//     ListInsert(&L, 3, 30);
//     PrintList(L); // 打印链表: 10 20 30
//     ListDelete(&L, 2);
//     PrintList(L); // 打印链表: 10 30
//     DestroyList(&L);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
//
// typedef _Bool Status;
// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
//
// typedef int ElemType;
//
// typedef struct Lnode {
//     ElemType data;
//     struct Lnode *next;
// } Lnode, *LinkList;
//
// // 初始化循环单链表
// Status InitList(LinkList *L) {
//     *L = (LinkList)malloc(sizeof(Lnode)); // 创建头节点
//     if (*L == NULL) {
//         return ERROR;
//     }
//     (*L)->next = *L; // 头节点指向自己，形成循环
//     return OK;
// }
//
// // 销毁循环单链表
// Status DestroyList(LinkList *L) {
//     LinkList p = (*L)->next; // 从首元节点开始
//     while (p != *L) { // 未到达头节点
//         LinkList q = p;
//         p = p->next;
//         free(q);
//     }
//     free(*L); // 最后释放头节点
//     *L = NULL;
//     return OK;
// }
//
// // 在循环单链表指定位置插入元素
// Status ListInsert(LinkList *L, int i, ElemType e) {
//     int j = 0;
//     LinkList p = *L;
//     while (p->next != *L && j < i - 1) { // 寻找第i-1个节点
//         p = p->next;
//         j++;
//     }
//     if (p->next == *L || j > i - 1) { // i小于1或大于表长+1
//         return ERROR;
//     }
//     LinkList s = (LinkList)malloc(sizeof(Lnode)); // 创建新节点
//     if (s == NULL) {
//         return ERROR;
//     }
//     s->data = e;
//     s->next = p->next;
//     p->next = s;
//
//     return OK; // 成功时确保资源已被正确分配，无泄漏风险
// }
//
// // 删除循环单链表中指定位置的元素
// Status ListDelete(LinkList *L, int i) {
//     int j = 0;
//     LinkList p = *L;
//     while (p->next != *L && j < i - 1) { // 寻找第i-1个节点
//         p = p->next;
//         j++;
//     }
//     if (p->next == *L || j > i - 1) { // i小于1或大于表长
//         return ERROR;
//     }
//     LinkList q = p->next;
//     p->next = q->next;
//     free(q);
//     return OK;
// }
//
// // 打印循环单链表
// void PrintList(LinkList L) {
//     LinkList p = L->next; // 从首元节点开始
//     while (p != L) { // 未到达头节点
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }
//
// int main() {
//     LinkList L;
//     InitList(&L);
//     ListInsert(&L, 1, 10);
//     ListInsert(&L, 2, 20);
//     ListInsert(&L, 3, 30);
//     PrintList(L); // 打印链表: 10 20 30
//     ListDelete(&L, 2);
//     PrintList(L); // 打印链表: 10 30
//     DestroyList(&L);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 假设元素类型为int

typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} Lnode, *LinkList;

// 创建循环单链表
LinkList CreateList() {
    LinkList head = (LinkList) malloc(sizeof(Lnode)); // 创建头节点
    if (!head) return NULL;
    head->next = head; // 初始化为循环单链表
    return head;
}

// 插入元素，pos为插入位置（从1开始计数），elem为要插入的元素值
int ListInsert(LinkList L, int pos, ElemType elem) {
    int i = 0;
    LinkList p = L;
    while (i < pos - 1 && p->next != L) {
        // 查找第pos-1个节点
        p = p->next;
        i++;
    }
    if (i < pos - 1) return 0; // pos大于链表长度+1
    LinkList newNode = (LinkList) malloc(sizeof(Lnode));
    newNode->data = elem;
    newNode->next = p->next; // 插入节点
    p->next = newNode;
    return 1;
}

// 删除元素，pos为删除位置（从1开始计数）
int ListDelete(LinkList L, int pos) {
    int i = 0;
    LinkList p = L;
    while (i < pos - 1 && p->next != L) {
        // 查找第pos-1个节点
        p = p->next;
        i++;
    }
    if (i < pos - 1 || p->next == L) return 0; // pos大于链表长度或位置不合理
    LinkList q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

// 遍历链表
void ListTraverse(LinkList L) {
    LinkList p = L->next; // 跳过头节点
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkList L = CreateList();
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListTraverse(L); // 输出: 10 20 30
    ListDelete(L, 2);
    ListTraverse(L); // 输出: 10 30
    return 0;
}