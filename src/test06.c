//
// Created by kitsc on 2024/7/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct CirLinkList {
    ElemType date;
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
    (*L)->date = 0;
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
    s->date = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool DelCirLinkList(CirLinkList *L, int i) {
    if (L == NULL || (*L) == NULL) {
        return false;
    }
    int j = 0;
    LNode *p = (*L);
    while (p->next != (*L) && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == (*L) || p == (*L)) {
        return false;
    }
    LNode *s = p->next;
    p->next = s->next;
    free(s);
    return true;
}

void PrintLinkList(CirLinkList L) {
    LNode *p = L->next;
    while (p != L) {
        printf("%d ", p->date);
        p = p->next;
    }
    printf("\n");
}


int main() {
    LNode *p;
    InitCirLinkList(&p);
    InsertCirLinkList(&p, 1, 2);
    InsertCirLinkList(&p, 1, 3);
    InsertCirLinkList(&p, 2, 6);
    InsertCirLinkList(&p, 4, 6);
    // InsertCirLinkList(&p, 0, 9);
    PrintLinkList(p);
    DelCirLinkList(&p, 0);
    PrintLinkList(p);

    DesCirLinkList(&p);
    return 0;
}
