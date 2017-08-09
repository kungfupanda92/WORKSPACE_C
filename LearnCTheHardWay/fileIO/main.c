#include <stdio.h>
#include <string.h>

void clear_file(const char *filename)
{ 
    FILE *output = fopen(filename, "w");
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

int main(int argc, char *argv[])
{
    char *name_file = argv[2];

    if(strcmp(argv[1],"-w")==0)
        for(int i=0; i<10;++i )
            write_IO(name_file, i);
    else if(strcmp(argv[1],"-r")==0)
        read_IO(name_file);
    else
        clear_file(name_file);

    return 0;
}