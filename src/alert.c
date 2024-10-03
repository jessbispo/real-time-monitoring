#include "alert.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para sleep
#include "sensor.h" // Adicione esta linha

// Array para armazenar alertas
Alert alerts[NUM_SENSORS];
int alert_count = 0; 
pthread_mutex_t alert_lock;  

void* alert_process(void* arg) {
    while (1) {
        for (int i = 0; i < NUM_SENSORS; i++) {
            pthread_mutex_lock(&sensors[i].lock);
            if (sensors[i].temperature > ALERT_THRESHOLD) {
                pthread_mutex_lock(&alert_lock);
                alerts[alert_count].sensor_id = sensors[i].id;
                alerts[alert_count].temperature = sensors[i].temperature;
                sprintf(alerts[alert_count].message, "ALERTA: Sensor %d detectou temperatura alta de %.2f!", sensors[i].id, sensors[i].temperature);
                alert_count++;
                printf("ALERTA GERAL: %s\n", alerts[alert_count - 1].message);
                pthread_mutex_unlock(&alert_lock);
            }
            pthread_mutex_unlock(&sensors[i].lock);
        }
        sleep(2);
    }

    return NULL;
}

void init_alerts() {
    pthread_mutex_init(&alert_lock, NULL);
}
