#include <stdio.h>

int main(void) {
    int zahl;

    printf("Gib eine ganze Zahl ein: ");
    scanf("%d", &zahl);

    // Mal nehmen mit 4 (2 ist binär 4) + 3 nur mit bitshift operatoren
    int ergebnis = (zahl << 2) | 3;  // 3 in Binär = 11 direkt auf die unteren 2 Bits setzen

    printf("(%d * 4) + 3 = %d\n", zahl, ergebnis);

    return 0;
}
