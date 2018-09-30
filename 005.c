#include <stdio.h>

int recur(int n) {
    printf("第%d级调用\n", n);
    if (n < 6) {
        recur(n + 1); 
    }
    printf("第%d级返回\n", n);
}

int main() {
    recur(1); 
    return 0;
}


