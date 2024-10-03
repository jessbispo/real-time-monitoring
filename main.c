#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/sensor.h" 
#include "src/alert.h"
#include "src/utils.h"

int main() {
    srand(time(NULL));  // Semente para geração de números aleatórios
    pthread_t sensor_threads[NUM_SENSORS];
    pthread_t alert_thread;

    init_sensors();  // Inicializa sensores e mutexes

    // Cria threads para cada sensor
    for (int i = 0; i < NUM_SENSORS; i++) {
        pthread_create(&sensor_threads[i], NULL, sensor_read, (void*)&sensors[i]);
    }

    // Cria uma thread para processar alertas
    pthread_create(&alert_thread, NULL, alert_process, NULL);

    // Espera que todas as threads de sensores terminem (nunca vai acontecer aqui)
    for (int i = 0; i < NUM_SENSORS; i++) {
        pthread_join(sensor_threads[i], NULL);
    }

    // Espera a thread de processamento de alertas (nunca vai acontecer aqui)
    pthread_join(alert_thread, NULL);

    return 0;
}
