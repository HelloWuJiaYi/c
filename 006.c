#include <stdio.h>
#include <string.h>

int main(){
    char str_input[100] = "";
    char * p = str_input;
    int len = 0;

    scanf("%s", p);

    len = strlen(p);

    for (int i = len - 1; i >= 0; i--){
        printf("%c", *(p+i));
    }
    printf("\n");

    return 0;
}
