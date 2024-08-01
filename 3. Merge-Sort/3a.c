#include <stdio.h>
#include <math.h>

// Function to calculate f(n)
int f(int n) {
    return 7 * n * n + 7 * n + 5;
}

int c1_g(int n, int c1) {
    return c1 * n * n;
}

int c2_g(int n, int c2){
    return c2 * n * n;
}

int main() {
    int n, c1 = 1, c2 = 19;
    printf("n\tc1*g(n)\tf(n)\tc2*g(n)\n");
    for (n = 10; n <= 30; n++) {
        printf("%d\t%d\t%d\t%d\n", n, c1_g(n,c1), f(n), c2_g(n,c2));
    }
    return 0;
}