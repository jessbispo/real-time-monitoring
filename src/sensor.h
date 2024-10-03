#ifndef SENSOR_H
#define SENSOR_H

#include <pthread.h>

#define NUM_SENSORS 20
#define ALERT_THRESHOLD 75.0 

typedef struct {
    int id;
    float temperature;
    pthread_mutex_t lock;
} Sensor;

extern Sensor sensors[NUM_SENSORS];

void init_sensors();
void* sensor_read(void* arg);

#endif
