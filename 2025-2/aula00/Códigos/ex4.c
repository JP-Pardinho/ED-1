#include <stdio.h>

int main(){
	int *p1;
	*p1 = 10;
	printf("End. p1 = %p\n", &p1);
	printf("End. apontado por p1 = %p\n", p1);
	printf("Valor do end. apontado por p1 = %d\n", *p1);
	return 0;
}