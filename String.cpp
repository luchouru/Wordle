#include "String.h"

void strCrear(string &s){
    s = new char[1];
    s[0] = '\0';
}

void strDestruir(string &s){
    delete [] s;
    s = NULL;
}

int strLargo(string s){
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strCop(string &s1, string s2){
    int i = 0;
    int largo = strLargo(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan(string &s){
    string aux = new char[MAX];
    int i=0;
    char c;
    fflush(stdin);
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
             strCop (s,aux);
             strDestruir (aux);
}

void print(string s){
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

boolean strEq(string s1,string s2){
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

boolean strMenor(string s1, string s2){
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;
    return menor;
}

void bajarString(string s, FILE * f){
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite (&s[i], sizeof(char), 1, f);
}

void levantarString(string &s, FILE * f){
    int i=0;
    string aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    strCop (s, aux);
    delete [] aux;
}

void convertirMayus(string &s){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 'a' && s[i] <='z')
            s[i] = s[i] - 32;
        i++;
    }
}

int convertirNumero(string s){
    int i = 0, digito, num = 0;

    while (s[i] != '\0'){
        digito = s[i] - 48;
        num = digito + 10 * num;
        i++;
    }
    return num;
}

void eliminarBlancosPrincipio(string s, string &sb){
    int largo = strLargo(s) + 1;
    int blanco = 0;

    while(s[blanco] == ' '){
        blanco++;
    }

    delete [] sb;
    sb = new char [largo - blanco];

    int i = 0;
    while(s[blanco] != '\0'){
        sb[i] = s[blanco];
        i++;
        blanco++;
    }
    sb[i] = '\0';
}

boolean soloNumeros(string s){
    int i = 0;
    boolean numeros = TRUE;
    while(numeros && s[i] != '\0'){
        if(!(s[i] >= '0' && s[i] <= '9'))
            numeros = FALSE;
        i++;
    }
    return numeros;
}

boolean soloLetras (string s){
    int i = 0;
    boolean letras = TRUE;
    while(letras && s[i] != '\0'){
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
            letras = FALSE;
        i++;
    }
    return letras;
}

void imprimirCoincidencias(string s1, string s2){
    int i = 0;
    while(s1[i] != '\0'){
        if(s1[i] == s2[i])
            printf("%c",s1[i]);
        else
            printf("_");
        i++;
    }
}

void noEsParte(string original, string intentar){
    int i = 0;
    while(original[i] != '\0'){
        if(original[i] != intentar[i]){
            char letra = intentar[i];
            if(!caracterExiste(letra,original))
                printf("la letra %c no es parte de la palabra\n", letra);
        }
        i++;
    }
}

boolean caracterExiste(char letra, string s){
    boolean existe = FALSE;
    int i = 0;
    while(s[i] != '\0'){
        if(letra == s[i])
            existe = TRUE;
        i++;
    }
    return existe;
}
