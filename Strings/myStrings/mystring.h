/**
 * mystring.h
 *
 * Custom implementations of C standard library functions.
 * Function names are prefixed with "my" to avoid conflicts.
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>  // for size_t

/* ---------- Character handling ---------- */
int myisdigit(int c);
int myisalpha(int c);
int myisalnum(int c);
int myisxdigit(int c);
int myislower(int c);
int myisupper(int c);
int mytolower(int c);
int mytoupper(int c);
int myisspace(int c);
int myiscntrl(int c);
int myispunct(int c);
int myisprint(int c);
int myisgraph(int c);

/* ---------- String conversion ---------- */
double mystrtod(const char *nptr, char **endptr);
long mystrtol(const char *nptr, char **endptr, int base);
unsigned long mystrtoul(const char *nptr, char **endptr, int base);

/* ---------- String manipulation ---------- */
char *mystrcpy(char *dest, const char *src);
char *mystrncpy(char *dest, const char *src, size_t n);
char *mystrcat(char *dest, const char *src);
char *mystrncat(char *dest, const char *src, size_t n);

/* ---------- Comparison ---------- */
int mystrcmp(const char *s1, const char *s2);
int mystrncmp(const char *s1, const char *s2, size_t n);

/* ---------- Search ---------- */
char *mystrchr(const char *s, int c);
size_t mystrcspn(const char *s, const char *reject);
char *mystrpbrk(const char *s, const char *accept);
char *mystrrchr(const char *s, int c);
size_t mystrspn(const char *s, const char *accept);
char *mystrstr(const char *haystack, const char *needle);
char *mystrtok(char *str, const char *delim);

/* ---------- Memory functions ---------- */
void *mymemcpy(void *dest, const void *src, size_t n);
void *mymemmove(void *dest, const void *src, size_t n);
int mymemcmp(const void *s1, const void *s2, size_t n);
void *mymemchr(const void *s, int c, size_t n);
void *mymemset(void *s, int c, size_t n);

/* ---------- Other ---------- */
char *mystrerror(int errnum);
size_t mystrlen(const char *s);   // note: renamed to avoid clash with strlen

#endif // MYSTRING_H

