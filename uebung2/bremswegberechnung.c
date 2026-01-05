#include <stdio.h>

int main() {
    // Konstanten
    float fGeschwindigkeitKmH;
    float fGeschwindigkeitMs;
    float fWahrnehmungszeit = 1.0f;          // 1 Sekunde
    float fMuskelreaktionszeit = 0.7f;       // 0.7 Sekunden
    float fBremsansprechezeit = 0.2f;        // 0.2 Sekunden
    float fBremsansprechzeitDruckluft = 0.6f; // 9,6 Sekunden
    float fBremsverzoegerung = -7.72f;       // -7.72 m/s²
    float fWahrnehmungszeitGamer = 0.3f;
    int iSchneeEis;
    int iBremsenArt;
    int iAlkohol;
    int iGamer;
    int iTelefonat;

    // Variablen für die Wege
    float fWahrnehmungsweg;
    float fMuskelreaktionsweg;
    float fBremsanspracheweg;
    float fBremsweg;
    float fAnhalteweg;
    float fAktuelleBremsansprechzeit;
    
    // Eingabe der Geschwindigkeit
    printf("Geben Sie die Geschwindigkeit in km/h ein: ");
    scanf("%f", &fGeschwindigkeitKmH);
    fflush(stdin);

    // Geschwindigkeit von km/h in m/s umrechnen
    fGeschwindigkeitMs = fGeschwindigkeitKmH / 3.6f;

    // Welche Bremse?
    printf("hat der PKW eine hydraulische Bremse (1=ja, 0=nein): ");
    scanf("%i", &iBremsenArt);
    fflush(stdin);

        // Auswahl der richtigen Bremsansprechzeit
    if (iBremsenArt == 1) {
        fAktuelleBremsansprechzeit = fBremsansprechezeit;
    } else {
        fAktuelleBremsansprechzeit = fBremsansprechzeitDruckluft;
    }
 
    // Schnee und Eis
    printf("Schnee und Eis? (1=ja, 0=nein): ");
    scanf("%i", &iSchneeEis);
    fflush(stdin);
    // Alkohol
    printf("ist der Fahrer Alkoholisiert? (1=ja, 0=nein): ");
    scanf("%i", &iAlkohol);
    fflush(stdin);

    printf("ist der Fahrer professioneller Gamer? (1=ja, 0=nein):");
    scanf("%i", &iGamer);
    fflush(stdin);

    printf("Telefoniert der Fahrer? (1=ja, 0=nein): ");
    scanf("%i", &iTelefonat);
    fflush(stdin);

    //alkohol
    if (iAlkohol == 1) {
        fWahrnehmungszeit = fWahrnehmungszeit + 1.0f; 
    }   else { // das vllt unnötig
        fWahrnehmungszeit = fWahrnehmungszeit;
    }

    //alkohol und gamer
    if (iAlkohol == 1 && iGamer == 1) {
        fWahrnehmungszeitGamer = fWahrnehmungszeitGamer + 1.4f;
    }

    if (iGamer == 1) {
        fWahrnehmungszeit = fWahrnehmungszeitGamer;
    } else {
        fWahrnehmungszeit = fWahrnehmungszeit;
    }

    if (iTelefonat == 1) {
        fWahrnehmungszeit = 6.0f;
    }

    if (iTelefonat == 1 && iAlkohol == 1) {
         fWahrnehmungszeit = 8.0f;
    }


    // Berechnung der einzelnen Wege
    fWahrnehmungsweg = fGeschwindigkeitMs * fWahrnehmungszeit;
    fMuskelreaktionsweg = fGeschwindigkeitMs * fMuskelreaktionszeit;
    fBremsanspracheweg = fGeschwindigkeitMs * fAktuelleBremsansprechzeit;
    fBremsweg = (fGeschwindigkeitMs * fGeschwindigkeitMs) / (-2.0f * fBremsverzoegerung);

    // Bremsweg verlängern wenn Schnee und Eis
    if (iSchneeEis == 1) {
        fBremsweg = fBremsweg * 8.0f;
    }
    
    // berechnung gesamter anhalteweg
    fAnhalteweg = fWahrnehmungsweg + fMuskelreaktionsweg + fBremsanspracheweg + fBremsweg;
    
    // ausgabe
    printf("\nanhalteweg\n");
    printf("Geschwindigkeit: %.2f km/h (%.2f m/s)\n", fGeschwindigkeitKmH, fGeschwindigkeitMs);
    printf("Wahrnehmungsweg: %.2f m\n", fWahrnehmungsweg);
    printf("Muskelreaktionsweg: %.2f m\n", fMuskelreaktionsweg);
    printf("Bremsanspracheweg: %.2f m\n", fBremsanspracheweg);
    printf("Bremsweg: %.2f m\n", fBremsweg);
    printf("Gesamter Anhalteweg: %.2f m\n", fAnhalteweg);
    // printf("test");
    
    return 0;
}
