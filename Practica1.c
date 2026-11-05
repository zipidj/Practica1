#include <stdio.h>

//Introduim les dades de la prima base
int prima_base[5][2] = {
    {50000, 90},
    {100000, 160},
    {150000, 225},
    {200000, 280},
    {300000, 390}
};

int main() {
    // Imprimir benvinguda
    printf("***************************************\n***Benvingut a Assegurances SafeLife***\n***************************************\n");

    // Demanar edat del client
    int edat;

    //Fem un bucle per assegurar una data correcta
    while (1) {
        printf("\n1. Introdueix la edat de la persona assegurada (18-70 anys): ");

        if (scanf("%d", &edat) != 1) {
            printf ("Error: introdueix un valor numèric entre 18 i 70.\n");
        
            while (getchar() != '\n');
        }
    
        else if (edat < 18 || edat > 70) {
            printf ("Error: introdueix un valor numèric entre 18 i 70.\n");
        }
        else {
            break;
        }
    }

    // Demanar capital assegurat (bucle per assegurar un altre cop)
    int capital;
    while (1) {
        printf("\n2. Introdueix el capital a assegurar:\n          1. 50.000€\n          2. 100.000€\n          3. 150.000€\n          4. 200.000€\n          5. 300.000€\n");
        printf("Escull una opció (1-5): ");
        
        if (scanf("%d", &capital) != 1) {
            printf ("Error: introdueix un valor numèric entre 1 i 5.\n");
            
            while (getchar() != '\n');
        }
    
        else if (capital < 1 || capital > 5) {
            printf ("Error: introdueix un valor numèric entre 1 i 5.\n");
        }
        else {
            break;
        }
    }

    // Verificar si el client és fumador (Ara amb bucle per assegurar que escrigui S o N)
    char fumador;
    while (1) {
        printf("\n3. El client és fumador? (S/N): ");
        if (scanf("%c", &fumador) != 1) {
            printf ("Error: introdueix S o N.\n");
            
            while (getchar() != '\n');
        }
    
        else if (fumador != 'S' && fumador != 'N') {
            printf ("Error: introdueix S o N.\n");
        }
        else {
            break;
        }
    }

    // Demanar pes
    float pes;
    return 0;
}