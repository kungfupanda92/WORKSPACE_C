#ifndef __CACHED_QUEUE_H__
#define __CACHED_QUEUE_H__

#include "queue.h"
typedef struct cached_queue cached_queue_t;
struct cached_queue
{
    queue_t *queue; /*base class*/
    /*new attributes */
    char filename[80];

    int numberElementsOnDisk;
    /* aggregation in subclass*/
    queue_t *output_queue;
    /* inherited virtual functions */
	int (*is_full)(cached_queue_t *const me);
	int (*is_empty)(cached_queue_t *const me);
	int (*get_size)(cached_queue_t *const me);
	void (*insert)(cached_queue_t *const me, int k);
	int (*remove)(cached_queue_t *const me);
    void (*debug)(cached_queue_t *const me);
    /*new virtual functions*/
    void (*flush)(cached_queue_t *const me);
    void (*load)(cached_queue_t *const me);
};
/*constructors and destructors*/
void cached_queue_init(cached_queue_t *const me, char *name,
            int (*isFull)(cached_queue_t *const me),
            int (*isEmpty)(cached_queue_t *const me),
            int (*getSize)(cached_queue_t *const me),
            void (*insert_fun)(cached_queue_t *const me, int k),
            int (*remove_fun)(cached_queue_t *const me),
            void (*flush_fun)(cached_queue_t *const me),
            void (*load_fun)(cached_queue_t *const me),
            void (*debug_fun)(cached_queue_t *const me));

void cached_queue_cleanup(cached_queue_t *const me);
/*Operations*/
int cached_queue_is_full(cached_queue_t *const me);
int cached_queue_is_empty(cached_queue_t *const me);
int cached_queue_get_size(cached_queue_t *const me);
void cached_queue_insert(cached_queue_t *const me, int k);
int cached_queue_remove(cached_queue_t *const me);
void cache_queue_flush(cached_queue_t *const me);
void cached_queue_load(cached_queue_t *const me);
void cached_queue_debug(cached_queue_t *const me);

cached_queue_t* cached_queue_create(void);
void cache_queue_destroy(cached_queue_t *const me);

#endif /*CACHED_QUEUE_H*/