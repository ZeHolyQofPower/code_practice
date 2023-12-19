# Link
dijkstra: dijkstra.o
	g++ -std=c++2a -Wall -Wextra -o $@ $<
# For c++20, g++ version 9 has a partial version.

# Compile
dijkstra.o: dijkstra.cpp
	g++ -std=c++2a -Wall -Wextra -c $<

# Clean
clean:
	rm ./*.o
	rm dijkstra