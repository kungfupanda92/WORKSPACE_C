#include <stdio.h>
#include <string.h>
int check_dx(char *in)
{
	int s_len = strlen(in);
	int half_len = s_len/2;

	for(int i=0; i<half_len; i++)
	{
		if(*(in+i) != *(in+s_len-i-1))
			return 0;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	char s_in[100];
	printf("Moi nhap chuoi: ");
	scanf("%s",s_in);
	if(check_dx(s_in))
		printf("Chuoi doi xung\n");
	else
		printf("eo doi xung\n");
	/* code */
	return 0;
}