/* 
 * Objetivo: Utilizar el comportamiento LIFO para invertir cadenas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definición de tipos básicos
typedef char DATO;
typedef struct elemento {
    DATO d;
    struct elemento *siguiente;
} ELEMENTO;

typedef struct {
    int cnt;
    ELEMENTO *tope;
} PILA;

// --- Funciones de Pila (A completar por el alumno) ---
void inicializar(PILA *s);
void push(PILA *s, DATO x);
DATO pop(PILA *s);
int estavacia(PILA *s);
int esPalindromo(char cadena[]);
// Funcion inicializar
void inicializar(PILA *stk) {
    /* TODO: 
       1. Inicializar el contador de elementos (cnt) a 0.
       2. Inicializar el puntero al tope a NULL. 
    */
    stk->cnt=0;
    stk->tope=NULL;
}

// Funcion push
void push(PILA *stk, DATO x) {
    /* TODO: 
       1. Declarar un puntero a ELEMENTO y asignar memoria con malloc.
       2. Asignar el dato 'x' al nuevo elemento.
       3. Hacer que el nuevo elemento apunte al actual tope de la pila.
       4. Actualizar el tope de la pila para que sea el nuevo elemento.
       5. Incrementar el contador (cnt).
    */
    ELEMENTO *uno;
    uno=malloc(sizeof(ELEMENTO));
    uno->d=x;
    uno->siguiente=stk->tope;
    stk->tope=uno;
    stk->cnt++;
    
}

// Funcion pop
DATO pop(PILA *stk) {
    if (estavacia(stk)) {
        printf("ERROR: Intento de POP en pila vacia (Stack Underflow)\n");
        exit(1); 
    }
    /* TODO: 
       1. Declarar una variable DATO para el valor de retorno.
       2. Declarar un puntero ELEMENTO temporal para el nodo a eliminar.
       3. Guardar el dato del tope en la variable DATO.
       4. Hacer que el tope de la pila apunte al siguiente elemento.
       5. Decrementar el contador (cnt).
       6. Liberar la memoria (free) del nodo temporal.
       7. Retornar el dato.
    */
    DATO retorno;
    ELEMENTO *temporal;
    temporal = stk->tope;
    retorno= stk->tope->d;
    stk->tope=stk->tope->siguiente;
    stk->cnt--;
    free(temporal);
    temporal=NULL;
    return  retorno;
    
}

// Funcion estavacia
int estavacia(PILA *stk) {
    /* TODO: Retornar VERDADERO si el contador es 0, FALSO de lo contrario. */
    if(stk->cnt==0){
        return 1;
    }
    return 0;
}


// =========================================================
// SECCIÓN 2: LÓGICA DE ALTO NIVEL (DESCRIPCIÓN INCLUIDA)
// =========================================================


/**
 * TAREA PRINCIPAL: Determinar si la cadena es palíndromo.
 * Estrategia sugerida:
 * 1. Recorrer la cadena y meter cada letra en la PILA A.
 * 2. Pasar la mitad de la PILA A a una PILA B para comparar 
 * (o usar una estrategia de inversión total).
 */
int esPalindromo(char cadena[]) {
    PILA invertida;
    inicializar(&invertida);

    int i, longitud = strlen(cadena);
    char cadenaLimpia[100]; // Para guardar la frase sin espacios ni mayúsculas
    int n = 0;

    // 1. Limpiar la cadena y meter caracteres a la PILA
    for (i = 0; i < longitud; i++) {
        if (isalpha(cadena[i])) {
            char letra = tolower(cadena[i]);
            cadenaLimpia[n++] = letra; // Guardamos el orden normal
            push(&invertida, letra);    // Al meterlo a la pila, el primero en salir será el último
        }
    }

    // 2. Comparar la cadena limpia contra la pila (que sale al revés)
    for (i = 0; i < n; i++) {
        // Sacamos el carácter del tope (que es el último de la frase original)
        char letraInvertida = pop(&invertida); 
        
        // Comparamos con el carácter en la posición i (el primero de la frase)
        if (cadenaLimpia[i] != letraInvertida) {
            return 0; // En cuanto uno no coincida, no es palíndromo
        }
    }

    return 1; // Si terminó el ciclo, coinciden todos
}

int main() {
    char prueba1[] = "Anita lava la tina";
    char prueba2[] = "Estructuras de Datos";

    printf("--- TEST DE PALINDROMOS ---\n");
    
    printf("Prueba 1: '%s' -> %s\n", prueba1, 
           esPalindromo(prueba1) ? "ES PALINDROMO" : "NO ES PALINDROMO");
           
    printf("Prueba 2: '%s' -> %s\n", prueba2, 
           esPalindromo(prueba2) ? "ES PALINDROMO" : "NO ES PALINDROMO");

    return 0;
}
