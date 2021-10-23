#ifndef _STRING_H
#define _STRING_H

#define __need_size_t
#define __need_NULL

#include <stddef.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

void *memcpy(void *, const void *, size_t);

void *memmove(void *, const void *, size_t);

char *strcpy(char *, const char *);

char *strncpy(char *, const char *, size_t);

char *strcat(char *, const char *);

char *strncat(char *, const char *, size_t);

int memcmp(const void *, const void *, size_t);

int strcmp(const char *, const char *);

int strcoll(const char *, const char *);

int strncmp(const char *, const char *, size_t);

size_t strxfrm(char *, const char *, size_t);

void *memchr(const void *, int, size_t);

char *strchr(const char *, int);

size_t strcspn(const char *, const char *);

char *strpbrk(const char *, const char *);

char *strrchr(const char *, int);

size_t strspn(const char *, const char *);

char *strstr(const char *, const char *);

char *strtok(char *, const char *);

void *memset(void *, int, size_t);

char *strerror(int);

size_t strlen(const char *);

__END_DECLS

#endif /* _STRING_H */
