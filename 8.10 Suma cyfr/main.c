#include <stdio.h>

int sum_of_digits(long long number){
    if(number < 0)
        number = -number;
    if(number == 0)
        return 0;
    return (number % 10) + sum_of_digits(number / 10);
}

int main() {
    long long a;
    printf("Podaj liczbe: ");
    if(!scanf("%lld", &a)){
        printf("Incorrect input");
        return 1;
    }
    printf("%d", sum_of_digits(a));
    return 0;
}
