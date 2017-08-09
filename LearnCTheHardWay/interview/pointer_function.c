#include <stdio.h>

int addInt(int n, int m)
{
	return n+m;
}

int main(int argc, char *argv[])
{
	/* Method1: poiter to function*/
	int (*functionPtr)(int,int); //define a pointer to a function
	functionPtr = &addInt;
	int sum_m1 = functionPtr(2,3);
	printf("sum_m1: %d\n", sum_m1);


	/* Method2: using typedef*/
	typedef int (*myFunction)(int,int);
	int sum_m2 = (*(myFunction) addInt)(2,3);
	printf("sum_m2: %d\n",sum_m2);
	return 0;	
}
