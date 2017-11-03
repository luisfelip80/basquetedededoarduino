/*  #### BASQUETE DE DEDO #### */ 
/*  ####    Luis Felipe   #### */ 
/*  ####     Monalisa     #### */
/*  #### Willian Guterres #### */

#define temp 10 // Variavel de controle para tempo do som final
#define sensor 6 // Sensor de infravermelho para controle de pontos.
#include <LiquidCrystal.h> //Biblioteca para LCD
#include <Servo.h> //Biblioteca do servo.

Servo myservo;  //Variavel para controle do servo.
int frequencia = 0; // Variavel para controle de frequencia do som final.
int Pinofalante = 10;  // Valor da variavel do pinofalante do som final.
int tw = 0; // Controle da impressao do tempo no LCD
int pos = 0; // Variavel da posicao do servo. 
int tempo; // Variavel que controla o tempo do jogo.
int h; // controle do tempo impresso.
int portSpeak(10); // Variavel e saida do som
int portSpeak2(8);// Variavel e saida do som
int o, a, seg; //Variaveis de controle e tempo. Variavel "a" controla direcao do servo.
int pontos; // variavel de controle dos pontos.

                  //## Melodia do ponto ##
int melodia[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
int melodia1[] = {1000, 900, 900, 700, 700, 500, 500, 400, 200, 100};


int duracaodasnotas[] = {1000,1000, 1000, 1000, 1000, 1000, 1000,1000, 1000, 100};
int duracaodasnotas1[] = {1000,1000, 1000, 1000, 1000, 1000, 1000,1000, 1000, 100};

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD



void setup() 
{  
 a = 1;
 tempo = 30; // Tempo começa como valendo 0.
 pinMode(10, OUTPUT); // Definir saida digital 10 como saida.
  
 pinMode(8, OUTPUT);  // Definir saida digital 8 como saida.
lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)  
pontos=0;
seg=0;
h=100;
} 

void loop() 
{ 
  
  myservo.attach(9);
  while (seg < 3000){ //While executa enquanto a variavel seg for menor que 3 mil.
 
 
  myservo.write(pos); 
  if ( pos== 40) { // Se a variavel pos for = 0, defina a como valendo 1.
    a= 1;
  }
  else if (pos == 120) { // Se a variavel pos for = 120, defina a como valendo 0.
    a= 0;
  } 
  
  if (a == 1) { // Se a variavel "a" for = 1, some + 1 a variavel pos.
    pos=pos+1;  
  } 
  else if ( a== 0)   // Se a variavel "a" for = 0, subtraia - 1 a variavel pos.
  {         
    pos=pos-1;    
  }               

  if (seg==h) {  // Se a variavel dos segundos "seg" for = a h, some +1 a variavel "tempo".
    tempo=tempo-1;
    h=h+100;
}
  else { //se nao...
}

   
  lcd.setCursor(13, 0); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD
  lcd.print(tempo); //Escreve no LCD "LabdeGaragem" 
  seg=seg+1;
  


  lcd.setCursor(12, 1); //Posiciona o cursor na décima quarta coluna(13) e na segunda linha(1) do LCD
  lcd.print(pontos); //Escreve o valor atual da variável de contagem no LCD
  pinMode(sensor, INPUT); //Configura o pino 2 como entrada 



  lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD
  lcd.print("Pontos:"); //Escreve no LCD "LabdeGaragem"


  if(digitalRead(sensor)) { // Se sensor detectar a bola passando pelo infravermelho, execute isso.
  
    pontos ++;  
 
  

   lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
   lcd.print("PONTO!!!!!"); //Escreve no LCD "PONTO!!!!!!"



               /* ###  Musica de ponto ### */    

  for (int nota = 0; nota < 10; nota++) {
 
              int duracaodanota = duracaodasnotas[nota];
              tone(portSpeak, melodia[nota],duracaodanota);
              tone(portSpeak2, melodia[nota],duracaodanota);
              int pausadepoisdasnotas[] ={100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
              delay(pausadepoisdasnotas[nota]);}
              delay(200);
              noTone(portSpeak);
              noTone(portSpeak2);
              
            
}

else {  // se no acontecer o ponto, faça isso abaixo.
  o=0;
lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
  lcd.print("   Tempo  :");


}

}
if ( seg==3000) { // Se a variavel de segundos "seg" for igual a 3 mil, faça isso abaixo.
  if (tw == 0) { // Som final.
    tw++;
   for (frequencia = 150; frequencia < 1000; frequencia += 1) 
  {
    tone(portSpeak, frequencia, temp); 
    delay(1);
  }
  for (frequencia = 150; frequencia > 1000; frequencia -= 1) 
  {
    tone(portSpeak, frequencia, tempo); 
    delay(1);
  }
  }
  lcd.setCursor(0,0);
  if (pontos == 0) { // Pontos == 0, faça isso abaixo.
    lcd.print("Nao foi dessa vez  ");
    delay(100);
    for (int i =0; i <16; i++){     
  lcd.scrollDisplayLeft();     
  delay(400); 
   
  }
  }
  else if (pontos >= 0 & pontos <= 3) { // Pontos for maior ou igual a 0 e menor ou igual a 3, faça isso abaixo.
   lcd.print("Mais ou menos...   ");
    delay(100);
  for (int i =0; i < 16; i++){     
  lcd.scrollDisplayLeft();     
  delay(400);      
  } 
  }
  else if (pontos >= 3 & pontos <= 6) {// Pontos for maior ou igual a 3 e menor ou igual a 6, faça isso abaixo.
    lcd.print("Muito Bom!!       ");
    delay(100);    
    for (int i =0; i <16; i++){     
    lcd.scrollDisplayLeft();     
    delay(400);   
  }     
  }
  else if (pontos >= 6 & pontos <= 9) {// Pontos for maior ou igual a 6 e menor ou igual a 9, faça isso abaixo.
    lcd.print("Uau! Como fez isso ?");
    delay(100);
    for (int i =0; i <16; i++){     
  lcd.scrollDisplayLeft();     
  delay(400);   
  }
  }
    /* Mostrar os pontos */
  lcd.setCursor(0,1);
  lcd.print("Pontuacao: ");
  lcd.setCursor(12,1);
  lcd.print(pontos);  
  

}
}
