#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define NUM_FIELDS 8
#define START_CAPITAL 1000      // 1000€ Start
#define MAX_DEBT 1              // Bei -1€ Schulden ist man raus

// Feldtypen
enum FieldType {
    FIELD_LOS,
    FIELD_CAFETERIA,
    FIELD_LAN_PARTY,
    FIELD_MENSA,
    FIELD_JACKPOT,
    FIELD_PARKTHEATER,
    FIELD_ZUR_LAN,
    FIELD_BIG_BOX
};

typedef struct {
    char name[50];
    enum FieldType type;
    int purchasePrice;
    int rentIncome;
    int owner;
} Field;

typedef struct {
    char name[50];
    int money;
    int position;
    int active;
} Player;

Field board[NUM_FIELDS];
Player players[MAX_PLAYERS];
int numPlayers;
int jackpotAmount;

void initializeBoard() {
    strcpy(board[0].name, "Los");
    board[0].type = FIELD_LOS;
    board[0].purchasePrice = 0;
    board[0].rentIncome = 0;
    board[0].owner = -1;

    strcpy(board[1].name, "FH Cafeteria");
    board[1].type = FIELD_CAFETERIA;
    board[1].purchasePrice = 800;      
    board[1].rentIncome = 400;        
    board[1].owner = -1;

    strcpy(board[2].name, "LAN-Party");
    board[2].type = FIELD_LAN_PARTY;
    board[2].purchasePrice = 0;
    board[2].rentIncome = 0;
    board[2].owner = -1;

    strcpy(board[3].name, "FH Mensa");
    board[3].type = FIELD_MENSA;
    board[3].purchasePrice = 1000;     
    board[3].rentIncome = 500;         
    board[3].owner = -1;

    strcpy(board[4].name, "Jackpot");
    board[4].type = FIELD_JACKPOT;
    board[4].purchasePrice = 0;
    board[4].rentIncome = 0;
    board[4].owner = -1;

    strcpy(board[5].name, "Parktheater");
    board[5].type = FIELD_PARKTHEATER;
    board[5].purchasePrice = 1500;     
    board[5].rentIncome = 750;         
    board[5].owner = -1;

    strcpy(board[6].name, "Zur Lan");
    board[6].type = FIELD_ZUR_LAN;
    board[6].purchasePrice = 0;
    board[6].rentIncome = 0;
    board[6].owner = -1;

    strcpy(board[7].name, "Big Box");
    board[7].type = FIELD_BIG_BOX;
    board[7].purchasePrice = 2000;     
    board[7].rentIncome = 1000;        
    board[7].owner = -1;

    jackpotAmount = 0;
}

void initializePlayers() {
    do {
        printf("Anzahl der Spieler (2-%d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
        while(getchar() != '\n');
    } while (numPlayers < 2 || numPlayers > MAX_PLAYERS);

    for (int i = 0; i < numPlayers; i++) {
        printf("Name von Spieler %d: ", i + 1);
        fgets(players[i].name, 50, stdin);
        
        int len = strlen(players[i].name);
        if (len > 0 && players[i].name[len-1] == '\n') {
            players[i].name[len-1] = '\0';
        }

        players[i].money = START_CAPITAL;
        players[i].position = 0;
        players[i].active = 1;
    }
    printf("\n");
}

int rollDice() {
    return (rand() % 6) + 1;
}

void movePlayer(int playerIndex, int steps) {
    int oldPosition = players[playerIndex].position;
    players[playerIndex].position = (players[playerIndex].position + steps) % NUM_FIELDS;

    if (players[playerIndex].position < oldPosition) {
        // Über Los: 200€ statt 20€
        printf(">>> %s kommt ueber Los und erhaelt 200 EUR!\n", players[playerIndex].name);
        players[playerIndex].money += 200;
    }
}

void handleField(int playerIndex) {
    Field* currentField = &board[players[playerIndex].position];

    printf("\n%s landet auf Feld %d: %s\n",
        players[playerIndex].name,
        players[playerIndex].position,
        currentField->name);

    switch (currentField->type) {
    case FIELD_LOS:
        printf("Du bist auf Los! Erhalte 400 EUR!\n");
        players[playerIndex].money += 400;
        break;

    case FIELD_LAN_PARTY:
        printf(">>> LAN-Party! Zahle 50 EUR Spende in den Gamer-Jackpot!\n");
        players[playerIndex].money -= 50;
        jackpotAmount += 50;
        printf("Jackpot steht nun bei: %d EUR\n", jackpotAmount);
        printf("%s setzt eine Runde aus!\n", players[playerIndex].name);
        break;

    case FIELD_JACKPOT:
        printf(">>> JACKPOT! %s gewinnt %d EUR!\n",
            players[playerIndex].name,
            jackpotAmount);
        players[playerIndex].money += jackpotAmount;
        jackpotAmount = 0;
        break;

    case FIELD_ZUR_LAN:
        printf(">>> Zur Lan! Gehe direkt zur LAN-Party!\n");
        printf("Du gehst nicht ueber LOS und ziehst nicht 200 EUR ein!\n");
        players[playerIndex].position = 2;
        // Direkt LAN-Party auslösen
        printf(">>> LAN-Party! Zahle 50 EUR Spende!\n");
        players[playerIndex].money -= 50;
        jackpotAmount += 50;
        printf("Jackpot steht nun bei: %d EUR\n", jackpotAmount);
        printf("%s setzt eine Runde aus!\n", players[playerIndex].name);
        break;

    default:
        // Kaufbare Felder
        Field* currentField = &board[players[playerIndex].position];

        if (currentField->owner == -1) {
            printf("Dieses Feld kostet %d EUR.\n", currentField->purchasePrice);
            printf("Dein Kontostand: %d EUR\n", players[playerIndex].money);
            printf("Moechtest du kaufen? (1=Ja, 0=Nein): ");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                if (players[playerIndex].money >= currentField->purchasePrice) {
                    players[playerIndex].money -= currentField->purchasePrice;
                    currentField->owner = playerIndex;
                    printf(">>> %s kauft %s fuer %d EUR!\n",
                        players[playerIndex].name,
                        currentField->name,
                        currentField->purchasePrice);
                }
                else {
                    printf("Nicht genug Geld!\n");
                }
            }
        }
        else if (currentField->owner == playerIndex) {
            printf("Dies ist dein eigenes Feld.\n");
            printf("Moechtest du renovieren? (1=Ja, 0=Nein): ");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                // Renovierung kostet viel
                int renovationCost = currentField->purchasePrice;
                int rentIncrease = renovationCost / 2;
                
                printf("Renovierungskosten: %d EUR\n", renovationCost);
                printf("Mietpreis steigt um: %d EUR\n", rentIncrease);
                printf("Dein Kontostand: %d EUR\n", players[playerIndex].money);
                printf("Bestaetigen? (1=Ja, 0=Nein): ");
                
                scanf("%d", &choice);
                
                if (choice == 1 && players[playerIndex].money >= renovationCost) {
                    players[playerIndex].money -= renovationCost;
                    currentField->rentIncome += rentIncrease;
                    printf(">>> Renovierung abgeschlossen! Neue Miete: %d EUR\n",
                        currentField->rentIncome);
                }
                else if (choice == 1) {
                    printf("Nicht genug Geld!\n");
                }
            }
        }
        else {
            // Miete zahlen - DAS MACHT SCHULDEN!
            int rent = currentField->rentIncome;
            printf(">>> %s zahlt %d EUR Miete an %s!\n",
                players[playerIndex].name,
                rent,
                players[currentField->owner].name);

            players[playerIndex].money -= rent;
            players[currentField->owner].money += rent;
        }
        break;
    }
}

void printPlayerStatus() {
    printf("\n========== SPIELERSTATUS ==========\n");
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].active) {
            printf("%s: Position %d, Geld: %d EUR\n",
                players[i].name,
                players[i].position,
                players[i].money);
        }
        else {
            printf("%s: AUSGESCHIEDEN (%d€ Schulden)\n", 
                   players[i].name, players[i].money);
        }
    }
    printf("===================================\n\n");
}

int checkGameOver() {
    int activePlayers = 0;
    int winner = -1;

    for (int i = 0; i < numPlayers; i++) {
        if (players[i].active) {
            activePlayers++;
            winner = i;
        }
    }

    if (activePlayers == 1) {
        printf("\n\n====================================\n");
        printf("   SPIEL BEENDET! ⚡\n");
        printf("   Gewinner: %s\n", players[winner].name);
        printf("   Endkapital: %d EUR\n", players[winner].money);
        printf("====================================\n");
        return 1;
    }

    return 0;
}

void playGame() {
    int round = 0;
    char enter[2];

    printf("\n⚡ TURBO-MODUS: Spiel endet bei -1€ Schulden! ⚡\n");
    printf("Preise sind HOCH, Startgeld ist NIEDRIG!\n\n");

    while (1) {
        round++;
        printf("\n\n******** RUNDE %d ********\n", round);

        for (int i = 0; i < numPlayers; i++) {
            if (!players[i].active) continue;

            printf("\n--- %s ist am Zug (%d€) ---\n", 
                   players[i].name, players[i].money);
            printf("Druecke Enter zum Wuerfeln...");
            fgets(enter, 2, stdin);

            int dice = rollDice();
            printf("Gewuerfelt: %d\n", dice);

            movePlayer(i, dice);
            handleField(i);

          
            if (players[i].money < -MAX_DEBT) {
                printf("\n %s hat %d€ SCHULDEN und scheidet aus!\n",
                    players[i].name, players[i].money);
                players[i].active = 0;

                // Felder freigeben
                for (int j = 0; j < NUM_FIELDS; j++) {
                    if (board[j].owner == i) {
                        board[j].owner = -1;
                        // Mieten zurücksetzen
                        switch (board[j].type) {
                            case FIELD_CAFETERIA: board[j].rentIncome = 400; break;
                            case FIELD_MENSA: board[j].rentIncome = 500; break;
                            case FIELD_PARKTHEATER: board[j].rentIncome = 750; break;
                            case FIELD_BIG_BOX: board[j].rentIncome = 1000; break;
                            default: board[j].rentIncome = 0; break;
                        }
                    }
                }
            }

            printPlayerStatus();

            if (checkGameOver()) {
                return;
            }
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));

    printf("====================================\n");
    printf("   MINIPOLY  \n");
    printf("====================================\n\n");

    initializeBoard();
    initializePlayers();
    playGame();

    return 0;
}