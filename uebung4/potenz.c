#include <stdio.h>

int main(void) {
    int basis, exponent;
    // darf nicht 0 sein sonst bleibt alles immer 0
    int ergebnis = 1;

    printf("Basis eingeben: ");
    scanf("%d", &basis);

    printf("Exponent eingeben: ");
    scanf("%d", &exponent);

    // die multiplikation - nimmt das ergebnis der i potenz mit den weitern * bis es am ende angekommen ist
    for (int i = 0; i < exponent; i++) {
        ergebnis *= basis;
    }

    printf("%d hoch %d = %d\n", basis, exponent, ergebnis);

    return 0;
}
