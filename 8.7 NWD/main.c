#include <stdio.h>

int GCD(int a, int b){
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;
    if(b == 0 || a == 0){
        if(a > b)
            return a;
        else
            return b;
    }
    if(a == b)
        return a;
    if(a > b)
        return GCD(a - b, b);
    else
        return GCD(a, b - a);
}

int main() {
    int a;
    int b;
    printf("Podaj a: ");
    if(!scanf("%d", &a)){
        printf("Incorrect input");
        return 1;
    }

    printf("Podaj b: ");
    if(!scanf("%d", &b)){
        printf("Incorrect input");
        return 1;
    }
    printf("%d", GCD(a, b));
    return 0;
}
