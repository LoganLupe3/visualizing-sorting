app: bubbleSort.o
	g++ bubbleSort.o -o app -lsfml-graphics -lsfml-window -lsfml-system


bubbleSort.o: bubbleSort.cpp
	g++ -c bubbleSort.cpp

clean:
	rm *.o app