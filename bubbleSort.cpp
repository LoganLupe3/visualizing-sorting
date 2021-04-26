#include <iostream>

void bubbleSort(int *array){

}

int main(){
    srand(time(NULL));

    int *array = new int[10];
    for(int i = 0; i < 10; i++){
        array[i] = rand() % 10;
    }

    printf("Unsorted:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    bubbleSort(array);

    printf("Sorted:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}