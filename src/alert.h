#ifndef ALERT_H
#define ALERT_H

#include <pthread.h>
#include "sensor.h"

// Estrutura para um alerta
typedef struct {
    int sensor_id;
    float temperature;
    char message[256];
} Alert;

// Declarações das funções
void* alert_process(void* arg);
void init_alerts();

#endif // ALERT_H