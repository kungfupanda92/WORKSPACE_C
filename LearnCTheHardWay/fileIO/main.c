#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void clear_file(const char *filename)
{ 
    FILE *output = fopen(filename, "w");
    fclose(output);
}
void create_new_file(const char *filename)
{
    FILE *output = fopen(filename, "a");
    fclose(output);
}

void write_IO(char *name,int data)
{
    FILE *pfile;
    pfile = fopen(name,"a+");
    if(pfile == NULL)
    {
        printf("%s can't open file\n", __FUNCTION__);
        return;
    }
    // fwrite(&data, sizeof(int), 1, pfile);
    fprintf(pfile,"%d\n", data);
    fclose(pfile);
}
void read_IO(char *name)
{
    FILE *pfile;
    pfile = fopen(name,"a+");
    if(pfile == NULL)
    {
        printf("%s can't open file", __FUNCTION__);
        return;
    }
    int data;
    for(int i=0; i<10; ++i)
    {
        // fread(&data, sizeof(int), 1, pfile);
        fscanf(pfile,"%d",&data);
        printf("Data: %d\n", data);
    }
    fclose(pfile);
    clear_file(name);
}
int remove_oldest_int(char *name)
{
    FILE *pfile,*ptem;
    pfile = fopen(name,"a+");
    ptem = fopen("temp.txt","w");
    int size = 10;

    int data,olest_data,length;
    fscanf(pfile,"%d",&length);
    if(length == 0)
    {
        printf("file is empty\n");
        return 0;
    }
    fprintf(ptem,"%d\n",length-1);

    fscanf(pfile,"%d",&olest_data);
    for(int i=1; i<length;i++)
    {
        fscanf(pfile,"%d",&data);
        fprintf(ptem,"%d\n",data);
    }

    rename("temp.txt", name);
    fclose(pfile);
    fclose(ptem);
    return olest_data;
}

int main(int argc, char *argv[])
{
    
    int opt;


    while((opt = getopt(argc, argv, ":e:r:w:t:c")) != -1)
    {
        switch(opt){
            case 'e': 
                printf("earase\n");
                clear_file(optarg);
                break;
            case 't':
                printf("trumcate_file\n");
                int ret = remove_oldest_int(optarg);
                printf("oldest : %d\n",ret);
                break;
            case 'r':
                printf("filename %s\n", optarg);
                read_IO(optarg);
                break;
            case 'w':
                printf("filename %s\n", optarg);
                int length = 10;
                write_IO(optarg,length);
                for(int i=0; i<10;i++ )
                    write_IO(optarg, i);
                break;
            case 'c':
                create_new_file("./fuckyou.txt");
        }
    }

    return 0;
}