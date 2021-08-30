#include <stdio.h>
#include <math.h>

float circumference(float b){
    float wynik;
    wynik = M_PI * b;
    if(wynik <= 0){
        return -1.0;
    }
    return wynik;
}

int main() {
    float d;
    float wynik;
    printf("Podaj srednice kola: ");
    if(!scanf("%f", &d)){
        d = -1.0;
    }
    wynik = circumference(d);
    if(wynik > 0){
        printf("Obwod kola to %f", wynik);
    }
    else{
        printf("Incorrect input");
        return 1;
    }
    return 0;
}
