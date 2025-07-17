#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int numCompare = 0, numSwap = 0;

void SelectionSort(int A[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            numCompare++;
            if (A[j] < A[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = temp;
            numSwap++;
        }
    }
}

void InsertionSort(int A[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0) {
            numCompare++;
            if (A[j] > key) {
                A[j + 1] = A[j];
                numSwap++;
                j--;
            } else
                break;
        }
        A[j + 1] = key;
    }
}

void BubbleSort(int A[], int n) {
    int i, j, temp, flag;
    for (i = 0; i < n-1; i++)
    {
        flag = 0;
        for (j = 0; j < n-i-1; j++)
        {
            numCompare++;
            if (A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                numSwap++;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void DisplayArray(int A[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]); 
    printf("\n");
}
    
int main() {
    int A[] = {19,25 ,11 ,14 ,19 ,19 ,26 ,17 ,27 ,10};
    int i;
    srand((unsigned) time(NULL));
    for (i=0; i< MAX; i++)
     A[i] = rand()%30 +1;
    DisplayArray(A, MAX);
    SelectionSort(A, MAX);
    DisplayArray(A, MAX);
    printf("%d\n",numCompare);
    printf("%d",numSwap);
    return 0;
}