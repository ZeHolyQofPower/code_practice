int combinations(std::vector<int> items) {
	// I gotta figure out the math first
	// Sets of one
	// return the value itself
	// Sets of two
	// multiply
	// Sets of three
	// multiply, but ignore zeros
	// This isn't a combination or permutation?
	int running_product = 1;
	for (int i = 0; i < items.size(); i++) {
		if (items[i] != 0) {
			running_product *= items[i];
		}
	}
	return running_product;
}
