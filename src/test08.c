//
// Created by kitsc on 2024/8/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef int SElemType;

typedef struct SqStack {
    SElemType *base;
    SElemType *top;
    size_t length;
} SqStack;

bool InitSqStack(SqStack *S) {
    if (S == NULL) {
        return false;
    }
    S->base = (SElemType *) malloc(sizeof(SElemType) * MAXSIZE);
    if (S->base == NULL) {
        return false;
    }
    S->top = S->base;
    S->length = MAXSIZE;
    return true;
}

bool StrackEmpty(SqStack S) {
    if (S.base == S.top) {
        return true;
    } else {
        return false;
    }
}

int StackLength(SqStack S) {
    return S.top - S.base;
}

bool ClearStack(SqStack *S) {
    if (S == NULL) {
        return false;
    }
    if (S->base == NULL) {
        return false;
    } else {
        S->top = S->base;
    }
    return true;
}

bool DestroyStack(SqStack *S) {
    if (S == NULL) {
        return false;
    }
    if (S->base == NULL) {
        return false;
    } else {
        free(S->base);
        S->length = 0;
        S->base = S->top = NULL;
    }
    return true;
}

bool Push(SqStack *S, SElemType e) {
    if (S->top - S->base == S->length) {
        return false;
    }
    *S->top++ = e;
    return true;
}

bool Pop(SqStack *S) {
    if (S == NULL) {
        return false;
    }
    if (S->top == S->base) {
        return false;
    }
    --S->top;
    return true;
}

void Print(SqStack S) {
    while (S.base != S.top) {
        printf("%d ", *S.base);
        S.base++;
    }
    printf("\n");
}


int main() {
    SqStack S;
    InitSqStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    Print(S);
    Pop(&S);
    Print(S);
    int a = StackLength(S);
    printf("%d\n", a);
    bool c = StrackEmpty(S);
    printf("%d\n", c);
    DestroyStack(&S);
    return 0;
}
