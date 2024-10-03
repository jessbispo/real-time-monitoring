#ifndef SENSOR_H
#define SENSOR_H

#include <pthread.h>

#define NUM_SENSORS 20
#define ALERT_THRESHOLD 75.0  // Limite de alerta para temperatura

// Estrutura que representa um sensor
typedef struct {
    int id;
    float temperature;
    pthread_mutex_t lock;  // Mutex para sincronização
} Sensor;

extern Sensor sensors[NUM_SENSORS];

// Declarações das funções
void init_sensors();
void* sensor_read(void* arg);

#endif // SENSOR_H
