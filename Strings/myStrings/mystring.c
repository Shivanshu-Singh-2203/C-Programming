/**
 * mystring.c
 *
 * Custom implementations of C standard library functions.
 * All functions are prefixed with "my" to avoid conflicts.
 *
 * NOTE: Only mystrlen1 is fully implemented here.
 *       Other functions are left as stubs for you to implement.
 */

#include "mystring.h"

/* ---------- Character handling ---------- */

/**
 * @brief Check if character is a digit [0–9].
 * @param c character to check
 * @return nonzero if digit, 0 otherwise
 */
int myisdigit(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is alphabetic [A–Z, a–z].
 */
int myisalpha(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is alphanumeric [0–9, A–Z, a–z].
 */
int myisalnum(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is a hexadecimal digit [0–9, a–f, A–F].
 */
int myisxdigit(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is lowercase.
 */
int myislower(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is uppercase.
 */
int myisupper(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Convert uppercase to lowercase, else return unchanged.
 */
int mytolower(int c) {
    // TODO: implement
    return c;
}

/**
 * @brief Convert lowercase to uppercase, else return unchanged.
 */
int mytoupper(int c) {
    // TODO: implement
    return c;
}

/**
 * @brief Check if character is a whitespace (space, tab, newline, etc.).
 */
int myisspace(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is a control character.
 */
int myiscntrl(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is punctuation.
 */
int myispunct(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character is printable (including space).
 */
int myisprint(int c) {
    // TODO: implement
    return 0;
}

/**
 * @brief Check if character has a graphical representation (not space).
 */
int myisgraph(int c) {
    // TODO: implement
    return 0;
}

/* ---------- String conversion ---------- */

/**
 * @brief Convert string to double.
 * @param nptr input string
 * @param endptr pointer to the character where conversion stopped
 */
double mystrtod(const char *nptr, char **endptr) {
    // TODO: implement
    return 0.0;
}

/**
 * @brief Convert string to long.
 */
long mystrtol(const char *nptr, char **endptr, int base) {
    // TODO: implement
    return 0;
}

/**
 * @brief Convert string to unsigned long.
 */
unsigned long mystrtoul(const char *nptr, char **endptr, int base) {
    // TODO: implement
    return 0;
}

/* ---------- String manipulation ---------- */

/**
 * @brief Copy string src into dest.
 */
char *mystrcpy(char *dest, const char *src) {
    // TODO: implement
    return dest;
}

/**
 * @brief Copy at most n characters from src into dest.
 */
char *mystrncpy(char *dest, const char *src, size_t n) {
    // TODO: implement
    return dest;
}

/**
 * @brief Append string src to the end of dest.
 */
char *mystrcat(char *dest, const char *src) {
    // TODO: implement
    return dest;
}

/**
 * @brief Append at most n characters from src to the end of dest.
 */
char *mystrncat(char *dest, const char *src, size_t n) {
    // TODO: implement
    return dest;
}

/* ---------- Comparison ---------- */

/**
 * @brief Compare two strings lexicographically.
 * @return 0 if equal, <0 if s1<s2, >0 if s1>s2
 */
int mystrcmp(const char *s1, const char *s2) {
    // TODO: implement
    return 0;
}

/**
 * @brief Compare at most n characters of two strings.
 */
int mystrncmp(const char *s1, const char *s2, size_t n) {
    // TODO: implement
    return 0;
}

/* ---------- Search ---------- */

/**
 * @brief Locate first occurrence of c in string s.
 */
char *mystrchr(const char *s, int c) {
    // TODO: implement
    return NULL;
}

/**
 * @brief Get length of initial segment of s consisting of chars not in reject.
 */
size_t mystrcspn(const char *s, const char *reject) {
    // TODO: implement
    return 0;
}

/**
 * @brief Locate first occurrence in s of any char from accept.
 */
char *mystrpbrk(const char *s, const char *accept) {
    // TODO: implement
    return NULL;
}

/**
 * @brief Locate last occurrence of c in string s.
 */
char *mystrrchr(const char *s, int c) {
    // TODO: implement
    return NULL;
}

/**
 * @brief Get length of initial segment of s consisting only of chars in accept.
 */
size_t mystrspn(const char *s, const char *accept) {
    // TODO: implement
    return 0;
}

/**
 * @brief Locate first occurrence of substring needle in haystack.
 */
char *mystrstr(const char *haystack, const char *needle) {
    // TODO: implement
    return NULL;
}

/**
 * @brief Tokenize string using delimiter characters.
 */
char *mystrtok(char *str, const char *delim) {
    // TODO: implement
    return NULL;
}

/* ---------- Memory functions ---------- */

/**
 * @brief Copy n bytes from src to dest.
 */
void *mymemcpy(void *dest, const void *src, size_t n) {
    // TODO: implement
    return dest;
}

/**
 * @brief Move n bytes from src to dest (safe for overlap).
 */
void *mymemmove(void *dest, const void *src, size_t n) {
    // TODO: implement
    return dest;
}

/**
 * @brief Compare n bytes of memory areas.
 */
int mymemcmp(const void *s1, const void *s2, size_t n) {
    // TODO: implement
    return 0;
}

/**
 * @brief Locate first occurrence of c in memory area.
 */
void *mymemchr(const void *s, int c, size_t n) {
    // TODO: implement
    return NULL;
}

/**
 * @brief Fill memory with constant byte.
 */
void *mymemset(void *s, int c, size_t n) {
    // TODO: implement
    return s;
}

/* ---------- Other ---------- */

/**
 * @brief Return string describing error number.
 */
char *mystrerror(int errnum) {
 	
    return "Unknown error";
}

/**
 * @brief Get length of string s.
 * 
 * @param s pointer to null-terminated string
 * @return number of characters before '\0'
 */
size_t mystrlen1(const char *s) {
    /* Fully implemented */
    size_t len = 0;
    while (s && *s != '\0') {
        len++;
        s++;
    }
    return len;
}
