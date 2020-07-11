# Actividad práctica con git
Repositorio inicial para práctica de trabajo colaborativo con git, GitHub y MPLAB X IDE.

## Primera Parte - Merge
1. Clona este repositorio en tu computadora.
2. En el archivo `main.c` escribe tu nombre y apellido en la lista de autores, similar al siguiente ejemplo:
    ```c
    /*
     * Nombre del archivo:   main.c
     *
     * Descripción: 
     *        Este programa es un ejemplo para practicar trabajo colaborativo
     *        usando git como herramienta de control de versiones.
     * 
     * Autores:
     *        Nahuel Espinosa
     */
    ```
3. Confirma los cambios con un *commit* con el texto **"Se agregan los datos de APELLIDO, Nombre"** en la descripción del mismo.
4. Envía los cambios efectuados al servidor con un *push*.
5. Si en el proceso alguien más envió cambios en la rama *master* entonces el servidor rechazará el envío. En este caso deberás realizar un nuevo *pull* y resolver los conflictos. Después genera un nuevo *commit* e intenta un nuevo *push*. Este paso se deberá repetir hasta que nadie efectúe cambios entre el *pull* y el *push*, y se pueda completar la actualización del servidor.

## Segunda Parte - Branches
1. En el proyecto clonado en la primera parte, crea y cambia a la rama *develop*.
3. Agrega en el archivo `main.c` el prototipo de una función que imprima tu nombre y apellido, similar a la del siguiente ejemplo:
	```c
    // TODO: Agregar prototipo de función que imprime tu nombre y apellido
	void printNahuelEspinosa();
	```
4. Agrega al archivo `main.c` la correspondiente llamada en el programa principal para que se muestren tus datos, en forma similar a la del siguiente ejemplo:
	```c
	void main(void) {
	    ...
        // TODO: Agregar el llamado a la función que imprime tu nombre y apellido
	    printNahuelEspinosa();
    
	    while(1) {                  // Super loop
	        __delay_ms(10);
	    }
	    ...
	}
	```
5. Agrega al archivo `main.c` la implementación de la función que imprima tu nombre y apellido, similar a la del siguiente ejemplo.
	```c
    // TODO: Agregar implementación de función que imprime tu nombre y apellido
	void printNahuelEspinosa() {
	    uartWriteString("Nahuel Espinosa\r\n");
	}
	```
6. Compila el programa, ejecutalo y revisa que el mismo funcione correctamente.
7. Confirma los cambios con un *commit* con el texto **"Se agrega la función con los datos de APELLIDO, Nombre"** en la descripción del mismo.
8. Cambia a la rama *master* y trae los cambios del servidor con un *pull*.
9. Mezcla la rama *develop* en la rama *master*, resuelve los conflictos y confirma los cambios con un *commit* en la rama *master*.
10. Envía los cambios efectuados en la rama *master* al servidor con un *push*.
11. Si en el proceso alguien más envió cambios en la rama *master* entonces el servidor rechazará el envío. En este caso deberás realizar un nuevo *pull* y resolver los conflictos. Después genera un nuevo *commit* e intenta un nuevo *push*. Este paso se deberá repetir hasta que nadie efectúe cambios entre el *pull* y el *push*, y se pueda completar la actualización del servidor.