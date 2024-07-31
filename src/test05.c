//
// Created by kitsc on 2024/7/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} Lnode, *LinkList;


//初始化化单循环链表
bool InitList(LinkList *L) {
    (*L) = (Lnode *) malloc(sizeof(Lnode));
    if ((*L) == NULL) {
        return false;
    }
    (*L)->data = 0;
    (*L)->next = (*L);
    return true;
}

//销毁循环链表
bool DestroyList(LinkList *L) {
    if (L == NULL) {
        return false;
    }
    if ((*L) == NULL) {
        return false;
    }
    Lnode *p = (*L)->next;
    while (p != (*L)) {
        Lnode *q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    (*L) = NULL;
    return true;
}

//在循环链表中插入元素
bool InsertList(LinkList *L, int i, ElemType e) {
    if (L == NULL || (*L) == NULL) {
        return false;
    }
    Lnode *p = (*L);
    int j = 0;
    while (p->next != *L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (j < i - 1) {
        return false;
    }
    Lnode *s = (Lnode *) malloc(sizeof(Lnode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除循环链表中的元素
bool ListDelete(LinkList *L, int i) {
    int j = 0;
    Lnode *p = (*L);
    while (j < i - 1 && p->next != (*L)) {
        p = p->next;
        j++;
    }
    if (j < i - 1 || p->next == *L) {
        return false;
    }
    Lnode *s = p->next;
    p->next = s->next;
    free(s);
    return 1;
}

//打印循环链表
void ListTraverse(LinkList L) {
    LinkList p = L->next; // 跳过头节点
    while (p != L) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

bool CreateList_H_Loop(LinkList *L, int n) {
    (*L) = (Lnode *) malloc(sizeof(Lnode));
    if ((*L) == NULL) {
        return false;
    }
    (*L)->data = 0; // 头节点数据域不存储有效数据
    (*L)->next = (*L); // 初始化为循环链表

    // Lnode *tail = (*L); // 尾指针，始终指向链表最后一个节点
    for (int i = 0; i < n; i++) {
        Lnode *p = (Lnode *) malloc(sizeof(Lnode));
        if (p == NULL) {
            return false;
        }
        scanf("%d", &p->data); // 注意这里应该是 &p->data
        p->next = (*L)->next; // 新节点指向头节点，形成循环
        (*L)->next = p;
        // 插入到头节点之后，并更新尾指针
        // tail->next = p;
        // tail = p;
    }
    return true;
}

bool CreateList_R_Loop(LinkList *L, int n) {
    (*L) = (Lnode *)malloc(sizeof(Lnode));
    if ((*L) == NULL) {
        return false;
    }
    (*L)->data = 0; // 头节点数据域不存储有效数据
    (*L)->next = (*L); // 初始化为循环链表

    Lnode *tail = (*L); // 尾指针，始终指向链表最后一个节点
    for (int i = 0; i < n; i++) {
        Lnode *p = (Lnode *)malloc(sizeof(Lnode));
        if (p == NULL) {
            return false;
        }
        scanf("%d", &p->data); // 注意这里应该是 &p->data
        p->next = (*L); // 新节点指向头节点，形成循环

        // 插入到尾节点之后，并更新尾指针
        tail->next = p;
        tail = p;
    }
    return true;
}

int main() {
    Lnode *H;
    InitList(&H);
    CreateList_H_Loop(&H, 3);
    ListTraverse(H);

    DestroyList(&H);
    return 0;
}
