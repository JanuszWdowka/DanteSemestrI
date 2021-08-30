#include <stdio.h>

unsigned int my_strlen(const char tab[]){
    int dlugosc = 0;
    for(int i = 0; tab[i] != '\0'; ++i){
        dlugosc++;
    }
    return dlugosc;
}
int my_atoi(const char tab[]){
    int wynik = 0;
    int znak;
    int i = 0;
    if(tab[0] < 45 || tab[0] == 46 || tab[0] == 47 || tab[0] > 57 || tab[0] == '\0')
        return 0;
    else if(tab[0] == '-'){
        znak = -1;
        ++i;
    }
    else
        znak = 1;
    for (; tab[i] != '\0' && tab[i] != 46; ++i){
        if (tab[i] < '0' || tab[i] > '9')
            break;
        wynik = wynik * 10 + (tab[i] - '0');
    }
    return wynik * znak;
}
float my_atof(const char tab[]){
    float wynik = 0;
    int znak;
    int i = 0;
    float j = 10.0;
    if(tab[0] < 45 || tab[0] == 46 || tab[0] == 47 || tab[0] > 57 || tab[0] == '\0')
        return 0;
    else if(tab[0] == '-'){
        znak = -1;
        ++i;
    }
    else
        znak = 1;
    for (; tab[i] != '\0' && tab[i] != 46; ++i){
        if (tab[i] < '0' || tab[i] > '9')
            break;
        wynik = wynik * 10 + (tab[i] - '0');
    }
    ++i;
    for (; tab[i] != '\0'; ++i, j *= 10){
        if (tab[i] < '0' || tab[i] > '9')
            break;
        wynik = wynik + ((tab[i] - '0') / j);
    }
    return wynik * znak;
}
int main() {
    char liczba[16];
    printf("podaj liczbe: ");
    fgets(liczba, 16, stdin);
    int dlugosc = my_strlen(liczba);
    if(dlugosc > 1 && dlugosc != 15)
        dlugosc--;
    printf("%d\n", dlugosc);
    printf("%d\n", my_atoi(liczba));
    printf("%.4f", my_atof(liczba));
    return 0;
}
