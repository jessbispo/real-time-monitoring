# Documentação do Projeto de Monitoramento de Temperatura

## Descrição do Projeto

Este projeto tem como objetivo monitorar a temperatura de sensores em tempo real e gerar alertas quando a temperatura estiver fora dos limites ideais. O sistema também registra logs detalhados sobre o ciclo de vida das threads, que ajudam na identificação de eventos críticos.

## Funcionalidades

- **Leitura de Sensores**: O sistema lê a temperatura de múltiplos sensores em intervalos regulares.
- **Geração de Alertas**: Alerta quando a temperatura está abaixo de 740°C ou acima de 850°C.
- **Logs Estruturados**: Geração de logs que acompanham a criação, execução, sincronização e finalização das threads.
- **Visualização de Logs**: Os logs são organizados para fácil identificação de eventos críticos.

## Estrutura do Código

### Principais Arquivos

- `main.c`: Ponto de entrada do programa que inicializa sensores e threads.
- `sensor.c`: Implementa a leitura de temperatura dos sensores.
- `alert.c`: Monitora as leituras de temperatura e gera alertas.
- `utils.c`: Contém funções auxiliares, como a geração de logs.

### Estruturas de Dados

- **Sensor**: Estrutura que armazena informações do sensor, como ID e temperatura.
- **Alert**: Estrutura que armazena informações sobre alertas gerados.

## Mecanismos de Sincronização

- **Mutexes**: Utilizados para garantir que apenas uma thread possa acessar dados críticos, como a temperatura dos sensores e a lista de alertas.
- **Semáforos**: Controlam o acesso às threads de sensores, permitindo que apenas um sensor leia a temperatura por vez.

## Geração de Logs

Os logs são gerados para acompanhar:

- **Criação de Threads**: Logs informando quando uma nova thread de sensor é criada.
- **Execução de Threads**: Logs com a temperatura medida por cada sensor.
- **Sincronização de Threads**: Logs que mostram o uso de mutexes e semáforos.
- **Finalização de Threads**: Logs que indicam quando uma thread encerra sua execução.

## Exemplo de Logs

- Quando a temperatura é medida dentro da normalidade:

## TBD:
    Adicionar SendEmail funtion pra quando alertas acontecerem