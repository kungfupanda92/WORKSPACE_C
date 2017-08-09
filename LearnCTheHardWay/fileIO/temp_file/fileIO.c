#include <stdio.h>
#include <stdlib.h>

#define MAX 41
#define CNTL_Z '\032' /* eof marker in DOS text files */
#define SLEN 81

int check_count_file(int argc, char *argv[]);
void update_file(void);
void reverse_file_string(void);
void stream_to_buffer();

int main(int argc, char *argv[])
{
	/*---------------------------------------------*/
	// if(check_count_file(argc, argv))
	// 	exit(EXIT_FAILURE);
	/*---------------------------------------------*/
	// update_file();
	// reverse_file_string();
	stream_to_buffer();
	/*---------------------------------------------*/
	return 0;
}
void stream_to_buffer(void)
{
	FILE *pfile;
	int ret_size,size_file;
	char *file_name = "test.bin";
	if((pfile = fopen(file_name,"rb+")) == NULL)
		return;
	//obtain file size
	fseek(pfile, 0, SEEK_END);
	size_file = ftell(pfile);
	rewind(pfile);//go to start file
	// allocate memory to contain the whole file
	char *buffer = malloc(size_file*sizeof(char));
	if(buffer == NULL){
		printf("Unable allocate file\n");
		return;
	}
	//copy file
	ret_size = fread(buffer, 1, size_file, pfile);
	if(ret_size != size_file){
		printf("fread error\n");
		return;
	}
	printf("buffer is: %s\n", buffer);

	fclose(pfile);
	free(buffer);
}

void reverse_file_string(void)
{
	char file[SLEN];
	char ch;
	FILE *fd;
	long count, size_file;

	puts("Enter the name of the file to be processed:");
	scanf("%80s", file);
	if((fd = fopen(file, "rb")) == NULL)
	{
		printf("reverse can't open file\n");
		return;
	}
	/*printf the content of file*/
	// while((ch = getc(fd)) != EOF)
	// 	putchar(ch);
	fgets(file,SLEN,fd);
	printf("content file is %s", file);
	rewind(fd);/*go to begin file*/
	/*printf the content of file*/
	// while((ch = getc(fd)) != EOF)
	// 	putchar(ch);
	//obtain file size
	fseek(fd, 0, SEEK_END); /*go to end of file*/
	size_file = ftell(fd);
	for(count = 1L; count <= size_file; count++)
	{
		fseek(fd, -count, SEEK_END); /*go backward*/
		ch = getc(fd);
		if(ch != CNTL_Z && ch != '\r') /*MS-DOS files*/
			putchar(ch);
	}
	putchar('\n');
	fclose(fd);
	return;
}

void update_file(void)
{
	FILE *fd;
	char ch;
	char *file_name = "test.txt";
	if((fd = fopen(file_name, "r")) == NULL)
	{
		printf("Can't open %s\n", file_name);
		return;
	}
	printf("Content of %s is:\n", file_name);
	while((ch = getc(fd)) != EOF)
		putchar(ch);
}
int check_count_file(int argc, char *argv[])
{
	FILE *fd;
	int count=0;
	char ch;

	printf("Argument count is %d\n", argc);
	if(argc != 2)
	{
		printf("Argument is not enough\n");
		return 1;

	}
	if((fd = fopen(argv[1],"r")) == NULL)
	{
		printf("Can't open %s file", argv[0]);
		return 1;
	}
	while((ch = getc(fd)) != EOF)
	{
		putc(ch, stdout);
		count ++;
	}
	printf("Count is %d\n", count);
	return 0;
}