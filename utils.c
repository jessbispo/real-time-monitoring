#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void log_message(const char *format, ...) {
    FILE *log_file = fopen("logs/system_log.txt", "a");
    if (log_file == NULL) {
        perror("Erro ao abrir o arquivo de log");
        return;
    }

    // Obtendo o timestamp atual
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    fprintf(log_file, "[%02d-%02d-%04d %02d:%02d:%02d] ", 
            tm_now->tm_mday, tm_now->tm_mon + 1, tm_now->tm_year + 1900,
            tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    fprintf(log_file, "\n");
    va_end(args);

    fclose(log_file);
}
