#include <stdio.h>

int main() {
    int zahl = 2000000000; // 2 Milliarden
    
    printf("Startwert: %d\n", zahl);
    
    // Immer weiter addieren bis ein Overflow passiert
    zahl = zahl + 500000000;
    printf("Nach +500 Millionen: %d\n", zahl);
    
    
    printf("Zahl wird negativ\n");
    
    return 0;  
}