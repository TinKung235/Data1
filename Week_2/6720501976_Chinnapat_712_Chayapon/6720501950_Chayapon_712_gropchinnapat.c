#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxdiff2(int x[], int n) {
    int i, max, min, maxdiff;
    max = x[0];
    min = x[0];
    for(i = 1; i < n; i++) {
        if(x[i] > max) max = x[i];
        if(x[i] < min) min = x[i];
    }
    maxdiff = max - min;
}

int main() {
    int T = 3200;
    int n = T;
    srand(time(NULL));
    
    printf("n\tTime_maxdiff2(seconds)\n");
    
    while(n <= 250000) {
        int *arr = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }
        clock_t start = clock();
        maxdiff2(arr, n);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, time_spent);
        
        free(arr);
        n *= 2;
    }
    
    return 0;
}