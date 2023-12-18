#include <stdio.h>
#include <iostream>

void update(int *a,int *b) {
    int sum = (*a) + (*b);
    int abs_diff = abs(*a - *b);
    //std::cout << abs_diff << std::endl;
    *a = sum;
    *b = abs_diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
