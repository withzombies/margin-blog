#include <stddef.h>

char *my_strncpy(char *restrict d, char *restrict s, size_t len)
{
    char *original_d = d;
    // copy up to len bytes
#pragma clang loop unroll(disable)
    while (len--) {
        *d++ = *s++;

        // Bailing after we copy the first NUL (\0) byte
        if (*d == 0) {
            break;
        }
    }

    return original_d;
}
