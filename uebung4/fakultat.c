#include <stdio.h>

int main(void) {
    int n;
    int fakultaet = 1;

    printf("Gib eine Zahl ein: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        fakultaet *= i;  
    }

    printf("%d! = %d\n", n, fakultaet);

    return 0;
}
