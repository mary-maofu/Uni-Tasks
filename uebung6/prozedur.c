#include <stdio.h>

void toUpperCaseRef(char *c) {
    if (*c >= 'a' && *c <= 'z') *c -= 32;
}

int main() {
    char text[100];
    
    printf("Text eingeben: ");
    fgets(text, 100, stdin);
    
    for (int i = 0; text[i]; i++) {
        toUpperCaseRef(&text[i]);
    }
    
    printf("Großbuchstaben: %s", text);
    
    return 0;
}
