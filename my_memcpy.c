#include <stddef.h>

void *my_memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
    char *dst = s1;
    const char *src = s2;

#pragma clang loop unroll(disable)
    while (n--) {
        *dst++ = *src++;
    }

    return s1;
}
