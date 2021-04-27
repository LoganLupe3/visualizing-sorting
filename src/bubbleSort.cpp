#include <iostream>
#include <vector>
#include <iterator>
#include <SFML/Graphics.hpp>

using namespace std;

vector<int> nums;
int size = 100;
int gap = 4;

void swap(int i, int j, int x, int y){

}

void bubbleSort(){
    int temp, i, j;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

int main(){
    //Create the window
    sf::RenderWindow window(sf::VideoMode(800,600), "test");
    sf::RectangleShape rect(sf::Vector2f(120, 50));
    rect.setSize(sf::Vector2f(100,100));

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
        window.draw(rect);
        window.display();
    }

    return 0;
}