#include <LiquidCrystal.h>
 
//Declarar LCD y pines
LiquidCrystal lcd(2,3,4,5,6,7);
//               (Rs,E,DB4,DB5,DB6,DB7)

int horas = 0;
int minutos = 0;
int segundos = 0;
int decimas = 0;
long milisegundos = 0;
 
int pulsadorReset = 10;
int pulsadorPausa = 9; 
 
void setup() {
  	Serial.begin(9600);
    pinMode(pulsadorReset, INPUT); 
    pinMode(pulsadorPausa, INPUT);
    // Inicializamos el LCD
    lcd.begin(16,2);
    pintarPantalla();
}
 
void loop() {
	 // Si presionamos el pulsador de inicio se pone todo a cero
    if(digitalRead(pulsadorReset) == HIGH)
    {
      horas = 0;
      minutos = 0;
      segundos = 0;
      decimas = 0;
      lcd.clear();
      pintarPantalla();
    }
  
  	 // Si presionamos el pulsador de pausa se congela el tiempo hasta que lo volvamos a presionar
    if(digitalRead(pulsadorPausa) == HIGH)
    {
      delay(100);
      while(digitalRead(pulsadorPausa) == LOW);
      delay(100);
    }
  	
  	cronometro();
}


void cronometro(){
	// Se cuentan los milisegundos transcurridos
    milisegundos = millis();
   
    // Si el tiempo transcurrido es mayor a una décima de segundo
    if(milisegundos % 100 == 0)
    {
      decimas++;
      // Si han pasado 10 décimas de segundo se cuenta un segundo
      if(decimas == 10)
      {
        decimas = 0;
        segundos++;
      }
      // Si han pasado 60 segundos se cuenta un minuto
      if(segundos == 60)
      {
        segundos = 0;
        minutos++;
      }
      // Si han pasado 60 minutos se cuenta una hora
      if(minutos == 60)
      {
        minutos = 0;
        horas++;
      }
     
      // Mostramos el tiempo a través del LCD
      lcd.setCursor(0,1);
      if(horas < 10)
      {
        lcd.print("0");
      }
      lcd.print(horas);
      lcd.print(":");
      lcd.setCursor(3,1);
      if(minutos < 10)
      {
        lcd.print("0");
      }
      lcd.print(minutos);
      lcd.print(":");
      lcd.setCursor(6,1);
      if(segundos < 10)
      {
        lcd.print("0");
      }
      lcd.print(segundos);
      lcd.print("(");
      lcd.setCursor(9,1);
      lcd.print(decimas);
      lcd.print(")");
    }    
}

void pintarPantalla(){
    lcd. setCursor(0, 0);
    lcd.print("h");
    lcd. setCursor(3, 0);
    lcd.print("m");
    lcd. setCursor(6, 0);
    lcd.print("s");
    lcd. setCursor(9, 0);
    lcd.print("ds");
}

