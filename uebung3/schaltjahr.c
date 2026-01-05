#include <stdio.h>

int main(void) {
    int jahr;

    printf("Gebe ein Jahr ein: ");
    scanf("%d", &jahr);

    // wenn der rest 0 ist ist es teilbar und somit ein schaltjahr
    if ((jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0)) {
        printf("%d ist ein Schaltjahr.\n", jahr);
    } else {
        printf("%d ist kein Schaltjahr.\n", jahr);
    }

    return 0;
}
