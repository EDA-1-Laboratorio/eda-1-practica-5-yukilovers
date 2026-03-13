/* Una implementación de calculadora de notación polaca */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define EMPTY 0
#define FULL 10000

struct dato {
    enum tipo {OPERADOR, VALOR} tipo; // El operador "enum" enlista los elementos de un conjunto. En este caso, el conjunto es {OPERADOR, VALOR} (de manera interna, se refiere al mismo con el nombre "tipo"), y el operador "enum" asigna automáticamente a cada elemento un valor entero, comenzando desde 0. Por lo tanto, "OPERADOR" tendrá el valor 0 y "VALOR" tendrá el valor 1. Esto permite que el programa distinga entre los dos tipos de datos que se pueden almacenar en la pila: operadores y valores. 
    union {
        char op;
        int val;
    } u; // La unión "union" permite almacenar diferentes tipos de datos en el mismo espacio de memoria. En este caso, puede almacenar un operador (char) o un valor (int), pero no ambos al mismo tiempo. Esto optimiza el uso de memoria y permite que la estructura "dato" represente tanto operadores como valores.
};

typedef struct dato DATO; // Define un nuevo tipo de dato llamado "DATO" que es una estructura que contiene un tipo (OPERADOR o VALOR) y una unión que puede almacenar un operador o un valor.
typedef enum {FALSO, VERDADERO} BOOLEAN; // Define un nuevo tipo de dato llamado "BOOLEAN" que es un enumerado con dos valores: FALSO (0) y VERDADERO (1). Esto se utiliza para representar valores booleanos en el programa, facilitando la lectura y comprensión del código al usar términos más descriptivos en lugar de números enteros para representar estados booleanos.

struct elemento {
    DATO d; // Cada elemento de la pila contiene un dato, que puede ser un operador o un valor.
    struct elemento *siguiente; // Un puntero al siguiente elemento en la pila, lo que permite la estructura de datos de tipo pila (LIFO).
};

typedef struct elemento ELEMENTO; // Define un nuevo tipo de dato llamado "ELEMENTO" que es una estructura que contiene un dato y un puntero al siguiente elemento en la pila.

struct pila {
    int cnt; // Un contador que mantiene el número de elementos en la pila.
    ELEMENTO *tope; // Un puntero al elemento que está en la parte superior de la pila, lo que permite acceder al último elemento agregado.
};

typedef struct pila PILA; // Define un nuevo tipo de dato llamado "PILA" que es una estructura que contiene un contador y un puntero al tope de la pila.

BOOLEAN estavacia(PILA *stk); // Declaración de la función que verifica si la pila está vacía.
int evaluar(PILA *polaca); // Declaración de la función que evalúa la expresión en notación polaca utilizando la pila.
void rellenar(PILA *stk, const char *str); // Declaración de la función que llena la pila con los elementos de la expresión en notación polaca.
BOOLEAN estallena(PILA *stk); // Declaración de la función que verifica si la pila está llena.
void inicializar(PILA *stk); // Declaración de la función que inicializa la pila.
void push(PILA *stk, DATO x); // Declaración de la función que agrega un dato a la pila.
DATO pop(PILA *stk); // Declaración de la función que elimina y devuelve el dato en la parte superior de la pila.
DATO top(PILA *stk); // Declaración de la función que devuelve el dato en la parte superior de la pila sin eliminarlo.
void imprimir(DATO d); // Declaración de la función que imprime un dato, ya sea un operador o un valor.
void imprimirPila(PILA *stk); // Declaración de la función que imprime todos los elementos de la pila, desde el tope hasta el fondo.
