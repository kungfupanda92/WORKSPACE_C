#include <stdio.h>


int main(int argc, char const *argv[])
{
	/* code */
	FILE *fd;
	fd = fopen("file.txt", "w");
	fprintf(fd, "hello baby\n");

	fclose(fd);

	return 0;
}