#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct MyHeader {
    unsigned short type;
    int flags;
    int size;
};

struct My {
    struct MyHeader h;
    char buf[];
};

__attribute__((visibility("hidden"))) struct My* grabMyStruct(int fd) {
    struct MyHeader h = {0};

    ssize_t sz = read(fd, &h, sizeof(struct MyHeader));
    if (sz != sizeof(struct MyHeader)) {
        return NULL;
    }

    struct My* my = (struct My*)malloc(sizeof(struct My) + h.size);
    memcpy(my, &h, sizeof(struct MyHeader));

    sz = read(fd, &my->buf, h.size);
    if (sz != h.size) {
        free(my);
        return NULL;
    }

    return my;
}
