#include <stdio.h>

int main() {

    //exta implementierung der Points
    int iPlayerPoints = 0;

    //erste frage
    int iAntwort; 

    printf("Willkommen zu: Wer wird Informatiker?\n");
    printf("Frage 1: Wer ist the unkillable demon king?\n");
    printf("1) Hans Sama\n");
    printf("2) Michael Jackson\n");
    printf("3) Faker\n");
    printf("4) Ronaldo\n");

    printf("Gib deine Antwort als Zahl ein (1-4): ");
    scanf("%d", &iAntwort);

    switch(iAntwort) {
        case 1:
            printf("Du hast Hans Sama gewaehlt.\n");
            printf("das ist leider falsch.:( )");
            break;

        case 2:
            printf("Du hast Michael Jackson gewaehlt.\n");
            printf("das ist leider falsch. :( )");
            break;

        case 3:
            printf("Du hast Faker gewaehlt.\n");
            printf("das ist Richtig!. :) ");
            iPlayerPoints++;
            break;

        case 4:
            printf("Du hast Ronaldo gewaehlt.\n");
            printf("das ist leider falsch. :( )");
            break;
        
        //rest der eingaben
        default:
            printf("Ungueltige Eingabe!\n");
    }
     
   // return 0 würde hier das programm beenden und keine weiteren fragen zulassen

    //eingabe leeren
    fflush(stdin);

    //zweite frage
    
    int iAntwort2;
    printf("Nun die zweite Frage\n");
    printf("Frage 2: Wie alt ist gianni?\n");
    printf("1) 19\n");
    printf("2) 26\n");
    printf("3) 24\n");
    printf("4) 22\n");

    printf("Gib deine Antwort als Zahl ein (1-4): ");
    scanf("%d", &iAntwort2);

    switch(iAntwort2) {

        case 1:
            printf("du hast 19 gewählt.\n das ist leider falsch :( \n)");
            break;

        case 2: 
            printf("du hast 26 gewählt. \n das ist richtig! :) \n");
            iPlayerPoints++;
            break;

        case 3: 
            printf("du hast 24 gewählt. \n das ist leider falsch :( \n");
            break;
        case 4:
            printf("du hast 22 gewählt. \n das ist leider falsch :( \n");
            break;

    default:
            printf("Ungueltige Eingabe!\n");
               break;

    }   
   //eingabe leeren
    fflush(stdin);

    //frage 3

    int iAntwort3;
    printf("Frage 3: Was ist Marys lieblingsspiel? ;)\n");
    printf("1) Minecraft\n");
    printf("2) TFT\n");
    printf("3) Valorant\n");
    printf("4) League of Legends\n");

    printf("Gib deine Antwort als Zahl ein (1-4): ");
    scanf("%d", &iAntwort3);

    switch(iAntwort3) {
        case 1:
            printf("Du hast Minecraft gewaehlt.\n");
            printf("das ist leider falsch.:( \n)");
            break;

        case 2:
            printf("Du hast TFT gewaehlt.\n");
            printf("das ist leider falsch. :( \n)");
            break;

        case 3:
            printf("Du hast Valorant gewaehlt.\n");
            printf("das ist leider falsch. :( \n");
            break;

        case 4:
            printf("Du hast League of Legends gewaehlt.\n");
            printf("das ist Richtig!. :) \n");
            iPlayerPoints++;
            break;
        
        //rest der eingaben
        default:
            printf("Ungueltige Eingabe!\n");
    }

    int iAntwort4;
    printf("Frage 3: Wer ist gemein? ;)\n");
    printf("1) die Frau in der Mensa\n");
    printf("2) Marie\n");
    printf("3) Arber\n");
    printf("4) die Frau im S Gebäude\n");

    printf("Gib deine Antwort als Zahl ein (1-4): ");
    scanf("%d", &iAntwort4);

        switch(iAntwort4) {
        case 1:
            printf("Du hast die Frau in der Mensa gewaehlt.\n");
            printf("das ist leider falsch.:( \n)");
            break;

        case 2:
            printf("Du hast Marie gewaehlt.\n");
            printf("das ist leider falsch. :( \n)");
            break;

        case 3:
            printf("Du hast Arber gewaehlt.\n");
            printf("das ist leider falsch. :( \n)");
            break;

        case 4:
            printf("Du hast die Frau im S Gebäude gewaehlt.\n");
            printf("das ist Richtig!. :) \n");
            iPlayerPoints++;
            break;
        
        //rest der eingaben
        default:
            printf("Ungueltige Eingabe!\n");
    }
    printf("du hast insgesamt %d der Fragen richtig beantwortet!\n", iPlayerPoints);

    //4fun implementierung der punkte
    if(iPlayerPoints == 4) {
    printf("Perfekt! Du bist ein wahrer Informatiker!\n");
    } else if (iPlayerPoints == 3 || iPlayerPoints == 2) {
        printf("Ganz okay, aber da geht noch mehr!\n");
        } 
            else {
                printf("Das war wohl nix... Versuch's nochmal! :)\n");
            }
            return 0;
}

