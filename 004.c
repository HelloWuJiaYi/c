#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int input_number =0;
    int temp = 0;
    int i = 0, j = 0;

    printf("请输入排序位数(100以内): ");
    scanf("%d",&input_number); 

    int array_rand[100] = {0};

    printf("排序前：");

    for (i = 0; i <= input_number - 1; i++) {
        array_rand[i] = rand()%90 + 10; 
        printf("%d ", array_rand[i]); 
    }

    printf("\n");

    for (i = 0; i <= input_number - 1; i++) {
        for (j = 0; j <= input_number - 2 - i; j++) {
            if (array_rand[j] > array_rand[j + 1]) {
                temp = array_rand[j]; 
                array_rand[j] = array_rand[j + 1]; 
                array_rand[j + 1] = temp; 
            } 
        }    
    }

    printf("升序  ：");
    
    for (i = 0; i <= input_number - 1; i++) {
        printf("%d ", array_rand[i]); 
    }

    printf("\n");

    for (i = 0; i <= input_number - 1; i++) {
        for (j = 0; j <= input_number - 2 - i; j++) {
            if (array_rand[j] < array_rand[j + 1]) {
                temp = array_rand[j]; 
                array_rand[j] = array_rand[j + 1]; 
                array_rand[j + 1] = temp; 
            } 
        }    
    }

    printf("降序  ：");
    
    for (i = 0; i <= input_number - 1; i++) {
        printf("%d ", array_rand[i]); 
    }

    printf("\n");

    return 0;
}
