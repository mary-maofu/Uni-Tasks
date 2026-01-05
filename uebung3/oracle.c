#include <stdio.h>

int main() {

    int iTeil1, iTeil2, iTeil3, iTeil4, iTeil5, iTeil6;

    printf("Gib eine Zahl für Teil 1 ein (1-5): ");
    scanf("%d", &iTeil1);

    printf("Gib eine Zahl für Teil 2 ein (1-5): ");
    scanf("%d", &iTeil2);

    printf("Gib eine Zahl für Teil 3 ein (1-5): ");
    scanf("%d", &iTeil3);

    printf("Gib eine Zahl für Teil 4 ein (1-8): ");
    scanf("%d", &iTeil4);

    printf("Gib eine Zahl für Teil 5 ein (1-12): ");
    scanf("%d", &iTeil5);

    printf("Gib eine Zahl für Teil 6 ein (1-5): ");
    scanf("%d", &iTeil6);

    printf("\nIhr Orakelspruch:\n\n");

    switch(iTeil1) {
        case 1: printf("Heute Abend "); break;
        case 2: printf("Morgen "); break;
        case 3: printf("Übermorgen "); break;
        case 4: printf("Diese Woche "); break;
        case 5: printf("Dieses Jahr "); break;
    }

    switch(iTeil2) {
        case 1: printf("werden Sie "); break;
        case 2: printf("wird Ihre Frau "); break;
        case 3: printf("könnten Sie "); break;
        case 4: printf("werden Ihre Freunde "); break;
        case 5: printf("werden Sie mit Ihren Liebsten "); break;
    }

    switch(iTeil3) {
        case 1: printf("unmöglich "); break;
        case 2: printf("möglicherweise "); break;
        case 3: printf("mit hoher Wahrscheinlichkeit "); break;
        case 4: printf("sicherlich "); break;
        case 5: printf("ganz bestimmt "); break;
        case 6: printf("teilweise  "); break;
    }

    switch(iTeil4) {
        case 1: printf("Glück "); break;
        case 2: printf("eine Überraschung "); break;
        case 3: printf("eine Herausforderung "); break;
        case 4: printf("Freude "); break;
        case 5: printf("Schwierigkeiten "); break;
        case 6: printf("eine günstige Gelegenheit  "); break;
        case 7: printf("pech  "); break;
        case 8: printf("eine freudige Überraschung  "); break;
    }

    switch(iTeil5) {
    case 1:  printf("in der Gesundheit "); break;
    case 2:  printf("in finanziellen Belangen "); break;
    case 3:  printf("bei Nachbarn "); break;
    case 4:  printf("in familiären Belangen "); break;
    case 5:  printf("beim Computerspiel "); break;
    case 6:  printf("im Alltag "); break;
    case 7:  printf("in der Liebe "); break;
    case 8:  printf("im Sex "); break;
    case 9:  printf("bei der Sinnfindung "); break;
    case 10: printf("auf der Arbeit "); break;
    case 11: printf("im Freundeskreis "); break;
    case 12: printf("in der spirituellen Selbstverwirklichung "); break;
    }

    switch(iTeil6) {
    case 1: printf("haben.\n"); break;
    case 2: printf("erleben.\n"); break;
    case 3: printf("durchleben.\n"); break;
    case 4: printf("bekommen.\n"); break;
    case 5: printf("erhalten.\n"); break;
    }

    return 0;
}
