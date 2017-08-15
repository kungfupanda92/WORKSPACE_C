#ifndef __SENSOR_H__
#define __SENSOR_H__

/* Class sensor */

typedef struct{
	int filterFrequency;
	int updateFrequency;
	int value;
} sensor_t;

int sensor_getFilterFrequency(const sensor_t *const me);
void sensor_setFilterFrequency(sensor_t *const me, int p_filterFrequency);
int sensor_getUpdateFrequency(const sensor_t *const me);
void sensor_setUpdateFrequency(sensor_t *const me, int p_updateFrequency);
int sensor_getValue(const sensor_t *const me);
sensor_t *sensor_create(void);
void sensor_destroy(sensor_t *const me);


#endif