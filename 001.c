#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int rand_number = rand()%101;
    int input_number = 0;
    int i = 0;

    for (i = 0; i <= 4; i++) {

        scanf("%d", &input_number);

        if (rand_number != input_number) {
            if (rand_number < input_number) {
                printf("您猜的数字[大于]随机产生的数字！\n");
            }

            if (rand_number > input_number) {
                printf("您猜的数字[小于]随机产生的数字！\n");
            }
        }
        else if (rand_number == input_number){
            printf("你赢了!\n");
            return 0;
        }
    } 

    printf("你输了!\n");
    printf("正确的数字是：%d\n", rand_number);

    return 0;
}
