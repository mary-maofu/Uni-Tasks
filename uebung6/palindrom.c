#include <stdio.h>
#include <stdbool.h>  // Für bool-Typ

// Funktion die prüft ob ein String ein Palindrom ist
bool istPalindrom(char *str) {
    if (str == NULL) return false;
    
    // Anfang und Ende finden
    char *start = str;
    char *ende = str;
    
    // Zum Ende des Strings gehen
    while (*ende != '\0') {
        ende++;
    }
    ende--;  // Zurück vom Null-Terminator
    
    // Von beiden Seiten vergleichen
    while (start < ende) {
        if (*start != *ende) {
            return false;
        }
        start++;
        ende--;
    }
    
    return true;
}

int main() {
    char text[100];
    
    printf("Text eingeben: ");
    fgets(text, 100, stdin);
    
    // Newline am Ende entfernen
    int i = 0;
    while (text[i] != '\0') i++;
    if (i > 0 && text[i-1] == '\n') text[i-1] = '\0';
    
    if (istPalindrom(text)) {
        printf("'%s' ist ein Palindrom!\n", text);
    } else {
        printf("'%s' ist KEIN Palindrom.\n", text);
    }
    
    
    return 0;
}