//
// Created by kitsc on 2024/8/1.
//

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
//
// typedef int ElemType;
//
// typedef struct DuLNode {
//     ElemType data;
//     struct DuLNode *prior;
//     struct DuLNode *next;
// } DuLNode, *DuLinkList;
//
// bool InitList(DuLinkList *head) {
//     *head = (DuLNode *) calloc(1, sizeof(DuLNode));
//     if ((*head) == NULL) {
//         return false;
//     }
//     (*head)->next = (*head)->prior = NULL;
//     return true;
// }
//
// //在链表末尾插入新节点
//
// bool InsertLast(DuLinkList *H, ElemType val) {
//     if (H == NULL || (*H) == NULL) {
//         return false;
//     }
//     DuLNode *newNode = (DuLNode *) malloc(sizeof(DuLNode));
//     if (newNode == NULL) {
//         return false;
//     }
//     newNode->data = val;
//
// }
//
//
// int main() {
//     DuLNode *H;
//     InitList(&H);
//
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
//
// // 定义 ElemType，这里假设为 int
// typedef int ElemType;
//
// // 双向链表节点
// typedef struct DuLNode {
//     ElemType data;
//     struct DuLNode *prior;
//     struct DuLNode *next;
// } DuLNode, *DuLinkList;

// 初始化链表
// DuLinkList InitList() {
//     DuLNode *head = (DuLNode *)malloc(sizeof(DuLNode));
//     if (!head) return NULL;
//     head->prior = head->next = NULL; // 头结点的prior和next都为NULL
//     return head;
// }
//
// // 在链表末尾插入新节点
// void InsertLast(DuLinkList list, ElemType elem) {
//     if (!list) return;
//     DuLNode *newNode = (DuLNode *)malloc(sizeof(DuLNode));
//     if (!newNode) return;
//     newNode->data = elem;
//     newNode->prior = list->prior; // 新节点的prior指向最后一个节点（或NULL，如果链表为空）
//     newNode->next = NULL;
//     if (list->prior) { // 如果链表不为空
//         list->prior->next = newNode; // 更新最后一个节点的next
//     }
//     list->prior = newNode; // 更新头结点的prior为新的最后一个节点
//     if (!list->next) { // 如果链表为空，则头结点的next也指向新节点
//         list->next = newNode;
//     }
// }
//
// // 在链表头部插入新节点
// void InsertFirst(DuLinkList list, ElemType elem) {
//     if (!list) return;
//     DuLNode *newNode = (DuLNode *)malloc(sizeof(DuLNode));
//     if (!newNode) return;
//     newNode->data = elem;
//     newNode->next = list->next; // 新节点的next指向原来的第一个节点
//     if (list->next) { // 如果链表不为空
//         list->next->prior = newNode; // 更新原来第一个节点的prior
//     }
//     newNode->prior = list; // 新节点的prior指向头结点
//     list->next = newNode; // 更新头结点的next为新节点
//     if (!list->prior) { // 正常情况下，这里总是为false，因为头结点的prior始终为NULL
//         list->prior = newNode; // 但为了完整性，这里还是写一下（虽然实际上是多余的）
//     }
// }
//
// // 打印链表（不包括头结点）
// void PrintList(DuLinkList list) {
//     DuLNode *p = list->next; // 从头结点的下一个节点开始打印
//     while (p != NULL) {
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }
//
// // 释放链表（不包括头结点）
// void FreeList(DuLinkList list) {
//     DuLNode *p = list->next; // 跳过头结点
//     while (p != NULL) {
//         DuLNode *tmp = p;
//         p = p->next;
//         free(tmp);
//     }
//     // 注意：这里没有释放头结点，因为头结点是在InitList中分配的，并且通常在整个链表的生命周期内都存在
// }
//
// int main() {
//     DuLinkList list = InitList();
//     InsertLast(list, 1);
//     InsertLast(list, 2);
//     InsertFirst(list, 0); // 在头部插入一个元素
//     PrintList(list);
//     FreeList(list);
//     // 注意：这里没有释放头结点
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义 ElemType，这里假设为 int
typedef int ElemType;

// 双向链表节点
typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

bool InitList(DuLinkList *L) {
    if (L == NULL) {
        fprintf(stderr, "InitList: NULL pointer passed as argument.\n");
        return false;
    }
    (*L) = (DuLNode *) calloc(1, sizeof(DuLNode));
    if ((*L) == NULL) {
        fprintf(stderr, "InitList: Memory allocation failed.\n");
        return false;
    }
    (*L)->next = (*L)->prior = NULL;
    return true;
}

bool InsertLink(DuLinkList *L, ElemType val) {
    if (L == NULL || (*L) == NULL) {
        fprintf(stderr, "InsertLink: NULL pointer passed as argument or list is uninitialized.\n");
        return false;
    }
    DuLNode *p = (DuLNode *) malloc(sizeof(DuLNode));
    if (p == NULL) {
        fprintf(stderr, "InsertLink: Memory allocation failed.\n");
        return false;
    }
    p->data = val;
    p->next = (*L)->next;
    p->prior = (*L);
    if ((*L)->next != NULL) {
        (*L)->next->prior = p;
    }
    (*L)->next = p;
    return true;
}

bool DestroyList(DuLinkList *L) {
    if (L == NULL || (*L) == NULL) return false;

    DuLNode *current = (*L)->next;
    while (current != NULL) {
        DuLNode *next = current->next;
        free(current);
        current = next;
    }
    free(*L);
    *L = NULL;
    return true;
}

DuLNode *GetElemP_DUL(DuLinkList *L, int i) {
    if (L == NULL || i < 1) {
        return NULL;
    }
    int j = 1;
    DuLNode *p = (*L)->next;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) {
        return NULL;
    }
    return p;
}



bool ListInsert_Dul(DuLinkList *L, int i, ElemType e) {
    if (L == NULL || (*L) == NULL) {
        return false;
    }
    DuLNode *p = GetElemP_DUL(L, i);
    if (p == NULL) {
        return false;
    }
    DuLNode *NewNode = (DuLNode *) malloc(sizeof(DuLNode));
    if (NewNode == NULL) {
        return false;
    }
    NewNode->data = e;
    NewNode->prior = p->prior;
    NewNode->next = p;
    p->prior->next = NewNode;
    p->prior = NewNode;
    return true;
}

bool DelInsert_Dul(DuLinkList *L, int i) {
    if (L == NULL || (*L) == NULL) {
        return false;
    }
    DuLNode *p = GetElemP_DUL(L, i);
    if (p == NULL) {
        return false;
    }

    // 保护措施：再次检查p是否为有效指针
    if (p->prior == NULL && p->next == NULL) {
        return false; // 如果p是孤立的节点，则不进行操作
    }
    p->prior->next = p->next;
    if (p->next != NULL) {
        // 避免空指针异常
        p->next->prior = p->prior;
    }
    p->next = NULL;
    p->prior = NULL;
    free(p);
    p = NULL;
    return true;
}

// bool DelInsert_Dul(DuLinkList *L, int i) {
//     DuLNode *p = GetElemP_DUL(L, i);
//     if (p == NULL) {
//         return false;
//     }
//     p->prior->next = p->next;
//     p->next->prior = p->prior;
//     free(p);
//     return true;
// }

void printList(DuLinkList L) {
    DuLNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    DuLNode *H;

    InitList(&H);
    InsertLink(&H, 1);
    InsertLink(&H, 2);
    InsertLink(&H, 3);
    InsertLink(&H, 4);
    printList(H);
    ListInsert_Dul(&H, 4, 8);
    // DuLNode *p = GetElemP_DUL(H, 2);
    // printf("%d\n", p->prior->data);
    // ListInsert_Dul(&H, 2, 5);
    printList(H);
    DestroyList(&H);
    return 0;
}
