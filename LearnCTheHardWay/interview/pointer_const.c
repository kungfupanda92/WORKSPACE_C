#include <stdio.h>

int main(int argc, char *argv[])
{
	// const int the same int const
	const int a = 10;
	int b = 10;

	int const  *ptr1 = &a;     // ptr is a pointer to constant int 
	// const int *ptr1 = &a;      // the same int const  *ptr1

	ptr1++;
	// *ptr1 = 0; 	wrong
	

	int *const ptr2 =&b; // ptr is a constant pointer to int
	// ptr2++; 		wrong
	*ptr2 = 1;


	// const int *const ptr = &a;
	int const *const ptr = &a;
	// ptr++; 		wrong
	// *ptr = 0; 	wrong
}
