#include "String.h"
#include <stdlib.h>

int main()
{
    string palabra;
    string adivinar;
    int intento = 1;
    int turno = 5;

    printf("Jugador 1 ingrese la palabra de 5 letras: ");
    strCrear(palabra);
    scan(palabra);

    while(strLargo(palabra) != 5){
        printf("La palabra debe contener 5 caracteres\n");
        printf("Ingrese nuevamente una palabra: ");
        scan(palabra);
    }

    while(!soloLetras(palabra)){
        printf("La palabra solo debe contener letras\n");
        printf("Ingrese nuevamente una palabra: ");
        scan(palabra);
    }

    printf("\n");
    convertirMayus(palabra);

    do{
        system("cls");
        printf("Intento %d/4 \n", intento++);

        printf("Jugador 2 ingrese la palabra de 5 letras: ");
        strCrear(adivinar);
        scan(adivinar);

        while(strLargo(adivinar) != 5){
            printf("La palabra debe contener 5 caracteres\n");
            printf("Ingrese nuevamente una palabra: ");
            scan(adivinar);
        }

        while(!soloLetras(adivinar)){
            printf("La palabra solo debe contener letras\n");
            printf("Ingrese nuevamente una palabra: ");
            scan(adivinar);
        }

        printf("\n");
        convertirMayus(adivinar);

        if(strEq(palabra,adivinar)){
            printf("Palabra original: ");
            print(palabra);
            printf("\n");
            printf("Tu intento: ");
            print(adivinar);
            printf("\nADIVINASTE!!!!");
            intento = 5;
        }else{
            printf("Tu intento: ");
            imprimirCoincidencias(palabra,adivinar);
            printf("\n");
            noEsParte(palabra,adivinar);

            if(intento == turno){
                printf("Perdiste\n");
                printf("La palabra era: ");
                print(palabra);
            }
        }
        printf("\nPresione ENTER para continuar\n");
        fflush(stdin);
        getchar();
    }while(intento < turno);
}
