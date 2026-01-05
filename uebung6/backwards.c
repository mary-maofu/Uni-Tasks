#include <stdio.h>

// Prozedur
void reversePrint(char *str) {
    // Zuerst zum Ende des Strings gehen
    char *end = str;
    while (*end != '\0') {
        end++;
    }
    end--; // Zurück 
    
    // Jetzt von hinten nach vorne ausgeben
    while (end >= str) {
        printf("%c", *end);
        end--;
    }
    printf("\n");
}

int main() {
    char text[100];
    
    printf("Text eingeben: ");
    fgets(text, 100, stdin);
    
    // Newline am Ende entfernen (falls vorhanden)
    int i = 0;
    while (text[i] != '\0') i++;
    if (i > 0 && text[i-1] == '\n') text[i-1] = '\0';
    
    printf("Rückwärts: ");
    reversePrint(text);
    
    return 0;
}