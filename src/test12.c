//
// Created by kitsc on 2024/8/10.
//
//
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #define MAXLEN 255
//
// typedef struct SString {
//     char ch[MAXLEN + 1];
//     int length;
// } String;
//
// bool AssignSString(String *S, const char *ch) {
//     if (S == NULL) {
//         return false;
//     }
//     if (strlen(ch) == 0 || strlen(ch) > MAXLEN) {
//         return false;
//     }
//     strcpy(S->ch + 1, ch);
//     S->ch[0] = '#';
//     S->length = strlen(S->ch);
//     return true;
// }
//
//
//
// int main() {
//     String S;
//     const char *ch1 = "Hello, World";
//     AssignSString(&S, ch1);
//     printf("%s\n", S.ch+1);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 255

typedef struct SString {
    char *ch;
    size_t length;
} SString;

bool StrAssign(SString *T, const char *chars) {
    if (T == NULL || chars == NULL) {
        return false;
    }
    size_t len = strlen(chars);
    if (len > MAXLEN) {
        return false;
    }
    T->ch = (char *) malloc(strlen(chars) + 1);
    if (T->ch == NULL) {
        return false;
    }
    strcpy(T->ch, chars);
    T->length = len;
    return true;
}

int StrCompare(SString S, SString T) {
    return strcmp(S.ch, T.ch);
}

int StrLength(SString S) {
    return S.length;
}

bool Concat(SString *T, SString S1, SString S2) {
    if (T == NULL) {
        return false;
    }
    T->ch = (char *) malloc(S1.length + S2.length + 1);
    if (T->ch == NULL) {
        return false;
    }
    strcpy(T->ch, S1.ch);
    strcat(T->ch, S2.ch);
    T->length = S1.length + S2.length;
    return true;
}

bool SubString(SString *Sub, SString S, int pos, int len) {
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1) {
        Sub->ch = NULL;
        Sub->length = 0;
        return false;
    }
    Sub->ch = (char *) malloc(len + 1);
    if (Sub->ch == NULL) {
        return false;
    }
    strncpy(Sub->ch, S.ch + pos - 1, len);
    Sub->ch[len] = '\0';
    Sub->length = len;
    return true;
}

bool StrCopy(SString *T, SString S) {
    if (T == NULL) {
        return false;
    }
    T->ch = (char *) malloc(sizeof(S.length + 1));
    if (T->ch == NULL) {
        return false;
    }
    strcpy(T->ch, S.ch);
    T->length = S.length;
    return true;
}

bool StrEmpty(SString S) {
    if (S.length == 0) {
        return true;
    } else {
        return false;
    }
}


int Index_BF(SString S, SString T, int pos) {
    if (pos < 0 || pos > MAXLEN - 1) {
        return -1;
    }
    if (S.ch == NULL || T.ch == NULL) {
        return -1;
    }
    int i = pos;
    int j = 0;
    while (i < S.length && j < T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.length) {
        return i - T.length;
    } else {
        return -1;
    }
}


int main() {
    SString S;
    SString T;
    SString C;
    SString Sub;
    const char *ch1 = "Hello, World!!!";
    const char *ch2 = "World";
    StrAssign(&S, ch1);
    StrAssign(&T, ch2);
    int c = Index_BF(S, T, 0);
    printf("%d\n", c);
    return 0;
}
