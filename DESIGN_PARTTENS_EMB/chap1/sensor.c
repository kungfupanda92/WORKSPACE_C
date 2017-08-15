#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

void sensor_init(sensor_t *const me)
{
	printf("%s\n", __FUNCTION__);
}
void sensor_cleanup(sensor_t *const me)
{
	printf("%s\n", __FUNCTION__);
}

sensor_t *sensor_create(void)
{
	sensor_t *me = (sensor_t *) malloc(sizeof(sensor_t));
	if(me != NULL)
		sensor_init(me);
	return me;
}
void sensor_destroy(sensor_t *const me)
{
	if(me != NULL)
		sensor_cleanup(me);
	free(me);
}

int sensor_getFilterFrequency(const sensor_t *const me){
	return me->filterFrequency;
}
void sensor_setFilterFrequency(sensor_t *const me, int p_filterFrequency){
	me->filterFrequency = p_filterFrequency;
}
int sensor_getUpdateFrequency(const sensor_t *const me){
	return me->updateFrequency;
}
void sensor_setUpdateFrequency( sensor_t *const me, int p_updateFrequency){
	me->updateFrequency = p_updateFrequency;
}
int sensor_getValue(const sensor_t *const me){
	return me->value;
}

