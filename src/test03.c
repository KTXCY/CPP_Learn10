//
// Created by kitsc on 24-7-28.
//

// #include <stdio.h>
// #include <stdlib.h>
//
// typedef struct Node {
//     int date;
//     struct Node *next;
// } Node, *LinkList;
//
// void InitList(LinkList *L) {
//     (*L) = (LinkList) malloc(sizeof(Node));
//     if (!(*L)) {
//         exit(1);
//     }
//     (*L)->next = (*L);
// }
//
// void InsertNode(LinkList L, int e) {
//
// }
//
// #include <stdio.h>
// #include <stdlib.h>
//
// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
// #define OVERFLOW -1
// typedef int ElemType;
// typedef int Status;
//
// typedef struct Lnode {
//     ElemType data;
//     struct Lnode *next;
// } Lnode, *LinkList;
//
// // 单循环链表的初始化
// Status InitList(LinkList *L) {
//     (*L) = (Lnode *) malloc(sizeof(Lnode));
//     if ((*L) == NULL) {
//         return FALSE;
//     }
//     (*L)->next = *L; // 初始化时，头结点的next指向自己，表示空链表
//     return OK;
// }
//
// // 单循环链表的销毁
// Status DestroyList(LinkList *L) {
//     Lnode *p = *L, *q;
//     if (p == NULL) return OK;
//     while (p->next != *L) {
//         // 循环直到找到最后一个节点
//         q = p;
//         p = p->next;
//         free(q);
//     }
//     free(p); // 释放头结点
//     *L = NULL; // 将链表指针置为空
//     return OK;
// }

// 在单循环链表指定位置插入元素
// Status ListInsert(LinkList *L, int i, ElemType e) {
//     if (*L == NULL) return FALSE;
//     Lnode *p = *L;
//     int j = 0;
//     // 找到第i-1个节点
//     while (p->next != *L && j < i - 1) {
//         p = p->next;
//         j++;
//     }
//     if (p->next == *L) {
//         // 如果已经到达链表末尾，则无法插入
//         return FALSE;
//     }
//     Lnode *s = (Lnode *) malloc(sizeof(Lnode));
//     if (s == NULL) return FALSE;
//     s->data = e;
//     s->next = p->next; // 新节点的next指向原第i个节点
//     p->next = s; // 第i-1个节点的next指向新节点
//     if (p == *L && s->next == *L) {
//         // 如果插入的是第一个节点，则更新尾节点的next
//         p->next->next = *L;
//     }
//     return OK;
// }

// Status ListInsert(LinkList *L, int i, ElemType e) {
//     if (*L == NULL) return FALSE;
//
//     Lnode *p = *L;
//     int j = 0;
//
//     while (p->next != *L && j < i - 1) {
//         p = p->next;
//         j++;
//     }
//
//     if (p->next == *L && i != 1) return FALSE; // 插入位置超出链表长度
//
//     Lnode *s = (Lnode *) malloc(sizeof(Lnode));
//     if (s == NULL) return FALSE;
//
//     s->data = e;
//     s->next = p->next;
//     p->next = s;
//
//     // 如果链表只有一个节点（头结点），则插入后s->next将自动指向头结点，保持循环
//
//     return OK;
// }

// Status ListInsert(LinkList *L, int i, ElemType e) {
//     if (*L == NULL) return ERROR; // 链表未初始化
//     if (i < 1) return ERROR; // 插入位置无效
//
//     Lnode *p = *L, *pre = NULL;
//     int j = 0;
//
//     // 找到第i-1个节点
//     while (p->next != *L && j < i - 1) {
//         pre = p;
//         p = p->next;
//         j++;
//     }
//
//     // 如果i大于链表长度+1，则插入位置无效
//     if (p->next == *L) return ERROR;
//
//     Lnode *s = (Lnode *)malloc(sizeof(Lnode));
//     if (s == NULL) return ERROR;
//
//     s->data = e;
//     s->next = p->next; // 新节点的next指向原p->next
//     p->next = s; // p的next指向新节点
//
//     // 如果是在链表开头插入（即p是头结点），则不需要特别处理
//     // 因为循环链表已经通过头结点的next指向自己保持了循环性
//
//     return OK;
// }
//
// // 删除单循环链表中指定位置的元素
// Status ListDelete(LinkList *L, int i) {
//     if (*L == NULL || (*L)->next == *L) return FALSE; // 空链表或只有一个头结点的情况
//     Lnode *p = *L;
//     int j = 0;
//     // 找到第i-1个节点
//     while (p->next != *L && j < i - 1) {
//         p = p->next;
//         j++;
//     }
//     if (p->next == *L) return FALSE; // 如果已经到达链表末尾，则无法删除
//     Lnode *q = p->next; // q是要删除的节点
//     p->next = q->next; // 跳过q节点
//     if (p->next == *L) {
//         // 如果删除的是最后一个节点，则更新尾节点的next
//         p->next = *L;
//     }
//     free(q);
//     return OK;
// }
//
// int main() {
//     Lnode *p;
//     InitList(&p);
//     ListInsert(&p, 1, 90);
//     ListInsert(&p, 2, 90);
//     DestroyList(&p);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define OVERFLOW -1
typedef int ElemType;
typedef int Status;

typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} Lnode, *LinkList;

// 单循环链表的初始化
Status InitList(LinkList *L) {
    (*L) = (Lnode *) malloc(sizeof(Lnode));
    if ((*L) == NULL) {
        return FALSE;
    }
    (*L)->next = *L; // 初始化时，头结点的next指向自己，表示空链表
    return OK;
}

// 单循环链表的销毁
Status DestroyList(LinkList *L) {
    Lnode *p = *L, *q;
    if (p == NULL) return OK;
    while (p->next != *L) {
        // 循环直到找到最后一个节点
        q = p;
        p = p->next;
        free(q);
    }
    free(p); // 释放头结点
    *L = NULL; // 将链表指针置为空
    return OK;
}

// 在单循环链表指定位置插入元素
Status ListInsert(LinkList *L, int i, ElemType e) {
    if (*L == NULL) return FALSE;
    Lnode *p = *L;
    int j = 0;
    // 找到第i-1个节点
    while (p->next != *L && j < i - 1) {
        p = p->next;
        j++;
    }
    // if (p->next == *L) {
    //     // 如果已经到达链表末尾，则无法插入
    //     return FALSE;
    // }
    Lnode *s = (Lnode *) malloc(sizeof(Lnode));
    if (s == NULL) return FALSE;
    s->data = e;
    s->next = p->next; // 新节点的next指向原第i个节点
    p->next = s; // 第i-1个节点的next指向新节点
    if (p == *L && s->next == *L) {
        // 如果插入的是第一个节点，则更新尾节点的next
        p->next->next = *L;
    }
    return OK;
}

// 删除单循环链表中指定位置的元素
Status ListDelete(LinkList *L, int i) {
    if (*L == NULL || (*L)->next == *L) return FALSE; // 空链表或只有一个头结点的情况
    Lnode *p = *L;
    int j = 0;
    // 找到第i-1个节点
    while (p->next != *L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == *L) return FALSE; // 如果已经到达链表末尾，则无法删除
    Lnode *q = p->next; // q是要删除的节点
    p->next = q->next; // 跳过q节点
    if (p->next == *L) {
        // 如果删除的是最后一个节点，则更新尾节点的next
        p->next = *L;
    }
    free(q);
    return OK;
}

// 注意：这里的ListInsert和ListDelete函数不再将LinkList指针声明为const，
// 因为我们需要修改它指向的链表结构。

int main() {
    Lnode *p;
    InitList(&p);
    ListInsert(&p, 1, 1);
    ListInsert(&p, 1, 2);
    ListInsert(&p, 1, 3);
    ListInsert(&p, 1, 4);
    ListDelete(&p, 1);
    ListDelete(&p, 2);
    DestroyList(&p);
    return 0;
}
