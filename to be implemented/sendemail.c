#include <curl/curl.h>
#include <stdio.h>

void send_email() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.example.com");
        curl_easy_setopt(curl, CURLOPT_USERNAME, "seu_email@example.com");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "sua_senha");
        
        // Defina o remetente e o destinatário
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "<seu_email@example.com>");
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, "<destinatario@example.com>");
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        
        // Defina a mensagem do e-mail
        const char *msg = "Subject: Teste\n\nEste é um e-mail de teste enviado com cURL.";
        curl_easy_setopt(curl, CURLOPT_READDATA, msg);
        
        // Enviar o e-mail
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() falhou: %s\n", curl_easy_strerror(res));
        }
        
        // Limpar
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
}
