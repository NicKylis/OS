#include <stdio.h>
#include <stdlib.h>

void add(int num1, int num2, int num3, int *sum){
   *sum = num1 + num2 + num3;
}

int main(int argc, char *argv[]){
    if(argc!= 4){
        printf("Usage: ./add <num1> <num2> <num3>");
        exit(-1);
    }

    int num1, num2, num3, sum;
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    num3 = atoi(argv[3]);
   
    add(num1, num2, num3, &sum);
    printf("The sum of the 3 inputs is: %d\n", sum);
    return 0;
}
