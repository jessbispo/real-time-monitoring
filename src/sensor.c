#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

// Definição da variável sensors
Sensor sensors[NUM_SENSORS];  // Adicione esta linha

void init_sensors() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i].id = i;
        sensors[i].temperature = 0.0;  // Temperatura inicial
        pthread_mutex_init(&sensors[i].lock, NULL);
    }
}

void* sensor_read(void* arg) {
    Sensor* sensor = (Sensor*)arg;

    while (1) {
        // Simula a leitura da temperatura
        pthread_mutex_lock(&sensor->lock);
        sensor->temperature = (rand() % 100);  // Temperatura aleatória entre 0 e 100
        printf("Sensor %d: Temperatura medida: %.2f\n", sensor->id, sensor->temperature);
        pthread_mutex_unlock(&sensor->lock);

        sleep(1);  // Espera 1 segundo antes de ler novamente
    }

    return NULL;
}
