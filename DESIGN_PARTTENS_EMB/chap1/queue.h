#ifndef __QUEUE_H__
#define __QUEUE_H__

#define QUEUE_SIZE 10
/* class queue*/
typedef struct queue queue_t;
struct queue
{
	/* attributes */
	int size;
	int head;
	int tail;
	int buffer[QUEUE_SIZE];
	
	int (*is_full)(queue_t *const me);
	int (*is_empty)(queue_t *const me);
	int (*get_size)(queue_t *const me);
	void (*insert)(queue_t *const me, int k);
	int (*remove)(queue_t *const me);
	void (*debug)(queue_t *const me);
};

/*constructors and destructors*/
void queue_init(queue_t *const me,
	int (*fun_is_full)(queue_t *const me),
	int (*fun_is_empty)(queue_t *const me),
	int (*fun_get_size)(queue_t *const me),
	void (*fun_insert)(queue_t *const me, int k),
	int (*fun_remove)(queue_t *const me),
	void (*debug_queue)(queue_t *const me));

void queue_cleanup(queue_t *const me);

/* operations */
int queue_is_full(queue_t *const me);
int queue_is_empty(queue_t *const me);
int queue_get_size(queue_t *const me);
void queue_insert(queue_t *const me, int k);
int queue_remove(queue_t *const me);
void queue_debug(queue_t *const me);

queue_t *queue_create(void);
void queue_destroy(queue_t *const me);
#endif