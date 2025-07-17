#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int findClosestPrime(int x) {
    if (isPrime(x)) return x;
    
    int lower = x - 1;
    int upper = x + 1;
    
    while (true) {
        if (lower >= 2 && isPrime(lower)) return lower;
        if (upper <= 2000000 && isPrime(upper)) return upper;
        lower--;
        upper++;
    }
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", findClosestPrime(x));
    return 0;
}