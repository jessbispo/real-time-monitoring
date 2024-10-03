#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/sensor.h" 
#include "src/alert.h"
#include "src/utils.h"

int main() {
    srand(time(NULL)); 
    pthread_t sensor_threads[NUM_SENSORS];
    pthread_t alert_thread;

    init_sensors();

    for (int i = 0; i < NUM_SENSORS; i++) {
        pthread_create(&sensor_threads[i], NULL, sensor_read, (void*)&sensors[i]);
    }
    pthread_create(&alert_thread, NULL, alert_process, NULL);

    //n vao acontecer
    for (int i = 0; i < NUM_SENSORS; i++) {
        pthread_join(sensor_threads[i], NULL);
    }

    pthread_join(alert_thread, NULL);

    return 0;
}
