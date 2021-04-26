#include <iostream>
#include <SFML/Graphics.hpp>

void swap(int i, int j, int x, int y){

}

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
    //Create the window
    sf::RenderWindow window(sf::VideoMode(800,600), "test");

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

    while(window.isOpen()){
        sf::Event e;
        
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}