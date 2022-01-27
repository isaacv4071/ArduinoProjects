// C++ code
// Definición de pines del semáforo

//Semáforo 1
int rojo1= 2; 
int amarillo1= 3;
int verde1 = 4;

//Semáforo 2
int rojo2= 5;
int amarillo2= 6;
int verde2= 7;

//semaforo 3
int rojo3 = 8;
int amarillo3 = 9;
int verde3 = 10;

// tiempos de los semaforos
int t1 = 500;
int t2 = 15000;

//auxiliar para el ciclo while
int aux = 1;

void setup()
{
  //semaforo 1
  pinMode(rojo1, OUTPUT);
  pinMode(amarillo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  
  //semaforo 2
  pinMode(rojo2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  
  //semaforo 3
  pinMode(rojo3, OUTPUT);
  pinMode(amarillo3, OUTPUT);
  pinMode(verde3, OUTPUT);
  
  digitalWrite(verde1, HIGH);//Inicio mi primer semáforo en verde
  digitalWrite(amarillo1, LOW);
  digitalWrite(rojo1, LOW);
  
  digitalWrite(verde2, LOW);
  digitalWrite(amarillo2, LOW);
  digitalWrite(rojo2, HIGH);//Inicio el segundo semáforo en rojo
  
  digitalWrite(verde3, LOW);
  digitalWrite(amarillo3, LOW);
  digitalWrite(rojo3, HIGH);//Inicio el tercer semáforo en rojo
  Serial.begin(9600);
}

void loop()
{
  Serial.read();
  while (aux == 1){
  	digitalWrite(rojo1, LOW);
    digitalWrite(verde1, HIGH);
    delay(t2);
    digitalWrite(verde1, LOW);
    digitalWrite(amarillo1, HIGH);
    delay(t1);
    digitalWrite(amarillo1, LOW);
    digitalWrite(rojo1, HIGH);
    
    digitalWrite(rojo2, LOW);
    digitalWrite(verde2, HIGH);
    delay(t2);
    digitalWrite(verde2, LOW);
    digitalWrite(amarillo2, HIGH);
    delay(t1);
    digitalWrite(amarillo2, LOW);
    digitalWrite(rojo2, HIGH);
    
    digitalWrite(rojo3, LOW);
    digitalWrite(verde3, HIGH);
    delay(t2);
    digitalWrite(verde3, LOW);
    digitalWrite(amarillo3, HIGH);
    delay(t1);
    digitalWrite(amarillo3, LOW);
    digitalWrite(rojo3, HIGH);
  }
}