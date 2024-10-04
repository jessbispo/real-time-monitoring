#ifndef SENSOR_H
#define SENSOR_H

#include <pthread.h>

#define NUM_SENSORS 5
#define ALERT_TEMP_SUPLIMIT 850.0 //temperatura limite pra nao perder a queima 
#define ALERT_TEMP_INFLIMIT 740.0 

typedef struct {
    int id;
    float temperature;
    pthread_mutex_t lock;
} Sensor;

extern Sensor sensors[NUM_SENSORS];

void init_sensors();
void* sensor_read(void* arg);

#endif
