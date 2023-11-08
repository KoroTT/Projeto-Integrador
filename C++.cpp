#include <LiquidCrystal.h>

//Aqui eu defini as v�riaveis que ser�o as mesmas em todo o probrama
//Todas os "x" devem ser substituidos pelas entradas no Arduino Uno
#define buz "x"
#define ledG "x"
#define ledR "x"
#define ledY "x"
#define ledB "x"
#define pushG "x"
#define pushR "x"
#define pushY "x"
#define pushB "x"

//Comando respons�vel pelas v�riaveis do display LCD
//Preencher conforme Instru��o 1 no Trelo: Estudar o c�digo

LiquidCrystal lcd ();

void setup(){
	/*Declarando todos os pinos usados
	Aqui definimos se as v�riaveis la de cima s�o entradas ou saidas e quais 
	pinos foram usados*/
	pinMode (pushG, INPUT);
	pinMode (pushR, INPUT);
	pinMode (pushY, INPUT);
	pinMode (pushB, INPUT);
	pinMode (ledG, OUTPUT);
	pinMode (ledR, OUTPUT);
	pinMode (ledY, OUTPUT);
	pinMode (ledB, OUTPUT);
	pinMode (buz, OUTPUT);
	
	randomSeed(analogRead(0)); //Respos�vel por sempre aleatorizar o sistema.
}

void ciclo(){
	lcd.begin(16,2);
	int inicio = 1; //Aqui definimos a v�riavel que dar in�cio ao sistema.
	ldc.print("Vamos Jogar?"); //Vai escrever no LCD.
	
	/*Quando o bot�o verde for apertado, ele iniciara o sistema
	Como o bot�o est� ligado em portas anal�gicas, quando for apertado
	ele vai retornar o valor 1023.*/
	while (inicio != 1023){
		inicio = analogicRead(pushG); //Esse comando vai ler o bot�o.
		
		//Esses 4 comandos seguidos ligam os leds.
		digitalWrite (ledG, HIGH);
		digitalWrite (ledR, HIGH);
		digitalWrite (ledY, HIGH);	
		digitalWrite (ledB, HIGH);	
	}
	
	lcd.clear(); //Comando para apagar o LCD.
	//Comando respons�vel por apagar os Leds.
	digitalWrite (ledG, LOW);
	digitalWrite (ledR, LOW);
	digitalWrite (ledY, LOW);	
	digitalWrite (ledB, LOW);
	delay(1000); //Vai dar uma pausa de 1 segundo.
	
	int acertou = 1; //Vari�vel que define se a pessoa acertou ou n�o.
	int luz; //V�riavel respons�vel pelo led que vai ascender.
	int pont = 0; //Controle da pontua��o.
	
	while (acertou == 1){//Enquanto o jogador acertar o jogo continua.
		
		//Vai escrever na tela a pontua��o do jogador.
		lcd.print("Vamos l�!");
		lcd.serCursos(0,1);
		lcd.print("Pontuacao: ");
		lcd.print(pont);
		lcd.setCursor(0,0);
		
		luz = random(1, 5); //Escolhe aleatoriamente qual luz vai ascender.
		
		/*Todos os IFs s�o respons�vel por ver qual luz vai ascender
		e ascender as mesmas.*/
		if (luz == 1){ 
			digitalWrite (ledG, HIGH); //Acende a Luz
			tone (buz, 262,500); //Toca o buzzer na frequencia configurada
			delay (500);
			digitalWrite (ledG, LOW);
			delay (200);
		}
		if (luz == 2){
			digitalWrite (ledR, HIGH);
			tone (buz, 294, 500);
			delay (500);
			digitalWrite (ledR, LOW);
			delay (200);
		}
		if (luz == 3){
			digitalWrite (ledY, HIGH);
			tone (buz, 330, 500);
			delay (500);
			digitalWrite (ledY, LOW);
			delay (200);
		}
		if (luz == 4){
			digitalWrite (ledB, HIGH);
			tone (buz, 349, 500);
			delay (500);
			digitalWrite (ledB, LOW);
			delay (200);
		}
		
		//Essas vari�veis recebem o valor de 1023 quando o bot�o � apertado.
		int pg = analogRead(pushG);
		int pr = analogRead(pushR);
		int py = analogRead(pushY);
		int pb = analogRead(pushB);
		
		/*Se o bot�o dessas luzes for apertado, ele vai testar se a
		luz � a correta ou n�o e retornar 1 para acertou quando a resposta
		for certa e 0 quando for a errada.*/
		if (pg == 1023){ 
			digitalWrite (ledG, HIGH);
			tone (buz, 262, 500);
			if (luz == 1){ //Testa se � a luz correta que foi acessa.
				pont++; //Adiciona 1 ponto na pontua��o.
			}
			else{
				acertou = 0; //Se o jogador errou, retorna 0
			}
			while (pg == 1023) {pg = analogRead(pushG)} /*Mantem a luz ligada enquanto
														  o bot�o estiver apertado*/
			delay (500);
			digitalWrite(ledG, LOW);
			delay (500);
		}
		if (pr == 1023){ 
			digitalWrite (ledR, HIGH);
			tone (buz, 294, 500);
			if (luz == 2){ //Testa se � a luz correta que foi acessa.
				pont++; //Adiciona 1 ponto na pontua��o.
			}
			else{
				acertou = 0; //Se o jogador errou, retorna 0
			}
			while (pr == 1023) {pr = analogRead(pushR)} /*Mantem a luz ligada enquanto
														  o bot�o estiver apertado*/
			delay (500);
			digitalWrite(ledR, LOW);
			delay (500);
		}
		if (py == 1023){ 
			digitalWrite (ledY, HIGH);
			tone (buz, 330, 500);
			if (luz == 3){ //Testa se � a luz correta que foi acessa.
				pont++; //Adiciona 1 ponto na pontua��o.
			}
			else{
				acertou = 0; //Se o jogador errou, retorna 0
			}
			while (py == 1023) {py = analogRead(pushY)} /*Mantem a luz ligada enquanto
														  o bot�o estiver apertado*/
			delay (500);
			digitalWrite(ledY, LOW);
			delay (500);
		}
		if (pb == 1023){ 
			digitalWrite (ledB, HIGH);
			tone (buz, 349, 500);
			if (luz == 4){ //Testa se � a luz correta que foi acessa.
				pont++; //Adiciona 1 ponto na pontua��o.
			}
			else{
				acertou = 0; //Se o jogador errou, retorna 0
			}
			while (pb == 1023) {pb = analogRead(pushB)} /*Mantem a luz ligada enquanto
														  o bot�o estiver apertado*/
			delay (500);
			digitalWrite(ledB, LOW);
			delay (500);
		}
	}
	
	//Quando o jogador errar
	tone (buz, 415, 3000); //Vai fazer um som diferente das luzes

	/*Vai escrever na tela a pontua��o*/
	lcd.clear();
	lcd.print("Finalizando...");
	lcd.setCursor(0,1);
	lcd.print("Resultado: ");
	lcd.print(pont);
	delay(3000);	
}
