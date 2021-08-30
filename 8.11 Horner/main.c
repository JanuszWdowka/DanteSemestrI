#include <stdio.h>

int read_vector_double(double vec[], int size, double stop_value)
{
    if(size <= 0) return -1;

    int x = 0;
    char c;

    for (int i = 0; i < size; i++)
    {
        if(scanf("%lf", &vec[i]) != 1)
        {
            return -2;
        }

        if(vec[i] == stop_value) break;
        else x++;
    }
    while((c = getchar()) != '\n' && c != EOF);
    return x;
}

double horner(double a[], double x, int n)
{
    if(n <= 0) return -1;


    if (n==1) return a[0];
    return x * horner(a, x, n-1) + a[n-1];
}

int main ()
{
    double vec[100];
    double x;

    printf("Podaj wspolczynniki wielomianu:\n");
    int size = read_vector_double(vec, 100, 0);

    if(size == -2)
    {
        printf ("Incorrect input\n");
        return 1;
    }

    if(size == 0)
    {
        printf("Not enough data available");
        return 3;
    }

    printf("Podaj zmienna x:\n");
    if(!scanf("%lf", &x))
    {
        printf ("Incorrect input\n");
        return 1;
    }
    printf("w = %.2lf\n", horner(vec, x, size));

    return 0;
}