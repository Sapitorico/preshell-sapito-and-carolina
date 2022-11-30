#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *p;
	size_t n;
	size_t zipo;

	printf("$");
	zipo = getline(&p, &n, stdin);
	printf("%zu characters were read.\n", zipo);
	
	return (0);

}
