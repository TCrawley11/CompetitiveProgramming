#include <cstdio>
#include <cstdlib>

void increment(int *v) {
    (*v)++;
}

void update(int *a, int *b) {
    int temp = *a;
    *a += *b;
    *b -= temp;
    *b = std::abs(*b);
}

int main() {
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);

    //increment(&a);
    //printf("%d\n", a);  // Add newline

    update(&a, &b);
    printf("%d\n", a);  // Add newline
    printf("%d\n", b);  // Add newline
    return 0;
}

