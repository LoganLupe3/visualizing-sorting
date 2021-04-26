app: bubbleSort.o
	g++ bubbleSort.o -o -lsfml-graphics -lsfml-window -lsfml-system


bubbleSort.o: bubbleSort.cpp
	g++ -c bubbleSort.cpp -I/usr/share/SFML/include

clean:
	rm *.o app