#include <stdio.h>
#include <ctype.h>
#include <math.h>

//Introduim les dades de la prima base
const int prima_base[5][2] = {
    {50000, 90},
    {100000, 160},
    {150000, 225},
    {200000, 280},
    {300000, 390}
};

int main() {
    // Imprimir benvinguda
    printf("******************************************\n*** BENVINGUTS A ASSEGURANCES SAFELIFE ***\n******************************************\n");

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
        while (getchar() != '\n');
        printf("\n3. El client és fumador? (S/N): ");
        if (scanf("%c", &fumador) != 1) {
            printf ("Error: introdueix S o N.\n");
            
            while (getchar() != '\n');
        }
    
        else if (fumador != 'S' && fumador != 'N' && fumador != 's' && fumador != 'n') {
            printf ("Error: introdueix S o N.\n");
        }
        else if (fumador == 's' || fumador == 'n') {
            fumador = toupper(fumador);
            break;
        }
        else {
            break;
        }
    }

    // Demanar pes
    float pes;
    while (1) {
        printf("\n4. Introdueix el pes del client (kg): ");
        if (scanf("%f", &pes) != 1) {
            printf ("Error: introdueix un valor numèric entre 30 i 200.\n");
            
            while (getchar() != '\n');
        }
    
        else if (pes <= 30 || pes >= 200) {
            printf ("Error: introdueix un valor numèric entre 30 i 200.\n");
        }
        else {
            break;
        }
    }
    
    // Demanar alçada
    float alcada;
    while (1) {
        printf("\n5. Introdueix l'alçada del client en metres (1.00 - 2.50): ");
        if (scanf("%f", &alcada) != 1) {
            printf ("Error: introdueix un valor numèric entre 1.00 i 2.50.\n");
            
            while (getchar() != '\n');
        }
    
        else if (alcada < 1.00 || alcada > 2.50) {
            printf ("Error: introdueix un valor numèric entre 1.00 i 2.50.\n");
        }
        else {
            break;
        }
    }

    // Calcular IMC
    float imc = pes / (pow(alcada, 2));

    // Demanar professió al client
    int professio;
    while (1) {
        printf("\n6. Introdueix la professió del client:\n          1 - Administració, informàtica, docència\n          2 - Transport, indústria, manteniment\n          3 - Construcció en altura, bombers, mineria\n");
        printf("Escull una opció (1-3): ");
        if (scanf("%d", &professio) != 1) {
            printf ("Error: introdueix un valor numèric entre 1 i 3.\n");
            while (getchar() != '\n');
        }
        else if (professio < 1 || professio > 3) {
            printf ("Error: introdueix un valor numèric entre 1 i 3.\n");
        }
        else {
            break;
        }
    }

    // Demanar esport al client
    char esport;
    while (1) {
        while (getchar() != '\n');
        printf("\n7. Practica esports de risc? (S/N): ");
        if (scanf("%c", &esport) != 1) {
            printf ("Error: introdueix S o N.\n");
            while (getchar() != '\n');
        }
        else if (esport != 'S' && esport != 'N' && esport != 's' && esport != 'n') {
            printf ("Error: introdueix S o N.\n");
        }
        else if (esport == 's' || esport == 'n') {
            esport = toupper(esport);
            break;
        }
        else {
            break;
        }
    }


    // Inicialitzem el modificador de preu com un enter a 0
    int modificador_factors = 0;

    // Modificador per edat
    if (edat >= 18 && edat <= 29) {
        modificador_factors -= 10;
    } else if (edat >= 40 && edat <= 49) {
        modificador_factors += 25;
    } else if (edat >= 50 && edat <= 59) {
        modificador_factors += 60;
    } else if (edat >= 60 && edat <= 65) {
        modificador_factors += 110;
    } else if (edat >= 66 && edat <= 70) {
        modificador_factors += 180;
    }

    // Modificador per fumador
    if (fumador == 'S') {
        modificador_factors += 45;
    }

    // Modificador per IMC
    if (imc < 18.5) {
        modificador_factors += 15;
    } else if (imc >= 25 && imc < 30) {
        modificador_factors += 10;
    } else if (imc >= 30) {
        modificador_factors += 30;
    }

    // Modificador per professió
    if (professio == 2) {
        modificador_factors += 15;
    } else if (professio == 3) {
        modificador_factors += 40;
    }

    // Modificador per esport
    if (esport == 'S') {
        modificador_factors += 20;
    }


    // Calcular la prima final
    float prima_final = prima_base[capital - 1][1] * (1 + (modificador_factors / 100.0));
    
    // Calcular modificador modalitat
    float modificador_modalitat[3][2] = {
        {1, 1},      // Basica
        {2, 1.3},   // Ampliada
        {3, 1.55},    // Premium
    };

    

    // Calcular fraccionament
    float modificador_fraccionament[4][2] = {
        {1, 1},      // Anual
        {2, 1.03},   // Semestral
        {4, 1.05},    // Trimestral
        {12, 1.08},    // Mensual
    };

    // Prima final
    float taula_final[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
        taula_final[i][j] = ((prima_final * modificador_modalitat[i][1]) * modificador_fraccionament[j][1])/modificador_fraccionament[j][0];
        }
    }    


    
    return 0;
}