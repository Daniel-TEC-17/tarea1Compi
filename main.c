#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double evaluar(char *expresion) {
    char *token, *resto;
    double resultado, num1, num2;
    int longitud, i;
    const double pi = 3.14159265358979323846;
    const double e = 2.71828182845904523536;

    // Se analiza la expresión por partes separadas por espacios
    token = strtok(expresion, " ");
    while (token != NULL) {
        // Si el token es un número, se convierte a un valor double y se apila en la pila
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            resultado = strtod(token, &resto);
        }
        // Si el token es "pi", se apila el valor de pi en la pila
        else if (strcmp(token, "pi") == 0) {
            resultado = pi;
        }
        // Si el token es "e", se apila el valor de e en la pila
        else if (strcmp(token, "e") == 0) {
            resultado = e;
        }
        // Si el token es una función, se evalúa el argumento y se aplica la función a él
        else if (strcmp(token, "sin") == 0) {
            token = strtok(NULL, " ");
            num1 = evaluar(token);
            resultado = sin(num1);
        }
        else if (strcmp(token, "cos") == 0) {
            token = strtok(NULL, " ");
            num1 = evaluar(token);
            resultado = cos(num1);
        }
        else if (strcmp(token, "ln") == 0) {
            token = strtok(NULL, " ");
            num1 = evaluar(token);
            resultado = log(num1);
        }
        else if (strcmp(token, "exp") == 0) {
            token = strtok(NULL, " ");
            num1 = evaluar(token);
            resultado = exp(num1);
        }
        // Si el token es un operador, se apilan los dos números superiores en la pila,
        // se realiza la operación, y se apila el resultado en la pila
        else {
            num2 = evaluar(strtok(NULL, " "));
            num1 = resultado;
            if (strcmp(token, "+") == 0) {
                resultado = num1 + num2;
            }
            else if (strcmp(token, "-") == 0) {
                resultado = num1 - num2;
            }
            else if (strcmp(token, "*") == 0) {
                resultado = num1 * num2;
            }
            else if (strcmp(token, "/") == 0) {
                resultado = num1 / num2;
            }
            else if (strcmp(token, "^") == 0) {
                resultado = pow(num1, num2);
            }
        }

        token = strtok(NULL, " ");
    }

    return resultado;
}
void eliminar_espacios(char *expresion) {
    int i, j;
    for (i = 0, j = 0; expresion[i] != '\0'; i++) {
        if (expresion[i] != ' ' && expresion[i] != '\t') {
            expresion[j++] = expresion[i];
        }
    }
    expresion[j] = '\0';
}
// Función principal que lee la entrada del usuario y llama a la función evaluar()
int main() {
    char expresion[100];

    printf("Ingrese una expresion aritmetica: ");
    fgets(expresion, 100, stdin);

    eliminar_espacios(expresion);

    printf("Resultado: %lf\n", evaluar(expresion));

    return 0;
}

