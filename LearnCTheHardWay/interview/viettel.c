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
#include <string.h>


FILE *fp;
FILE *fd;
typedef struct{
	int low_el;
	int high_el;
}collect_t;
typedef struct{
    int begin_series;
    int stop_series;
}series_number_t;
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
	// srand(time(NULL));
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
void create_random_array()
{
    fd = fopen("text.txt", "w");
    if(fd == NULL)
    {
        printf("Can't write file\n");
        return;
    }
    int N_random = create_random(10, 1000);
    int Neg_at_least_30 = (N_random*create_random(30,100))/100;
    series_number_t *series = (series_number_t *)malloc(N_random*sizeof(series_number_t));
    for(int i=0; i<N_random; ++i)
    {
        if(i<Neg_at_least_30)
        {
            series[i].begin_series = -rand();
            series[i].stop_series = rand();
        }
        else
        {
            series[i].begin_series = rand();
            series[i].stop_series = rand();
        }
    }
    //save file
    fprintf(fd,"%d\n", N_random);
    for(int i=0; i<N_random; ++i)
        fprintf(fd,"[%d ; %d]\n", series[i].begin_series,series[i].stop_series);
    fclose(fd);
}
void swap_number(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap_number(&arr[i], &arr[j]);
        }
    }
    swap_number(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void quick_sort(int *a,int left, int right)
{
    int i,j;
    int x;
    i = left; j = right;
    x = a[left];
    do{
        while(a[i]<x && i<right) i++;
        while(a[j]>x && j>left) j--;
        if(i<=j)
        {
            swap_number(&a[i], &a[j]);
            i++;j--;
        }
    }while(i<=j);
    if (left<j) quick_sort(a,left,j);
    if(i<right) quick_sort(a,i,right);
}
void _quick(int *a, int left, int right)
{
    int x;
    int i,j;
    //pick first element as pivot
    
    i = left;
    j = right;
    x = (a[left]+a[right])/2;
    do{
        while(a[i]<x && i<right) i++;
        while(a[j]>x && j>left) j--;
        if(i<=j)
        {
            swap_number(&a[i], &a[j]);
            i++; j--;
        }
    }while(i<=j);

    if(left<j) _quick(a,left,j);
    if(i<right) _quick(a,i,right);
}
void bubble_sort(int *a, int n)
{
    for(int i=0; i<n;++i)
    {
        for(int j=n-1; j>i;--j)
        {
            if(a[j]>a[j-1])
            {
                swap_number(&a[j], &a[j-1]);
            }
        }
    }
}
void select_sort(int *a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min = a[i];
        int p_min = i;
        for(int j=i+1; j<n; ++j)
            if(min > a[j])
            {
                min = a[i];
                p_min = j;
            }
        if(p_min != i)
            swap_number(&a[i],&a[p_min]);

    }
}
void bubble_sort_series(int *a, int *b, int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j = n-1; j>i; --j)
        {
            if(a[j]<a[j-1])
            {
                swap_number(&a[j],&a[j-1]);
                swap_number(&b[j],&b[j-1]);
            }
        }
    }
}
void sort_series_nunber()
{
    fp = fopen("doc.txt", "r");
    if( fp == NULL)
        return;
    int N_number;
    fscanf(fp, "%d",&N_number);
    int *begin_array = (int *)malloc(N_number * sizeof(int));
    int *end_array = (int *)malloc(N_number * sizeof(int));
    char str[100];
    for(int i=0;i<N_number;i++)
	{
		fscanf(fp,"%s",str);
		sscanf(str,"(%d;%d)",&begin_array[i],&end_array[i]);
	}
    for(int i = 0; i< N_number; ++i)
    {
        printf("(%d;%d)\n", begin_array[i],end_array[i]);
    }
    bubble_sort_series(begin_array,end_array,N_number);
    printf("\n After sorting\n");
    for(int i = 0; i< N_number; ++i)
    {
        printf("(%d;%d)\n", begin_array[i],end_array[i]);
    }
    printf("\n After remove overlap\n");
    printf("(%d;%d)\n", begin_array[0],end_array[0]);
    for(int i = 1; i< N_number; ++i)
    {
        if(begin_array[i]>=end_array[i-1])
            printf("(%d;%d)\n", begin_array[i],end_array[i]);
    }
    fclose(fp);
}
int main()
{

    // int array[] = {1,6,3,2,7};
    // _quick(array,0,4);
    // for(int i=0; i<5; ++i)
    //     printf("%d ", array[i]);
	// process();
    // create_random_array();
    sort_series_nunber();
    // createFile();
    return 0;
    // createFile();        
}
