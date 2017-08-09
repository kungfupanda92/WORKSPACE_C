/*
 ============================================================================
 Name        : prj.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

FILE *fp;
typedef struct{
	int low_el;
	int high_el;
}collect_t;
int create_random(int a, int b)
{
	return (rand() % (b - a)) + a;
}
int checkOverlap(collect_t first, collect_t second)
{
	if((second.high_el<=first.low_el)&& (second.low_el<first.low_el))
		return 1;
	if((second.low_el>=first.high_el)&& (second.high_el>first.high_el))
		return 1;
	return 0;
}
void process(void)
{
	fp = fopen("doc.txt", "r");
	int n;
	int i,
		j,
		k,
		maxSize,
		sizeListTemp;
	collect_t *array;
	fscanf(fp,"%d",&n);
	array = (collect_t*)malloc(n*sizeof(collect_t));
	char str[256];
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",str);
		sscanf(str,"(%d;%d)",&array[i].low_el, &array[i].high_el);
	}
	for(i=0;i<n;i++)
	{
		printf("(%d;%d)\n",array[i].low_el,array[i].high_el);
	}
	collect_t *listMax = (collect_t*)malloc(n*sizeof(collect_t));
	collect_t *listTemp = (collect_t*)malloc(n*sizeof(collect_t));
	for(i=0;i<n;i++)
	{
		listTemp[0].high_el = array[i].high_el;
		listTemp[0].low_el = array[i].low_el;
		sizeListTemp = 1;
		for(j = i; j< n; j++)
		{
			int flag = 0;
			for(k = 0;k < sizeListTemp;k++)
			{
				if (!((j!=i)&&(checkOverlap(array[j],listTemp[k]))))
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				//add
				listTemp[sizeListTemp].high_el = array[j].high_el;
				listTemp[sizeListTemp].low_el = array[j].low_el;
				sizeListTemp++;
			}
		}
		if(sizeListTemp > maxSize)
		{
			maxSize = sizeListTemp;
			memcpy(listMax, listTemp,maxSize*sizeof(collect_t));
		}
	}
	printf("asdkfljaskdfjalskdf\n");
	for(i=0;i<maxSize;i++)
	{
		printf("(%d;%d)\n",listMax[i].low_el,listMax[i].high_el);
	}
	fclose(fp);
}

int createFile(void) {
	srand(time(NULL));
	fp = fopen("doc.txt", "w");
	int _N = create_random(10,1000);
	int i,
		n30;
	fprintf(fp,"%d\n ", _N);
//	_N = 10;
	n30 = (int)_N/3;
	collect_t *array = (collect_t *)malloc(_N*sizeof(collect_t));
	for(i=0;i<n30;i++)
	{
		array[i].low_el = -1*(rand()%100);
		array[i].high_el = rand()%100;
	}
	for(i=n30; i<_N; i++)
	{
		int temp;
		array[i].low_el = (rand()%100);
		array[i].high_el = rand()%100;
		if(array[i].high_el< array[i].low_el)
		{
			temp = array[i].high_el;
			array[i].high_el = array[i].low_el;
			array[i].low_el = temp;
		}
	}

	for(i=0;i<_N;i++)
	{
		fprintf(fp,"(%d;%d)\n",array[i].low_el,array[i].high_el);
	}
	fclose(fp);
	return EXIT_SUCCESS;
}
int main()
{
	process();
}
