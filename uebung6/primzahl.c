#include <stdio.h>
#include <stdbool.h>

bool istPrimzahl(int n) {
    // Sonderfall
    if (n <= 1) return false;
    
    // Prüfe alle möglichen Teiler
    for (int teiler = 2; teiler < n; teiler++) {
        if (n % teiler == 0) {
            return false;  
        }
    }
    
    return true; 
}

int main() {
    int zahl;
    
    printf("Gib eine Zahl ein: ");
    scanf("%d", &zahl);
    
    if (istPrimzahl(zahl)) {
        printf("%d ist eine Primzahl!\n", zahl);
    } else {
        printf("%d ist keine Primzahl.\n", zahl);
    }
    
    return 0;
}