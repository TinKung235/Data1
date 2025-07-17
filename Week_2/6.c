#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxdiff1(int x[], int n) {
    int i, j, diff, max = 0;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            diff = abs(x[i] - x[j]);
            if(diff > max)
                max = diff;
        }
    }
}

int main() {
    int T = 3200;
    int n = T;
    srand(time(NULL));
    
    printf("n\tTime(seconds)\n");
    
    while(n <= 250000) {
        // สร้างและเติมอาเรย์ด้วยค่าสุ่ม
        int *arr = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }
        clock_t start = clock();
        maxdiff1(arr, n);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, time_spent);
        free(arr);
        n *= 2;
    }
    
    return 0;
}