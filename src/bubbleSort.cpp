/*
    Visualizing sorting algorithms
    Logan Lupeamanu
    https://github.com/LoganLupe3/visualizing-sorting
*/

#include <iostream>
#include <unistd.h>
#include <vector>
#include <iterator>
#include <SFML/Graphics.hpp>

using namespace std;

int *nums; //These numbers will determine the height of the rectangles that will be sorted
int size = 100;
int gap = 4;

void swap(int i, int j, sf::RectangleShape *rectangles){
    rectangles[i].setFillColor(sf::Color::Green);
    rectangles[j].setFillColor(sf::Color::Green);

    sf::Vector2f temp = rectangles[i].getPosition();
    rectangles[i].setPosition(rectangles[j].getPosition());
    rectangles[j].setPosition(temp);

    rectangles[i].setFillColor(sf::Color::White);
    rectangles[j].setFillColor(sf::Color::White);    
}

void bubbleSort(sf::RectangleShape *rectangles){
    int temp, i, j;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;

                swap(i, j, rectangles);
            }
        }
    }
}

int main(){
    int height = 600;
    int width = 800;
    //Allocate memory to nums
    nums = new int[size];

    sf::RectangleShape rectangles[size];

    //Create the window
    sf::RenderWindow window(sf::VideoMode(width,height), "test");

    srand(time(NULL));

    //Initialize array with random values (1-799 inclsive)
    for(int i = 0; i < size; i++){
        nums[i] = rand() % 599 + 1;
    }
    

    printf("Unsorted:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    /*
    bubbleSort();

    printf("Sorted:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    */
    
    usleep(200000);

    while(window.isOpen()){
        sf::Event e;
        
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //Draw rectangles
        bubbleSort(rectangles);
        int i, l;
        while (l < sizeof(rectangles) / sizeof(rectangles[0])) {
            rectangles[l].setSize(sf::Vector2f(3, nums[l]));

            rectangles[l].setPosition(i, height-599);

            window.draw(rectangles[l]);

            i += 7;

            l++;
        }
        i = 0;
        l = 0;

        /*
        for(int i = 0; i < size; i++){
            rectangles[i].setSize(sf::Vector2f(3.69, nums[i]));
            rectangles[i].setFillColor(sf::Color::White);
            rectangles[i].setPosition((i*7.69), 600);
            window.draw(rectangles[i]);
        }
        */

        window.display();
    }

    //Clean up allocated memory
    delete nums;

    return 0;
}