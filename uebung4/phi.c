#include <stdio.h>

int main(void) {

    double f1 = 1;
    double f2 = 1;
    double phi, invphi;

    // Wir lassen die Fibonacci-Zahlen größer werden,
    // damit das Verhältnis Phi immer genauer wird.
    for(int i = 0; i < 50; i++) {
        double fneu = f1 + f2;
        f1 = f2;
        f2 = fneu;
    }

    // Phi ≈ F(n) / F(n-1)
    phi = f2 / f1;

    // 1/Phi
    invphi = 1.0 / phi;

    printf("Phi  ≈ %.7f\n", phi);
    printf("1/Phi ≈ %.7f\n", invphi);

    return 0;
}
