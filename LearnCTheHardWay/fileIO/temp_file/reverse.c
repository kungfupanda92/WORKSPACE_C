#include <stdio.h>
#include <stdlib.h>
#define CTRZ 0x32

int main(int argc, char *argv[])
{
	FILE *fd;
	char *name_file = "test.txt";
	int size_file;
	if((fd = fopen(name_file,"r")) == NULL)
	{
		printf("Can't open %s\n", name_file);
		return 1;
	}
	fseek(fd,0,SEEK_END);
	size_file = ftell(fd);


	printf("Reverse:");
	char ch;
	rewind(fd);
	for(int index=0; index < size_file; index++)
	{
		fseek(fd, 1, SEEK_CUR);
		// putchar(getc(fd));
		ch = getc(fd);
		if( ch != CTRZ && ch != '\r' && ch != '\n')
			putchar(ch);
	}	
	putchar('\n');

	fclose(fd);
	return 0;
}
