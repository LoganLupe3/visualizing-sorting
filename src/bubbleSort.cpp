/*
    Visualizing sorting algorithms
    Logan Lupeamanu
    https://github.com/LoganLupe3/visualizing-sorting
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <SFML/Graphics.hpp>

using namespace std;

int *nums; //These numbers will determine the height of the rectangles that will be sorted
int size = 100;
int gap = 4;

void swap(int i, int j, int x, int y){

}

void bubbleSort(){
    int temp, i, j;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

int main(){
    //Allocate memory to nums
    nums = new int[size];

    sf::RectangleShape rectangles[size];

    //Create the window
    sf::RenderWindow window(sf::VideoMode(800,600), "test");

    srand(time(NULL));

    //Initialize array with random values (1-100 inclsive)
    for(int i = 0; i < size; i++){
        nums[i] = rand() % 100 + 1;
    }
    

    printf("Unsorted:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    bubbleSort();

    printf("Sorted:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    while(window.isOpen()){
        sf::Event e;
        
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //Draw rectangles
        for(int i = 0; i < size; i++){
            rectangles[i].setSize(sf::Vector2f(7.69, nums[i]));
            rectangles[i].setPosition((i*7.69), 600);
            window.draw(rectangles[i]);
        }

        window.display();
    }

    //Clean up allocated memory
    delete nums;

    return 0;
}