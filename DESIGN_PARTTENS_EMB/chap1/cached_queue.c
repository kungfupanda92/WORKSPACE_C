#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "cached_queue.h"

FILE * pfile;
static void clear_file(const char *filename);
static int remove_oldest_int(char *name, int size_file);

/*constructors and destructors*/
void cached_queue_init(cached_queue_t *const me, char *name,
            int (*isFull)(cached_queue_t *const me),
            int (*isEmpty)(cached_queue_t *const me),
            int (*getSize)(cached_queue_t *const me),
            void (*insert_fun)(cached_queue_t *const me, int k),
            int (*remove_fun)(cached_queue_t *const me),
            void (*flush_fun)(cached_queue_t *const me),
            void (*load_fun)(cached_queue_t *const me),
            void (*debug_fun)(cached_queue_t *const me))
{
    /* Initialize base class */
    me->queue = queue_create(); /* queue memer must be use it original functions*/
    /* Initialize subclass attributes*/
    me->numberElementsOnDisk = 0;
    strcpy(me->filename, name);
    /* initialize aggregates*/
    me->output_queue = queue_create();

    /* initialize subclass virtual operations ptrs*/
    me->is_full = isFull;
    me->is_empty = isEmpty;
    me->get_size = getSize;
    me->insert = insert_fun;
    me->remove = remove_fun;
    me->flush = flush_fun;
    me->load = load_fun;
    me->debug = debug_fun;
}


void cached_queue_cleanup(cached_queue_t *const me)
{
    queue_cleanup(me->queue);
}
/*Operations*/
int cached_queue_is_full(cached_queue_t *const me)
{
    return me->queue->is_full(me->queue) &&
           me->output_queue->is_full(me->output_queue);
}
int cached_queue_is_empty(cached_queue_t *const me)
{
    return me->queue->is_empty(me->queue) &&
           me->output_queue->is_empty(me->output_queue) &&
           (me->numberElementsOnDisk == 0);
}
int cached_queue_get_size(cached_queue_t *const me)
{
    return me->queue->get_size(me->queue) +
           me->output_queue->get_size(me->output_queue) +
           me->numberElementsOnDisk;
}
void cached_queue_insert(cached_queue_t *const me, int k)
{
    if(me->queue->is_full(me->queue)) me->flush(me);
    me->queue->insert(me->queue, k);
}
int cached_queue_remove(cached_queue_t *const me)
{
    int value = -9999; //sential value
    if(!(me->output_queue->is_empty(me->output_queue)))
        return me->output_queue->remove(me->output_queue);
    else if(me->numberElementsOnDisk > 0)
    {
        me->load(me);
        return me->output_queue->remove(me->output_queue);
        // return me->queue->remove(me->queue);
    }
    else
        return me->queue->remove(me->queue);
}
void cache_queue_flush(cached_queue_t *const me)
{
    //write file I/O statement here
    pfile = fopen(me->filename,"a+");
    if(pfile == NULL)
    {
        printf("%s can't open file\n", __FUNCTION__);
        return;
    }
    while(!(me->queue->is_empty(me->queue)))
    {
        int data = me->queue->remove(me->queue);
        // fwrite(data, sizeof(int), 1, pfile);
        fprintf(pfile,"%d\n", data);
        ++me->numberElementsOnDisk;
    }
    fclose(pfile);
}
static void clear_file(const char *filename)
{ 
    FILE *output = fopen(filename, "w");
    fclose(output);
}
static int remove_oldest_int(char *name, int size_file)
{
    FILE *pfile,*ptem;
    pfile = fopen(name,"a+");
    ptem = fopen("temp.txt","w");
    int size = 10;

    int data,olest_data;


    fscanf(pfile,"%d",&olest_data);
    for(int i=1; i<size_file;i++)
    {
        fscanf(pfile,"%d",&data);
        fprintf(ptem,"%d\n",data);
    }

    rename("temp.txt", name);
    fclose(pfile);
    fclose(ptem);
    return olest_data;
}
void cached_queue_load(cached_queue_t *const me)
{
    //write file I/O statement here
    while(!(me->output_queue->is_full(me->output_queue)) && (me->numberElementsOnDisk > 0))
    {   
        int data = remove_oldest_int(me->filename, me->numberElementsOnDisk);
        --me->numberElementsOnDisk;
        me->output_queue->insert(me->output_queue,data);
    }
}
void cached_queue_debug(cached_queue_t *const me)
{
    me->queue->debug(me->queue);
    me->output_queue->debug(me->output_queue);
    if(me->numberElementsOnDisk >0)
    {
        int data;
        FILE *pfile;
        pfile = fopen(me->filename,"r");
        for(int i=0; i<me->numberElementsOnDisk;i++)
        {
            fscanf(pfile,"%d",&data);
            printf("%d\n",data);
        }
    }

}
cached_queue_t* cached_queue_create(void)
{
    cached_queue_t *me = (cached_queue_t *)malloc(sizeof(cached_queue_t));
    if(me != NULL)
    {
        cached_queue_init(me,
        "./fuckyou.txt",
        cached_queue_is_full,
        cached_queue_is_empty,
        cached_queue_get_size,
        cached_queue_insert,
        cached_queue_remove,
        cache_queue_flush,
        cached_queue_load,
        cached_queue_debug);
    }
    
    clear_file(me->filename);
    return me;
}
void cache_queue_destroy(cached_queue_t *const me)
{
    if(me != NULL)
        cached_queue_cleanup(me);
    
    free(me);
}