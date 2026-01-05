#include <stdio.h>

// Prozedur aus Aufgabe 1b
void toUpperCaseRef(char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 32;
    }
}

// Prozedur für ganze Zeichenketten
void stringToUpperCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        toUpperCaseRef(&str[i]);
        i++;
    }
}

int main() {
    char text[100];  // Platz für Eingabe (max 99 Zeichen)
    
    printf("Gib einen Text ein: ");
    fgets(text, 100, stdin);  // Liest Text mit Leerzeichen
    
    // fgets speichert auch Enter (\n) am Ende -> entfernen
    int i = 0;
    while (text[i] != '\0') {
        i++;
    }
    if (i > 0 && text[i-1] == '\n') {
        text[i-1] = '\0';  // \n durch Stringende ersetzen
    }
    
    stringToUpperCase(text);
    printf("In Großbuchstaben: %s\n", text);
    
    return 0;
}