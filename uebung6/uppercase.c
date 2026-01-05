#include <stdio.h>

char toUpperCase(char c) {
    // Prüfen, ob es sich um einen Kleinbuchstaben handelt
    if (c >= 'a' && c <= 'z') {
        // Kleinbuchstabe in Großbuchstabe umwandeln
        // ASCII: 'a'=97, 'A'=65 -> Unterschied 32
        return c - 32;
    } else {
        // Kein Kleinbuchstabe -> unverändert zurückgeben
        return c;
    }
}

int main() {
    char c; 
    printf("Gib ein Zeichen ein: ");
    scanf(" %c", &c); 
    // Funktion aufrufen und Ergebnis speichern
    char ergebnis = toUpperCase(c);
    
    // Ergebnis ausgeben
    printf("Großbuchstabe: %c\n", ergebnis);
    
    return 0;
}