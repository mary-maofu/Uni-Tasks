#include <stdio.h>
#include "math.h"

int main()
{
    const double fFallbeschleunigungen [2] = {9.814, 9.802};             //m/s^2
    int Ort;
    double dHoehe, dFallzeit, dAufprallgeschwindigkeit_ms, dAufprallgeschwindigkeit_kmh;

    printf("\nOrt waelen (0 = Hamburg, 1 = Kempten)"); fflush(stdout);
    scanf("%d", &Ort);

    printf("\nGib die Hoehe in Meter an: "); fflush(stdout);
    scanf("%lf", &dHoehe); fflush(stdin);

    double fFallbeschleunigung = fFallbeschleunigungen[Ort];

    dFallzeit = sqrt(2.0*dHoehe/fFallbeschleunigung);                   // s
    dAufprallgeschwindigkeit_ms = fFallbeschleunigung*dFallzeit;        // m/s
    dAufprallgeschwindigkeit_kmh = dAufprallgeschwindigkeit_ms*3.6;     // km/h
    
    printf("\n\nDie Fallzeit (ohne Beruecksichtigung des Luftwiderstandes) betraegt %.2f Sekunden.\n",dFallzeit);
    printf("\nDie Aufprallgeschwindigkeit betraegt %.2f Meter pro Sekunde.\n",dAufprallgeschwindigkeit_ms);
    printf("\nDas entspricht %.2f Kilometer pro Stunde. \n ",dAufprallgeschwindigkeit_kmh);
    
    return 0;
}

