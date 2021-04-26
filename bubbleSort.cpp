#include <iostream>

void bubbleSort(int *array){
    int temp, i, j;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
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