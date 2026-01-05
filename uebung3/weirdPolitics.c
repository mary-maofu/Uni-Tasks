#include <stdio.h>

int main() {

    int iTeil1, iTeil2, iTeil3, iTeil4;

    printf("Gib eine Zahl für Teil 1 ein (1-11): ");
    scanf("%d", &iTeil1);

    printf("Gib eine Zahl für Teil 2 ein (1-11): ");
    scanf("%d", &iTeil2);

    printf("Gib eine Zahl für Teil 3 ein (1-10): ");
    scanf("%d", &iTeil3);

    printf("Gib eine Zahl für Teil 4 ein (1-9): ");
    scanf("%d", &iTeil4);


    printf("\nIhr Redeinspirationsgenerator für einfallslose Politiker:\n\n");

    switch(iTeil1) {
        case 1:  printf("Die "); break;
        case 2:  printf("Diese "); break;
        case 3:  printf("Die asozialen "); break;
        case 4:  printf("Diese perfiden "); break;
        case 5:  printf("Die fehlgeleiteten "); break;
        case 6:  printf("Jene gewissenlosen "); break;
        case 7:  printf("Die konservativen "); break;
        case 8:  printf("Die illegalen "); break;
        case 9:  printf("Die vermummten "); break;
        case 10: printf("Die deutschen "); break;
        case 11: printf("Die immigrierten "); break;
    }


    switch(iTeil2) {
        case 1:  printf("Killerspieler "); break;
        case 2:  printf("Schläfer "); break;
        case 3:  printf("Terroristen "); break;
        case 4:  printf("Heuschrecken "); break;
        case 5:  printf("Anarchisten "); break;
        case 6:  printf("Rechtsradikalen "); break;
        case 7:  printf("Linkradikalen "); break;
        case 8:  printf("Ungeimpften "); break;
        case 9:  printf("Salafisten "); break;
        case 10: printf("Coronaleugner "); break;
        case 11: printf("Verschwörungstheoretiker "); break;
    }


    switch(iTeil3) {
        case 1:  printf("verunglimpfen "); break;
        case 2:  printf("unterminieren "); break;
        case 3:  printf("terrorisieren "); break;
        case 4:  printf("unterwandern "); break;
        case 5:  printf("infiltrieren "); break;
        case 6:  printf("bekämpfen "); break;
        case 7:  printf("unterstützen "); break;
        case 8:  printf("zersetzen "); break;
        case 9:  printf("verhöhnen "); break;
        case 10: printf("sind eine Gefahr für "); break;
    }


    switch(iTeil4) {
        case 1:  printf("Bayern "); break;
        case 2:  printf("die freiheitlich demokratische Grundordnung "); break;
        case 3:  printf("unser Wertesystem "); break;
        case 4:  printf("die westliche Demokratie "); break;
        case 5:  printf("den Mittelstand "); break;
        case 6:  printf("die soziale Marktwirtschaft "); break;
        case 7:  printf("die Bundesrepublik Deutschland "); break;
        case 8:  printf("die Freiheit "); break;
        case 9:  printf("uns "); break;
    }

    return 0;
}
