#include <stdio.h>

int f(int n) {
    return 4 * n + 3;
}

int g(int n, int c) {
    return c * n;
}

int main() {
    int n, c = 7;
    printf("n\tf(n)\tc*g(n)\n");
    for (n = 10; n <= 30; n++) {
        printf("%d\t%d\t%d\n", n, f(n), g(n, c));
    }
    return 0;
}