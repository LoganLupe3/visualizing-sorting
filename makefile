app: bubbleSort.o
	g++ bubbleSort.o -o -I/usr/share/SFML/include -lsfml-graphics -lsfml-window -lsfml-system


bubbleSort.o: bubbleSort.cpp
	g++ -c bubbleSort.cpp -I/usr/share/SFML/include

clean:
	rm *.o app