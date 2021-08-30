#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_vector(const int vec[], int size){
    for(int i = 0; i < size; ++i){
        printf("%d ", vec[i]);
    }
}

int generate(int lotto[], int N, int start, int end){
    if(N < 1)
        return -1;
    else if(end < start)
        return -1;
    if((end > 0 && start > 0) || (end > 0 && start < 0)){
        if((end - start) < (N - 1)){
            return -1;
        }
    }
    else if (end < 0 && start < 0){
        if((end - start) < (N - 1)){
            return -1;
        }
    }

    srand(time(NULL));
    int suma = end - start;
    if(start < 0)
        suma = start - end;
    if(suma < 0)
        suma *= -1;
    start *= -1;
    for(int i = 0; i < N; ++i) {
        lotto[i] = (rand() % (suma + 1)) - start;
        if (i > 0) {
            for (int j = 0; j < i; ++j) {
                if (lotto[i] == lotto[j]) {
                    lotto[i] = (rand() % (suma + 1)) - start;
                    j = -1;
                }
            }
        }
    }

    return 0;
}

int vector_max_norm(const int tab[], int size){
    int max = tab[0];
    if(max < 0)
        max = -max;
    for(int i = 1; i < size; ++i){
        if(tab[i] < 0){
            if(max < -tab[i])
                max = -tab[i];
        }
        else
            if(max < tab[i])
                max = tab[i];
    }
    if(size < 1)
        max = 0;
    return max;
}

int vector_sum(const int tab[], int size){
    int suma = 0;
    for(int i = 0; i < size; ++i){
        suma += tab[i];
    }
    return suma;
}

int main() {
    int tab[100];
    int start;
    int end;
    int ilosc;
    printf("wprowadz a: ");
    if(!scanf("%d", &start)){
        printf("Incorrect input");
        return 1;
    }
    printf("wprowadz b: ");
    if(!scanf("%d", &end)){
        printf("Incorrect input");
        return 1;
    }
    printf("wprowadz liczbę elementów do wylosowania: ");
    if(!scanf("%d", &ilosc)){
        printf("Incorrect input");
        return 1;
    }
    if(ilosc > 100 || ilosc < 1){
        printf("Incorrect input data");
        return 2;
    }

    if(end < start){
        printf("Incorrect input data");
        return 2;
    }
    if((end > 0 && start > 0) || (end > 0 && start < 0)){
        if((end - start) < (ilosc - 1)){
            printf("Incorrect input data");
            return 2;
        }
    }
    else if (end < 0 && start < 0){
        if((end - start) < (ilosc - 1)){
            printf("Incorrect input data");
            return 2;
        }
    }

    generate(tab, ilosc, start, end);
    display_vector(tab, ilosc);
    printf("\n");
    printf("norma max wynosi %d\n", vector_max_norm(tab, ilosc));
    printf("suma wynosi %d\n", vector_sum(tab, ilosc));
    return 0;
}
