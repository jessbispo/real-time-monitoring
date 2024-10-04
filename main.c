#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/sensor.h" 
#include "src/alert.h"
#include "src/utils.h"
#include <semaphore.h>

int main() {
    srand(time(NULL)); 
    pthread_t sensor_threads[NUM_SENSORS];
    pthread_t alert_thread;
    sem_t sensor_sem; 
    
    sem_init(&sensor_sem, 0, 3);
    init_sensors();
    
    for (int i = 0; i < NUM_SENSORS; i++) {
        pthread_create(&sensor_threads[i], NULL, sensor_read, (void*)&sensors[i]);
        log_message("Nova thread criada");
    }
    pthread_create(&alert_thread, NULL, alert_process, NULL);
    log_message("Nova thread criada");

    for (int i = 0; i < NUM_SENSORS; i++) {
        pthread_join(sensor_threads[i], NULL);
    }

    pthread_join(alert_thread, NULL);

    return 0;
}
