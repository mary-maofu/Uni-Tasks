#include <stdio.h>

int main(void) {
    // Startwerte der Aufgabe
    double dHoehe = 1000.0;       // starthöhe in m
    double dGeschw = -200.0;      // negative geschw. = es fällt
    double dFuel = 8165.0;         // SW d Treibstoffmasse
    double dLeermasse = 1855.0;    // Leermasse
    // konstanten
    const double dGravitation = 1.63;    // Mondgravitation
    const double dSchub = 5000.0;        // Schubkonstante
    const double rm = 1738000.0;         // Mondradius in Metern
    const double maxSchub = 44316.0;    // NASA-Daten
    const double maxVerbrauch = maxSchub / dSchub;  // ≈ 12.31 kg/s
    const double dt = 1.0;

    while (dHoehe > 0) { // solange die höhe über 0 ist wird der code weiter laufen

        double dMasse = dLeermasse + dFuel; // Berechnung der Masse


        double r = rm + dHoehe;     // Abstand Mondmittelpunkt
        double dGatm = dGravitation  * (rm * rm) / (r * r); // g(h) (gravitationatm)

        printf("Hoehe: %.2f m\n", dHoehe);
        printf("Geschwindigkeit: %.2f m/s\n", dGeschw);
        printf("Treibstoff: %.2f kg\n", dFuel);

        // spieler eingabe
        double dVerbrauch;
        printf("Wieviel Treibstoff pro Sekunde verbrennen? ");
        scanf("%lf", &dVerbrauch);

        // Verbrauch begrenzen
        if (dVerbrauch < 0) dVerbrauch = 0;
        if (dVerbrauch > dFuel) dVerbrauch = dFuel;

        // Formeln

        // Schubkraft - Levitation
        double dFS = dVerbrauch * dSchub;

        // Gravitationskraft
        double dFG = dMasse * dGatm;   

        // Gesamtkraft
        double dFges = dFS - dFG;

        // Beschleunigung
        double dBes = dFges / dMasse;

        // geschw und höhe ändern


        dGeschw += dBes * dt;
        dHoehe  += dGeschw * dt;


        // treibstoff verbrauch
        dFuel -= dVerbrauch;

        // sicherstellen das die höhe nicht unter 0 geht
        if (dHoehe <= 0) {
            dHoehe = 0;
            break;
        }
    }

    printf("\nlandung\n");
    printf("Aufprallgeschwindigkeit: %.2f m/s\n", dGeschw);

    if (dGeschw > -5.0) {
        printf("Perfekte Landung!\n");
    } else if (dGeschw > -20.0) {
        printf("Harte Landung, aber noch überlebt\n");
    } else {
        printf("CRASH! du bist gestorben\n");
    }
    


    printf("\nStartphase\n");
    printf("wir sind auf der Mondoberfläche.\n");

    dGeschw = 0;   // sitzt am Boden
    dHoehe = 0;

    while (dHoehe < 10000) {   // Erfolg bei 10000 m

        double dMasse = dLeermasse + dFuel;
        double r = rm + dHoehe;
        double dGatm = dGravitation * (rm * rm) / (r * r);

        printf("Hoehe: %.2f m\n", dHoehe);
        printf("Geschwindigkeit: %.2f m/s\n", dGeschw);
        printf("Treibstoff: %.2f kg\n", dFuel);

        double dVerbrauch;
        printf("Treibstoff pro Sekunde (START): ");
        scanf("%lf", &dVerbrauch);

        if (dVerbrauch < 0) dVerbrauch = 0;
        if (dVerbrauch > dFuel) dVerbrauch = dFuel;

        double dFS = dVerbrauch * dSchub;
        double dFG = dMasse * dGatm;
        double dBes = (dFS - dFG) / dMasse;

        dGeschw += dBes * dt;
        dHoehe += dGeschw * dt;

        dFuel -= dVerbrauch;

        if (dFuel <= 0) {
            printf("Treibstoff leer! Du kommst nicht mehr weg!\n");
            return 0;
        }
    }

    printf("\nStart Erfolgreich!\n");

    return 0;

}


//9mal401mal121mal40