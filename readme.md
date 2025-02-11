# Controle de Servomotor por PWM

## Descrição
Este projeto visa o controle de um servomotor utilizando PWM (Pulse Width Modulation) no microcontrolador Raspberry Pi Pico W. A implementação utiliza a ferramenta Pico SDK para simulação no ambiente Wokwi. O servomotor será controlado para ajustar-se em diferentes posições (0°, 90° e 180°) e, posteriormente, realizar um movimento suave entre os extremos.

## Requisitos
- Raspberry Pi Pico W (simulado no Wokwi)
- Servomotor micro servo padrão (simulado no Wokwi)
- Ambiente de desenvolvimento VS Code
- Kit de Desenvolvimento de Software Pico SDK
- Integração do simulador Wokwi ao VS Code
- Repositório GitHub para versionamento do código

## Funcionalidades
1. Configura a GPIO 22 para gerar um sinal PWM com frequência de aproximadamente 50Hz.
2. Define ciclos ativos do PWM para:
   - 2400µs (μs) - Posição 180° (Aguarda 5s)
   - 1470µs (μs) - Posição 90° (Aguarda 5s)
   - 500µs (μs) - Posição 0° (Aguarda 5s)
3. Movimentação suave do servo motor entre 0° e 180° em incrementos de 5µs com atraso de 10ms.
4. Experimento com a placa BitDogLab utilizando um LED RGB no GPIO 12.

## Instalação e Uso
1. Clone o repositório:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   ```
2. Compile e carregue o código para a Raspberry Pi Pico W utilizando o Pico SDK.
3. Execute a simulação no Wokwi.

## Observações do LED RGB (GPIO 12)
Descreva o comportamento do LED RGB ao executar o código no BitDogLab.

## Vídeo Demonstrativo
[--]

## Autor
Leonardo Jonatan

