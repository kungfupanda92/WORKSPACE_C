#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"
#include "queue.h"
#include "cached_queue.h"

void test_sensor();
void test_queue();
void test_cached_queue();
int main(int argc, char const *argv[])
{
	// test_sensor();
	// test_queue();
	test_cached_queue();

	return 0;
}
void test_cached_queue()
{
	int j, k, h, t;

	printf("%s\n", __FUNCTION__);
	cached_queue_t	*myCachedQ;
	myCachedQ = cached_queue_create();
	printf("-----------WRITE--------------\n");
	k = 1000;
	for(j = 0; j<3*QUEUE_SIZE+5; ++j)
	{
		myCachedQ->insert(myCachedQ, k);
		printf("inserting %d , size %d \n",k--, myCachedQ->get_size(myCachedQ));
	}
	printf("-----------READ--------------\n");
	for(j = 0; j<2*QUEUE_SIZE; j++)
	{
		k = myCachedQ->remove(myCachedQ);
		printf("REMOVING %d, size = %d\n", k , myCachedQ->get_size(myCachedQ));
	}
	printf("-----------DEBUG--------------\n");
	myCachedQ->debug(myCachedQ);
}
void test_queue()
{
	/* code */
	int j, k, h, t;

	/*test normal queue */
	queue_t *myQ;
	myQ = queue_create();
	k = 1000;
	for(j = 0; j<QUEUE_SIZE; ++j)
	{
		h = myQ->head;
		myQ->insert(myQ, k);
		printf("inserting %d at position %d, size %d \n",k--, h, myQ->get_size(myQ));
	}
	printf("Inserted %d elements\n", myQ->get_size(myQ));
	for(j = 0; j<QUEUE_SIZE; j++)
	{
		t = myQ->tail;
		k = myQ->remove(myQ);
		printf("REMOVING %d at position %d, size = %d\n", k, t, myQ->get_size(myQ));
	}

	printf("Last item removed = %d\n", k);
	printf("Current queue size %d\n",myQ->get_size(myQ));
	k = 1000;
	for(j = 0; j<5; j++)
	{
		h = myQ->head;
		myQ->insert(myQ,k);
		printf("Inserting %d at position %d, size %d \n", k--, h, myQ->get_size(myQ));
	}

	puts("QUEUE TEST PROGRAN");
}
void test_sensor()
{
	sensor_t *p_sensor0, *p_sensor1;
	p_sensor0 = sensor_create();
	p_sensor1 = sensor_create();

	/* do stuff with the sensors ere*/
	p_sensor0->value = 99;
	p_sensor1->value = -1;
	printf("The current value from sensor0 is %d\n",
			sensor_getValue(p_sensor0));
	printf("The current value from sensor1 is %d\n",
			sensor_getValue(p_sensor1));
	/* done with sensors */
	sensor_destroy(p_sensor0);
	sensor_destroy(p_sensor1);
}
