bubbleSort.o: bubbleSort.cpp
	g++ -c bubbleSort.cpp -I/usr/share/SFML/include

app: bubbleSort.o
	g++ bubbleSort.o -o -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o app