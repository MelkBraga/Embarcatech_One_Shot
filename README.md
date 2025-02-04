# Embarcatech_Interrupcoes_LedMatrix
Repositório criado para a Tarefa 2 - Aula Síncrona 29/01 - Atividade 2 - Temporizador De Um Disparo (One Shot)

Aluno: Melk Silva Braga

# Instruções de compilação para o simulador

Para compilar e rodar o código, são necessárias as seguintes extensões: 

*Raspberry Pi Pico*

*Cmake*

*Cmake Tools*

*Wokwi simulator*

Após a compilação, clicar no arquivo "diagram.json" e iniciar a simulação no wokwi.
No terminal poderá ser possível observar uma mensagem a cada segundo (1.000 ms) enquanto
o botão não é pressionado.

# Instruções de compilação para a BitDogLab

Alternativamente, foi adicionado ao repositório o arquivo "codigo_oneshot_bitdoglab.txt" com um código modificado 
para que o programa funcione na placa BitDogLab, visto que o mapeamento GPIO do LED RGB da placa é diferente da 
configuração exigida no wokwi para a atividade, além de que a placa não possui leds de cores independentes.

Substitua o código do arquivo principal "oneShot.c" pelo do arquivo .txt, faça a compilação e para
rodar na placa, é necessário conectá-la via cabo usb em modo bootsel e ter instalado o driver 
WinUSB (v6.1.7600.16385) na interface 1. Só então clicar em "Run Project", na extensão Raspberry Pi Pico.

Para iniciar o One Shot, pressione o botão A.

No painel de LEDs WS2812, setas indicativas são exibidas. No Serial Monitor do VSCode, selecionar a porta correta e 
clicar em "Start Monitoring" para observar uma mensagem a cada segundo (100 ms) enquanto o botão não é pressionado.

Perceba que o LED RGB vai começar da cor BRANCA, pois é o resultado da união do Azul, Vermelho e Verde que são iniciados
simultâneamente. Em seguida mudará para uma cor AMARELADA, pois é o resultado da união do Vermelho e Verde, já que o Azul
foi apagado depois de 3s. Por último, a cor VERDE, pois o Vermelho também foi apagado após outros 3 segundos.

# Vídeo demonstrativo do One Shot funcionando na BitDogLab
https://youtube.com/shorts/OT0d1WxaPsY?feature=share
