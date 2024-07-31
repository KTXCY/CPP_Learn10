// //
// // Created by kitsc on 2024/7/28.
// //
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define OVERFLOW -1
typedef int ElemType;
typedef int Status;
typedef int apile;


typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} Lnode, *LinkList;


//单链表的初始化
Status InitLIst(LinkList *L) {
    (*L) = (Lnode *) malloc(sizeof(Lnode));
    if ((*L) == NULL) {
        return FALSE;
    }
    (*L)->next = NULL;
    (*L)->data = 0;
    return OK;
}

//单链表的销毁
Status DestroyList_L(LinkList *L) {
    while (*L) {
        Lnode *p = (*L);
        (*L) = (*L)->next;
        free(p);
    }
    return OK;
}

//单链表的判空
int ListEmpty(LinkList L) {
    if (L->next) {
        return 0;
    } else {
        return 1;
    }
}

//清除单链表中的元素
void ClearList(const LinkList *L) {
    Lnode *p, *q;
    p = (*L)->next;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    (*L)->next = NULL;
}


// Status ClearList(const LinkList *L) {
//     Lnode *p, *q;
//     p = (*L)->next;
//     while (p != NULL) {
//         q = p->next;
//         free(p);
//         p = q;
//     }
//     (*L)->next = NULL;
//     return OK;
// }


//在单链表指定位置插入元素
Status ListInsert_L(const LinkList *L, const int i, const ElemType e) {
    Lnode *p = (*L);
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1) {
        return FALSE;
    }
    Lnode *s = (Lnode *) malloc(sizeof(Lnode));
    if (s == NULL) {
        return FALSE;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//删除单链表中指定位置的元素
Status ListDelete_L(const LinkList *L, const int i) {
    Lnode *p = (*L);
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL && j > i - 1) {
        return FALSE;
    }
    Lnode *q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

//求单链表的表长
int ListLength_L(const LinkList L) {
    LinkList p;
    p = L->next;
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

//获取链表中第i个元素
Status GetElem_L(const LinkList L, const int i, ElemType *e) {
    Lnode *p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) {
        return FALSE;
    }
    *e = p->data;
    return OK;
}


//根据指定数据获取该数据所在的位置（地址）
Lnode *LocateElem_P(LinkList L, ElemType e) {
    Lnode *p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//根据指定数据获取该数据位置序号
int LocateElem_I(LinkList L, ElemType e) {
    Lnode *p = L->next;
    int j = 1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    if (p) {
        return j;
    } else {
        return 0;
    }
}

//建立单链表头插法
Status CreateList_H(LinkList *L, int n) {
    (*L) = (Lnode *) malloc(sizeof(Lnode));
    if ((*L) == NULL) {
        return FALSE;
    }
    (*L)->data = 0;
    (*L)->next = NULL;
    for (int i = n; i > 0; i--) {
        Lnode *p = (Lnode *) malloc(sizeof(Lnode));
        if (p == NULL) {
            return FALSE;
        }
        scanf("%d", p->data);
        p->next = ((*L)->next);
        (*L)->next = p;
    }
    return TRUE;
}

//建立单链表尾插法
Status CreateList_R(LinkList *L, int n) {
    (*L) = (Lnode *) malloc(sizeof(Lnode));
    if ((*L) == NULL) {
        return FALSE;
    }
    (*L)->data = 0;
    (*L)->next = NULL;
    Lnode *r = (*L);
    for (int i = 0; i < n; i++) {
        Lnode *p = (Lnode *) malloc(sizeof(Lnode));
        if (p == NULL) {
            return FALSE;
        }
        scanf("%d", p->data);
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return TRUE;
} //
//
// int main() {
//     Lnode *p = NULL;
//     InitLIst(&p);
//     ListInsert_L(&p, 1, 1);
//     ListInsert_L(&p, 1, 2);
//     ListInsert_L(&p, 1, 3);
//     ListInsert_L(&p, 1, 4);
//     ListInsert_L(&p, 1, 5);
//     ListInsert_L(&p, 1, 6);
//     ListInsert_L(&p, 1, 7);
//     ListInsert_L(&p, 8, 8);
//     int a = 0;
//     GetElem_L(p, 1, &a);
//     printf("%d\n", a);
//     DestroyList_L(&p);
//     return 0;
// }
