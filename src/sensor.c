#include "sensor.h"
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h> 
#include "utils.h"

Sensor sensors[NUM_SENSORS]; 
sem_t sensor_sem;

void init_sensors() {
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i].id = i;
        sensors[i].temperature = 0.0; 
        pthread_mutex_init(&sensors[i].lock, NULL);
    }
    sem_init(&sensor_sem, 0, 1);
}

void* sensor_read(void* arg) {
    Sensor* sensor = (Sensor*)arg;

    log_message("Thread do sensor %d iniciada.", sensor->id); 

    while (1) {
        sem_wait(&sensor_sem);

        pthread_mutex_lock(&sensor->lock);
        sensor->temperature = 600 + (rand() % (900 - 600 + 1));  
        log_message("Sensor %d: Temperatura medida: %.2f", sensor->id, sensor->temperature);
        pthread_mutex_unlock(&sensor->lock);

        sem_post(&sensor_sem);
        sleep(1); 
    }

    log_message("Thread do sensor %d finalizada.", sensor->id); 
    return NULL;
}

void cleanup_sensors() {
    sem_destroy(&sensor_sem);
}
