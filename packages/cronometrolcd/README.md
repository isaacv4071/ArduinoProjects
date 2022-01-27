# CONFIGURACIÓN DE DISPOSITIVOS ELECTRÓNICOS
### **Cronometro LCD + pulsadores**

En la Figura 1 se muestra un cronómetro digital controlador con Arduino y visualización
con display 16x2. Para este sistema existen ciertas condiciones que deben cumplirse:

1. El cronómetro debe iniciarse al conectarse el arduino.

2. Debe tener un botón de pause, el cuál debe servir para reanudar el conteo.

3. Debe tener un botón de reset, el cuál debe borrar los datos que tenía el crnómetro hasta ese momento.

4. En el display se deben mostrar las décimas de segundo, los segundos, los minutos y las horas.

* Diseño del circuito:

    ![Esta es una imagen de ejemplo](images/cronometro.png "Figura 1. Cronómetro digital")

* Codigo fuente:

    [Link code Here](https://github.com/isaacv4071/ArduinoProjects/blob/main/packages/cronometrolcd/code/main.ino)