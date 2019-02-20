#include <stdio.h>

int main() {
	int n = 1;
	void *memlocation = &n;
	printf("n address = %p\n", (void *) &n);
	printf("memlocation = %p\n", memlocation);
	printf("memlocation as int = %d\n", (int) memlocation);

	return 0;
}
