#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    char geschlecht;
    struct Person* vater;
    struct Person* mutter;
    struct Person* kinder[10];
    int anzahlKinder;
} Person;

Person* aktuell;

Person* erstellePerson(const char* name, char geschlecht) {
    Person* neu = (Person*)malloc(sizeof(Person));
    strcpy(neu->name, name);
    neu->geschlecht = geschlecht;
    neu->vater = NULL;
    neu->mutter = NULL;
    neu->anzahlKinder = 0;
    
    for (int i = 0; i < 10; i++) {
        neu->kinder[i] = NULL;
    }
    
    return neu;
}

void verbindeEltern(Person* kind, Person* vater, Person* mutter) {
    if (kind != NULL) {
        kind->vater = vater;
        kind->mutter = mutter;
    }
    
    if (vater != NULL && vater->anzahlKinder < 10) {
        vater->kinder[vater->anzahlKinder] = kind;
        vater->anzahlKinder++;
    }
    
    if (mutter != NULL && mutter->anzahlKinder < 10) {
        mutter->kinder[mutter->anzahlKinder] = kind;
        mutter->anzahlKinder++;
    }
}

void erstelleKoeniglicheFamilie() {
    // Queen Elizabeth II und Prinz Philip
    Person* queen = erstellePerson("Queen Elizabeth II", 'F');
    Person* philip = erstellePerson("Prinz Philip", 'M');
    
    // Ihre Kinder
    Person* charles = erstellePerson("König Charles III", 'M');
    Person* anne = erstellePerson("Prinzessin Anne", 'F');
    Person* andrew = erstellePerson("Prinz Andrew", 'M');
    Person* edward = erstellePerson("Prinz Edward", 'M');
    
    // Verbinde Queen und Philip mit ihren Kindern
    verbindeEltern(charles, philip, queen);
    verbindeEltern(anne, philip, queen);
    verbindeEltern(andrew, philip, queen);
    verbindeEltern(edward, philip, queen);
    
    // Diana und Camilla
    Person* diana = erstellePerson("Diana, Princess of Wales", 'F');
    Person* camilla = erstellePerson("Camilla, Queen Consort", 'F');
    
    // Kinder von Charles und Diana
    Person* william = erstellePerson("Prinz William", 'M');
    Person* harry = erstellePerson("Prinz Harry", 'M');
    
    verbindeEltern(william, charles, diana);
    verbindeEltern(harry, charles, diana);
    
    // Ehepartner von William und Harry
    Person* kate = erstellePerson("Catherine, Princess of Wales", 'F');
    Person* meghan = erstellePerson("Meghan, Duchess of Sussex", 'F');
    
    // Kinder von William und Kate
    Person* george = erstellePerson("Prinz George", 'M');
    Person* charlotte = erstellePerson("Prinzessin Charlotte", 'F');
    Person* louis = erstellePerson("Prinz Louis", 'M');
    
    verbindeEltern(george, william, kate);
    verbindeEltern(charlotte, william, kate);
    verbindeEltern(louis, william, kate);
    
    // Kinder von Harry und Meghan
    Person* archie = erstellePerson("Archie Mountbatten-Windsor", 'M');
    Person* lilibet = erstellePerson("Lilibet Mountbatten-Windsor", 'F');
    
    verbindeEltern(archie, harry, meghan);
    verbindeEltern(lilibet, harry, meghan);
    
    // Setze Startpunkt auf Prinz Harry
    aktuell = harry;
}

void zeigeAktuellePerson() {
    printf("\n=== AKTUELLE PERSON ===\n");
    printf("Name: %s\n", aktuell->name);
    printf("Geschlecht: %c\n", aktuell->geschlecht);
    
    if (aktuell->vater != NULL) {
        printf("Vater: %s\n", aktuell->vater->name);
    }
    
    if (aktuell->mutter != NULL) {
        printf("Mutter: %s\n", aktuell->mutter->name);
    }
    
    if (aktuell->anzahlKinder > 0) {
        printf("Kinder (%d):\n", aktuell->anzahlKinder);
        for (int i = 0; i < aktuell->anzahlKinder; i++) {
            printf("  %d. %s\n", i+1, aktuell->kinder[i]->name);
        }
    }
    printf("=======================\n");
}

int main() {
    erstelleKoeniglicheFamilie();
    
    char eingabe;
    
    printf("=== KÖNIGLICHES AHNENNETZWERK ===\n");
    printf("Startpunkt: Prinz Harry\n");
    
    while (1) {
        zeigeAktuellePerson();
        
        printf("\nNavigation:\n");
        printf("V - Vater\nM - Mutter\n1-9 - Kind\nH - Zu Harry zurück\nQ - Beenden\n");
        printf("Eingabe: ");
        scanf(" %c", &eingabe);
        
        switch (eingabe) {
            case 'Q':
            case 'q':
                return 0;
                
            case 'H':
            case 'h':
                aktuell = erstellePerson("Prinz Harry", 'M');
                erstelleKoeniglicheFamilie();
                break;
                
            case 'V':
            case 'v':
                if (aktuell->vater) {
                    aktuell = aktuell->vater;
                    printf("Zum Vater gesprungen.\n");
                } else {
                    printf("Vater unbekannt.\n");
                }
                break;
                
            case 'M':
            case 'm':
                if (aktuell->mutter) {
                    aktuell = aktuell->mutter;
                    printf("Zur Mutter gesprungen.\n");
                } else {
                    printf("Mutter unbekannt.\n");
                }
                break;
                
            case '1':
                if (aktuell->anzahlKinder >= 1) {
                    aktuell = aktuell->kinder[0];
                }
                break;
                
            case '2':
                if (aktuell->anzahlKinder >= 2) {
                    aktuell = aktuell->kinder[1];
                }
                break;
                
            default:
                printf("Ungültige Eingabe.\n");
        }
    }
    
    return 0;
}