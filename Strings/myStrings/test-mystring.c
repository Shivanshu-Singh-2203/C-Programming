/**
 * test-mystring.c
 *
 * Unit tests for testing operations in mystring library
 * Covers all major functions from <string.h> and <ctype.h>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mystring.h"

/* ---------- Character handling ---------- */
int testCharFuncs() {
    int result = 1;

    for (int c = -1; c <= 256; c++) {
        if ((isdigit(c) != myisdigit(c)) ||
            (isalpha(c) != myisalpha(c)) ||
            (isalnum(c) != myisalnum(c)) ||
            (isxdigit(c) != myisxdigit(c)) ||
            (islower(c) != myislower(c)) ||
            (isupper(c) != myisupper(c)) ||
            (tolower(c) != mytolower(c)) ||
            (toupper(c) != mytoupper(c)) ||
            (isspace(c) != myisspace(c)) ||
            (iscntrl(c) != myiscntrl(c)) ||
            (ispunct(c) != myispunct(c)) ||
            (isprint(c) != myisprint(c)) ||
            (isgraph(c) != myisgraph(c)))
        {
            result = 0;
        }
    }
    return result;
}

/* ---------- String conversion ---------- */
int testConversion() {
    int result = 1;

    char *end1, *end2;
    const char *s1 = "123.45abc";
    if (strtod(s1, &end1) != mystrtod(s1, &end2) || (end1 - s1) != (end2 - s1))
        result = 0;

    const char *s2 = "   -123xyz";
    if (strtol(s2, &end1, 10) != mystrtol(s2, &end2, 10))
        result = 0;

    const char *s3 = "77777abc";
    if (strtoul(s3, &end1, 8) != mystrtoul(s3, &end2, 8))
        result = 0;

    return result;
}

/* ---------- String manipulation ---------- */
int testManipulation() {
    int result = 1;

    // strcpy / strncpy
    char buf1[50], buf2[50];
    strcpy(buf1, "Hello");
    mystrcpy(buf2, "Hello");
    if (strcmp(buf1, buf2) != 0) result = 0;

    char src[] = "ABCDE";
    char d1[10] = "XXXXXXXX";
    char d2[10] = "XXXXXXXX";
    strncpy(d1, src, 3);
    mystrncpy(d2, src, 3);
    if (memcmp(d1, d2, 10) != 0) result = 0;

    // strcat / strncat
    char c1[20] = "Hi";
    char c2[20] = "Hi";
    strcat(c1, " There");
    mystrcat(c2, " There");
    if (strcmp(c1, c2) != 0) result = 0;

    char d3[20] = "Hi";
    char d4[20] = "Hi";
    strncat(d3, "!!!", 2);
    mystrncat(d4, "!!!", 2);
    if (strcmp(d3, d4) != 0) result = 0;

    return result;
}

/* ---------- Comparison ---------- */
int testComparison() {
    int result = 1;

    if (strcmp("abc", "abd") != mystrcmp("abc", "abd")) result = 0;
    if (strcmp("abc", "abc") != mystrcmp("abc", "abc")) result = 0;
    if (strncmp("abcdef", "abcxyz", 3) != mystrncmp("abcdef", "abcxyz", 3)) result = 0;

    return result;
}

/* ---------- Search ---------- */
int testSearch() {
    int result = 1;

    char s[] = "This is a test string";

    if (strchr(s, 't') - s != mystrchr(s, 't') - s) result = 0;
    if (strrchr(s, 't') - s != mystrrchr(s, 't') - s) result = 0;
    if (strcspn(s, "xyz") != mystrcspn(s, "xyz")) result = 0;
    if (strpbrk(s, "aeiou") - s != mystrpbrk(s, "aeiou") - s) result = 0;
    if (strspn(s, "This ") != mystrspn(s, "This ")) result = 0;

    char *sub = "test";
    if (strcmp(strstr(s, sub), mystrstr(s, sub)) != 0) result = 0;

    // strtok
    char s1[] = "a,b,c";
    char s2[] = "a,b,c";
    char *t1 = strtok(s1, ",");
    char *t2 = mystrtok(s2, ",");
    while (t1 && t2) {
        if (strcmp(t1, t2) != 0) result = 0;
        t1 = strtok(NULL, ",");
        t2 = mystrtok(NULL, ",");
    }

    return result;
}

/* ---------- Memory functions ---------- */
int testMemory() {
    int result = 1;

    char s1[20] = "1234567890";
    char s2[20] = "1234567890";
    memcpy(s1 + 2, s1, 5);
    mymemcpy(s2 + 2, s2, 5);
    if (memcmp(s1, s2, 20) != 0) result = 0;

    char m1[20] = "abcdef";
    char m2[20] = "abcdef";
    memmove(m1 + 2, m1, 4);
    mymemmove(m2 + 2, m2, 4);
    if (memcmp(m1, m2, 20) != 0) result = 0;

    if (memcmp("abc", "abd", 3) != mymemcmp("abc", "abd", 3)) result = 0;

    if (memchr("hello", 'e', 5) != mymemchr("hello", 'e', 5)) result = 0;

    char x1[10], x2[10];
    memset(x1, 'A', 10);
    mymemset(x2, 'A', 10);
    if (memcmp(x1, x2, 10) != 0) result = 0;

    return result;
}

/* ---------- Other ---------- */
int testOther() {
    int result = 1;

    if (strlen("Hello") != mystrlen("Hello")) result = 0;

    for (int i = 0; i < 5; i++) {
        if (strcmp(strerror(i), mystrerror(i)) != 0) result = 0;
    }

    return result;
}

/* ---------- Main test runner ---------- */
int main() {
    printf("Running tests for mystring...\n");

    if (testCharFuncs()) printf("Character functions passed ✅\n");
    else printf("Character functions failed ❌\n");

    if (testConversion()) printf("Conversion functions passed ✅\n");
    else printf("Conversion functions failed ❌\n");

    if (testManipulation()) printf("String manipulation passed ✅\n");
    else printf("String manipulation failed ❌\n");

    if (testComparison()) printf("Comparison passed ✅\n");
    else printf("Comparison failed ❌\n");

    if (testSearch()) printf("Search functions passed ✅\n");
    else printf("Search functions failed ❌\n");

    if (testMemory()) printf("Memory functions passed ✅\n");
    else printf("Memory functions failed ❌\n");

    if (testOther()) printf("Other functions passed ✅\n");
    else printf("Other functions failed ❌\n");

    return 0;
}

