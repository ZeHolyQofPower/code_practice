int quadraticEquation(int a, int b, int c) {
	int discriminant = ((b*b) - (4*a*c));
	// Algorithm for calculating a sqrt without math.h?
	double temp = 0.0;
	double sqrt = discriminant / 2.0;
	std::cout << "discriminant: " << discriminant << std::endl;
	// Iterate these two values back and forth.
	// Dividing the decimal by two until it divides with itself neatly.
	while (sqrt != temp) {
		temp = sqrt;
		sqrt = ( ((discriminant/temp) + temp)/2 );
	}
	std::cout << "sqrt: " << sqrt << std::endl;
	// -b +- sqrt / 2a
	int plus =( (-1*b + (int)sqrt)/(2*a) );
	int minus =( (-1*b - (int)sqrt)/(2*a) );
	std::cout << "plus: " << plus << std::endl;
	std::cout << "minus: " << minus << std::endl;
	return plus;
}
