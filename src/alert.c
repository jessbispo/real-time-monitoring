#include "alert.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "sensor.h"
#include "utils.h"

Alert alerts[NUM_SENSORS];
int alert_count = 0; 
pthread_mutex_t alert_lock;  

void* alert_process(void* arg) {
    log_message("Thread de alerta iniciada."); 

    while (1) {
        for (int i = 0; i < NUM_SENSORS; i++) {
            pthread_mutex_lock(&sensors[i].lock);  // bloqueia o acesso ao sensor

            if (sensors[i].temperature > 850) {  
                pthread_mutex_lock(&alert_lock);

                alerts[alert_count].sensor_id = sensors[i].id;
                alerts[alert_count].temperature = sensors[i].temperature;

                sprintf(alerts[alert_count].message, "Sensor %d detectou temperatura alta de %.2f!", sensors[i].id, sensors[i].temperature);
                printf("ALERTA: %s\n", alerts[alert_count].message);
                log_message("ALERTA: Sensor %d detectou temperatura alta %.2f", sensors[i].id, sensors[i].temperature);

                alert_count++;

                pthread_mutex_unlock(&alert_lock);

            } else if (sensors[i].temperature < 740) { 
                pthread_mutex_lock(&alert_lock);

                alerts[alert_count].sensor_id = sensors[i].id;
                alerts[alert_count].temperature = sensors[i].temperature;

                sprintf(alerts[alert_count].message, "Sensor %d detectou temperatura baixa de %.2f!", sensors[i].id, sensors[i].temperature);
                printf("ALERTA: %s\n", alerts[alert_count].message);
                log_message("ALERTA: Sensor %d detectou temperatura baixa %.2f", sensors[i].id, sensors[i].temperature);

                alert_count++;

                pthread_mutex_unlock(&alert_lock);
            } else {
  
                printf("Sensor %d: Temperatura medida %.2f está dentro da faixa normal.\n", sensors[i].id, sensors[i].temperature);
                log_message("Sensor %d: Temperatura medida %.2f está dentro da faixa normal.", sensors[i].id, sensors[i].temperature);
            }

            pthread_mutex_unlock(&sensors[i].lock);  // libera o acesso ao sensor
        }
        sleep(2);
    }

    log_message("Thread de alerta finalizada.");  // log de finalização da thread
    return NULL;
}

void init_alerts() {
    pthread_mutex_init(&alert_lock, NULL);
}
