// aufgabe 2
#include <stdio.h>

int main(void) {
    // bei bitshift geht nur int deshalb werden die zahlen ohne kommastelle berechnet
    int zahl;

    printf("Gib eine ganze Zahl ein: ");
    scanf("%d", &zahl);

    int ergebnis = zahl >> 3; // entspricht division durch 8

    printf("%d / 8 = %d\n", zahl, ergebnis);

    return 0;
}

