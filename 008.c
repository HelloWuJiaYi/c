#include <stdio.h>

int res(int number) {
    if (number > 1) 
       return number * res(number - 1); 
}

int main() {
    int number_input = 0;
    scanf("%d",&number_input);
    printf("%d! = %d", number_input, res(number_input));
    return 0;
}
