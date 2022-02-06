ALL:
	$(CC) -o data-not-operations.so data-not-operations.c -Wall -Wshadow -Wextra -Wconversion -std=c11 -O2 -fomit-frame-pointer -shared
	strip -s data-not-operations.so
	$(CC) -o data-shape.so data-shape.c -Wall -Wshadow -Wextra -Wconversion -std=c11 -O2 -fomit-frame-pointer -shared
	strip -s data-shape.so
	clang -o memcpy.dylib -shared my_memcpy.c -Wall -Wshadow -Wextra -O2 -fno-builtin -fno-slp-vectorize -mno-sse
	clang -o strncpy.dylib -shared my_strncpy.c -Wall -Wshadow -Wextra -O2 -fno-builtin -fno-slp-vectorize -mno-sse
