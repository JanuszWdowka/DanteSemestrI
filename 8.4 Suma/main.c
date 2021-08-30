#include <stdio.h>

unsigned long sum_rec(int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return 0;

    return n + sum_rec(n - 1);
}

int main() {
    int liczba;
    printf("Podaj liczbę, dla której chcesz policzyć sumę: ");
    if(!scanf("%d", &liczba)){
        printf("Incorrect input");
        return 1;
    }
    if(liczba < 1){
        printf("Incorrect input data");
        return 2;
    }
    printf("%lu", sum_rec(liczba));
    return 0;
}
