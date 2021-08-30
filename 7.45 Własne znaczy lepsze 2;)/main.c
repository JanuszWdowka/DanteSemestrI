#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

int my_strcmp(const char tab[], const char tab2[]){
    int prawda = 1;
    int znak = 0;
    do{
        if(tab2[znak] != tab[znak]){
            prawda = 0;
            break;
        }
        znak++;
    }while (tab2[znak] != '\0' && tab[znak] != '\0' && tab2[znak] == tab[znak]);
    if(tab[znak] == '\0' && tab2[znak] == '\0' && prawda == 1)
        return 0;
    else{
        if(tab[znak] < tab2[znak])
            return -1;
        else
            return 1;
    }

}
int my_strncmp(const char tab[], const char tab2[], unsigned int n){
    if(n <= 0){
        printf("Incorrect input");
        return 1;
    }
    int prawda = 1;
    unsigned int znak = 0;
    do{
        if(tab2[znak] != tab[znak]){
            prawda = 0;
            break;
        }
        znak++;
    }while (znak < n);
    if(prawda)
        return 0;
    else{
        if(tab[znak] < tab2[znak])
            return -1;
        else
            return 1;
    }
}

int main() {
    char tekst1[101];
    char tekst2[101];
    char c;
    bool ilosc_znakow;
    int liczba;
    printf("Podaj tekst:\n");
    scanf("%100[^\n]s", tekst1);
    //fgets(tekst1, 101, stdin);
    while((c = getchar()) != '\n' && c != EOF);
    printf("Podaj drugi tekst:\n");
    //fgets(tekst2, 101, stdin);
    scanf("%100[^\n]s", tekst2);
    while((c = getchar()) != '\n' && c != EOF);
    //scanf("%100[^\n]s", tekst2);
    printf("%s\n %s\n", tekst1, tekst2);
    printf("Podaj liczbe znakow do porownania:\n");
    ilosc_znakow = scanf("%d", &liczba);
    if(!ilosc_znakow || liczba < 0){
        printf("incorrect input");
        return 1;
    }
    printf("strcmp %d\n", my_strcmp(tekst1, tekst2));
    printf("strncmp ");
    if(liczba <= 100)
        printf(" %d\n", my_strncmp(tekst1, tekst2, liczba));
    else
        printf(" %d\n", my_strncmp(tekst1, tekst2, 100));

    return 0;
}