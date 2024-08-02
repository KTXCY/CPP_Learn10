//
// Created by kitsc on 2024/7/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct CirLinkList {
    ElemType data;
    struct CirLinkList *next;
} LNode, *CirLinkList;

bool InitCirLinkList(CirLinkList *L) {
    if (L == NULL) {
        return false;
    }
    (*L) = (LNode *) malloc(sizeof(LNode));
    if ((*L) == NULL) {
        return false;
    }
    (*L)->data = 0;
    (*L)->next = (*L);
    return true;
}

bool DesCirLinkList(CirLinkList *L) {
    if (L == NULL || (*L) == NULL) {
        return false;
    }
    LNode *p = (*L)->next;
    while (p != (*L)) {
        LNode *q = p;
        p = p->next;
        free(q);
    }
    free(p);
    (*L) = NULL;
    return true;
}

bool InsertCirLinkList(CirLinkList *L, int i, ElemType e) {
    if (L == NULL || (*L) == NULL) {
        return false;
    }
    if (i < 1) {
        return false;
    }
    int j = 0;
    LNode *p = (*L);
    while (p->next != (*L) && j < i - 1) {
        p = p->next;
        j++;
    }
    if (j < i - 1) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool DelCirLinkList(CirLinkList *L, int i) {
    if (L == NULL || (*L) == NULL) {
        return false;
    }
    if (i < 1) {
        return false;
    }
    int j = 0;
    LNode *p = (*L);
    while (p->next != (*L) && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == (*L)) {
        return false;
    }
    LNode *s = p->next;
    p->next = s->next;
    free(s);
    return true;
}

bool CreateCirList_H(CirLinkList *L, int n) {
    (*L) = (LNode *) malloc(sizeof(LNode));
    if ((*L) == NULL) {
        return false;
    }
    (*L)->data = 0;
    (*L)->next = (*L);

    for (int i = 0; i < n; i++) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        if (p == NULL) {
            return false;
        }
        scanf("%d", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return true;
}

bool CreateCirList_R(CirLinkList *L, int n) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    if ((*L) == NULL) {
        return false;
    }
    (*L)->data = 0;
    (*L)->next = (*L);
    LNode *tail = (*L);
    for (int i = 0; i < n; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL) {
            return false;
        }
        scanf("%d", &p->data);
        p->next = (*L);
        tail->next = p;
        tail = p;
    }
    return true;
}


int main() {
    LNode *p;
    InitCirLinkList(&p);
    InsertCirLinkList(&p, 1, 2);
    InsertCirLinkList(&p, 1, 3);
    InsertCirLinkList(&p, 2, 6);
    InsertCirLinkList(&p, 4, 6);
    DelCirLinkList(&p, 0);


    DesCirLinkList(&p);
    return 0;
}
