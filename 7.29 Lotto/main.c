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

int main() {
    int liczby[6];
    generate(liczby, 6, 1, 49);
    display_vector(liczby, 6);
    return 0;
}
