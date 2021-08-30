#include <stdio.h>


float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;

}

float divide(float a, float b){
    if(b == 0){
        return -1;
    }
    return a / b;
}

int main() {
    float pierwsza;
    float druga;
    printf("Podaj pierwszą liczbę: ");
    if(!scanf("%f", &pierwsza)){
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj drugą liczbę: ");
    if(!scanf("%f", &druga)){
        printf("Incorrect input");
        return 1;
    }
    printf("Suma: %f\n", add(pierwsza, druga));
    printf("Różnica: %f\n", subtract(pierwsza, druga));
    printf("Iloczyn: %f\n", multiply(pierwsza, druga));
    if(druga != 0)
        printf("Iloraz: %f\n", divide(pierwsza, druga));
    else
        printf("operation not permitted");
    return 0;
}
