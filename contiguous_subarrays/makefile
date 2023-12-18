# Link
contiguous_subarrays: contiguous_subarrays.o
	g++ -std=c++2a -Wall -Wextra -o $@ $<
# For c++20, g++ version 9 has a partial version.

# Compile
contiguous_subarrays.o: contiguous_subarrays.cpp
	g++ -std=c++2a -Wall -Wextra -c $<

# Clean
clean:
	rm ./*.o
	rm contiguous_subarrays