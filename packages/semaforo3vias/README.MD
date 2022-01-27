# CONFIGURACIÓN DE DISPOSITIVOS ELECTRÓNICOS
## Autores
- Isaac Arrieta Mercado
- Yan Fran Arias Bohorquez 
- Carlos de Jesus Arguelles Monterrosa
- Jose Alejandro Gonzalez Ortiz

### **Control de un semáforo de tres vías**

En la Figura 1 se muestra una intersección de tres vías. El tráfico en cada una de las vías es controlado por un semáforo de tres luces (verde, roja y amarilla) que está diagonal a la intersección de cada vía (o sea enfrente de la bocacalle). Para este sistema de luces existen ciertas condiciones que deben cumplirse:

1. Nunca se deben activar 2 luces verdes al mismo tiempo.

2. Cada vía debe tener un tiempo de paso (luz verde activada) de 15 segundos.

3. La luz amarilla sólo se debe activar cuando se va a hacer el cambio de luz verde a roja (no es necesario activarla en el cambio de roja a verde).

4. Nunca se deben activar al mismo tiempo una luz verde y una amarilla (pude ocasionar accidentes).

5. Nunca se deben activara varias luces amarillas al mismo tiempo.

6. La duración de la luz amarilla debe ser máximo de 1 segundo (se recomienda 0,5 segundos).

    ![Figura 1](images/figura1.png "Figura 1. Intersección de tres vías")

* Diseño del circuito:

    ![circuito](images/semaforo.png "Circuito")

* Codigo fuente:

    * Definimos los pines de los leds que van a utilizar los semaforos.
        ```c++
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
        ```

    * Iniciamos las varibles de tiempo para los semaforos y una varible auxiliar que nos ayudara con el funcionamiento de estos.
        ```c++
        // tiempos de los semaforos
        int t1 = 500;
        int t2 = 15000;

        //auxiliar para el ciclo while
        int aux = 1;
        ```
    
    * En el void setup() inicializamos los pines de los leds como salidas y damos inicio a la secuencia, en primera instancia inicia el primer semaforo en verde y los demas en rojo.
        ```c++
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
        }
        ```

    * Por ultimo en el void loop() vamos continuar con la secuencia para esto nos hacemos con la varible auxiliar que declaramos inicamos un ciclo while y dentro de este ciclo comenzamos diciendo que el led rojo este apagado pero el verde este encendido por el tiempo t2 luego de ese tiempo apagamos el led verde y encendemos el led amarillo por el tiempo t1 pasado ese tiempo finalmente apagamos el led amarillo y encendemos el rojo, esta misma secuencia se utiliza para los tres semaforos.
        ```c++
        void loop()
        {
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
        ```

* Link de la simulación:

    [Link Simulation Here](https://www.tinkercad.com/things/6g6R8uzQU3D)