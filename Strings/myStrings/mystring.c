#include "mystring.h"
#include <stddef.h>

/* ---------- String length ---------- */
size_t mystrlen(const char *s) {
    const char *temp = s;
    while (*temp != '\0') temp++;
    return temp - s;
}

/* ---------- String copy ---------- */
char* mystrcpy(char *dest, const char *src) {
    char *temp = dest;
    while (*src != '\0') *temp++ = *src++;
    *temp = '\0';
    return dest;
}

char* mystrncpy(char *dest, const char *src, size_t n) {
    size_t i = 0;
    for (; i < n && src[i] != '\0'; i++) dest[i] = src[i];
    for (; i < n; i++) dest[i] = '\0';
    return dest;
}

/* ---------- String concatenation ---------- */
char* mystrcat(char *dest, const char *src) {
    char *temp = dest;
    while (*temp != '\0') temp++;
    while (*src != '\0') *temp++ = *src++;
    *temp = '\0';
    return dest;
}

char* mystrncat(char *dest, const char *src, size_t n) {
    char *temp = dest;
    while (*temp != '\0') temp++;
    size_t i = 0;
    while (*src != '\0' && i < n) {
        *temp++ = *src++;
        i++;
    }
    *temp = '\0';
    return dest;
}

/* ---------- String comparison ---------- */
int mystrcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int mystrncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;
    while (i < n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        i++;
    }
    if (i == n) return 0;
    return (unsigned char)*s1 - (unsigned char)*s2;
}

/* ---------- String search ---------- */
char* mystrchr(const char *s, int c) {
    while (*s) {
        if (*s == (char)c) return (char*)s;
        s++;
    }
    if (c == '\0') return (char*)s;
    return NULL;
}

char* mystrrchr(const char *s, int c) {
    char *last = NULL;
    while (*s) {
        if (*s == (char)c) last = (char*)s;
        s++;
    }
    if (c == '\0') return (char*)s;
    return last;
}

static int inString(const char *s, char c) {
    while (*s) {
        if (*s == c) return 1;
        s++;
    }
    return 0;
}

size_t mystrcspn(const char *s, const char *reject) {
    size_t count = 0;
    while (*s && !inString(reject, *s)) {
        count++;
        s++;
    }
    return count;
}

size_t mystrspn(const char *s, const char *accept) {
    size_t count = 0;
    while (*s && inString(accept, *s)) {
        count++;
        s++;
    }
    return count;
}

char* mystrpbrk(const char *s1, const char *s2) {
    while (*s1) {
        if (inString(s2, *s1)) return (char*)s1;
        s1++;
    }
    return NULL;
}

char* mystrstr(const char *haystack, const char *needle) {
    if (*needle == '\0') return (char*)haystack;
    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') return (char*)haystack;
    }
    return NULL;
}

/* ---------- Tokenizer ---------- */
char* mystrtok(char *str, const char *delim) {
    static char *next = NULL;
    if (str) next = str;
    if (!next) return NULL;

    char *start = next;
    char *end = start;

    while (*end) {
        const char *d = delim;
        int is_delim = 0;
        while (*d) {
            if (*end == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (is_delim) {
            *end = '\0';
            next = end + 1;
            return start;
        }
        end++;
    }
    next = NULL;
    return start;
}

/* ---------- Character handling ---------- */
int myisdigit(int c) { return c >= '0' && c <= '9'; }
int myisalpha(int c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
int myisalnum(int c) { return myisalpha(c) || myisdigit(c); }
int myisxdigit(int c) {
    return myisdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
int myislower(int c) { return c >= 'a' && c <= 'z'; }
int myisupper(int c) { return c >= 'A' && c <= 'Z'; }
int mytolower(int c) { return myisupper(c) ? c + 32 : c; }
int mytoupper(int c) { return myislower(c) ? c - 32 : c; }
int myisspace(int c) { return c == ' ' || (c >= 9 && c <= 13); }
int myiscntrl(int c) { return (c >= 0 && c <= 31) || c == 127; }
int myispunct(int c) { return myisprint(c) && !myisalnum(c) && c != ' '; }
int myisprint(int c) { return c >= 32 && c <= 126; }
int myisgraph(int c) { return c >= 33 && c <= 126; }

