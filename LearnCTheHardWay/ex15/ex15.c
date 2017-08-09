#include <stdio.h>
int main(int argc, char *argv[])
{
	//Create two arrays we care about
	int ages[] = {23, 15, 36, 9, 7};
	char *name []= {
		"Cody", "Alibaba",
		"FUCK", "Ngo", "NGUYEN"	
	};
	//Safely  get the size of ages
	int count= sizeof(ages)/sizeof(int);
	int i=0;
	//first way to using indexing
	for(i=0; i<count; i++){
		printf("%s has %d years alive.\n",name[i],ages[i]);
	}
	printf("----\n");
	//set up the pointer to start of the arrays
	int *cur_age = ages;
	char **cur_name = name;

	//secon way to using pointer
	for(i=0; i<count; i++){
		printf("%s has %d years alive.\n",*(cur_name+i), *(cur_age));
	}
	printf("----\n");
	//third way, pointers are just arrays
	for(i=0; i< count; i++){
		printf("%s has %d years alive.\n",cur_name[i],cur_age[i]);
	}
	printf("----\n");
	//forth way with pointers in a stupid conplex way
	// not using a count index i
	for(cur_age=ages, cur_name=name; cur_age-ages<count; cur_age++, cur_name++)
		printf("%s has %d years alive.\n",*(cur_name),*(cur_age));

	return 0;
}

