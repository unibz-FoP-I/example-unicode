#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utf8.h"

int compare_str(const void *s1, const void *s2) {
    const char *arg1 = *(const char **)s1;
    const char *arg2 = *(const char **)s2;
    return strcmp(arg1, arg2);
}

void sortLines(char **lines, size_t size) {
    qsort(lines, size, sizeof(char*), compare_str);
}

int compare_utf(const void *s1, const void *s2) {
    const char *arg1 = *(const char **)s1;
    const char *arg2 = *(const char **)s2;
    return utf8cmp(arg1, arg2);
}

void sortUTFLines(char **lines, size_t size) {
    qsort(lines, size, sizeof(char*), compare_utf);
}