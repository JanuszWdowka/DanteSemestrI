#include <stdio.h>
#include <stdbool.h>

int sign(int value){
    switch (value < 0){
        case true:
        return -1;
    }
    switch (value == 0){
        case true:
        return 0;
    }
        return 1;
}

int main() {
    int liczba;
    int wynik;
    printf("Podaj liczbe: ");
    switch (!scanf("%d", &liczba)){
        case true:
        printf("Incorrect input");
        return 1;
    }
    wynik = sign(liczba);
    switch (wynik) {
        case 1: printf("positive"); break;
        case 0: printf("zero"); break;
        case -1: printf("negative"); break;
    }
    return 0;
}
