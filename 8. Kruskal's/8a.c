#include <stdio.h>

int f(int n) {
    return 6 * n * n + 2 * n + 2;
}

int g(int n, int c) {
    return c * n * n;
}

int main() {
    int n, c = 10;
    printf("n\tf(n)\tc*g(n)\n");
    for (n = 10; n <= 30; n++) {
        printf("%d\t%d\t%d\n", n, f(n), g(n, c));
    }
    return 0;
}