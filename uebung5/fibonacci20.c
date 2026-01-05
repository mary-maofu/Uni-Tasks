#include <stdio.h>

int main(void) {
    // Array
    int fibonacci[20];
    
    // Die ersten beiden zahlen setzen - zählt später weiter
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    // Die restlichen zahlen in den array rein bis 20
    for (int i = 2; i < 20; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    
    // Ausgabe
    printf("Die ersten 20 Fibonacci-Zahlen:\n");
    for (int i = 0; i < 20; i++) {
        printf("F(%d) = %d\n", i, fibonacci[i]);
    }
    
    return 0;
}