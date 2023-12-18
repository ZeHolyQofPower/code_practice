#include <cstdio>
#include <iostream>
#include <vector>   // Using vectors for data storage and passing.
#include <algorithm>    // Using for cleaning input whitespace.

void print_contiguous_subarrays(const std::vector<int>& base_vector);

int main(int argc, char** argv) {
    // Rather than using console into cin and torturing myself...
    // Here's a hardcoded case in a driver.
    /**
     * 0 1 2
     * 
     * 0    0 1     0 1 2
     * 1    1 2
     * 2
    */
    if (argc) { /* Lazy warning surpression */ }
    // Fun bug of the day: argv will contain previous CLI garbage if you go past or try to count argc.
    if (argv) {}
    std::vector<int> input_vector;
    for (size_t i = 0; i < 3; i++) {
        input_vector.push_back(2 + i);
        //std::cout << (2 + i) << std::endl;
    }
    input_vector.push_back(-8);
    input_vector.push_back(17);
    input_vector.push_back(100);
    input_vector.push_back(0);
    // LETS PRETEND, I got info from the CLI correctly...
    /*
    size_t input_length = atoi(argv[0]);
    string argv_zero_string_t(argv[0]); // String class constructor can take a char*
    // To my knowledge, this should be the cleaning whitespace standard...
    string::iterator end_pos = remove(argv_zero_string_t.begin(), argv_zero_string_t.end(), ' ');
    argv_zero_string_t.erase(end_pos, argv_zero_string_t.end());
    size_t input_length = stoi(argv_zero_string_t);
    cout << "input_length: " << input_length << endl;
    */
    // Do the do
    print_contiguous_subarrays(input_vector);
    return 0;
}

void print_contiguous_subarrays(const std::vector<int>& base_vector) {
    // Loop through every element.
    for (size_t i = 0; i < base_vector.size(); i++) {
        // Loop through the remaining elements to reach the end.
        for (size_t j = i; j < base_vector.size(); j++) {
            // Loop through the number of values in each set
            for (size_t k = i; k < j+1; k++) {
                std::cout << base_vector[k] << " ";
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }
    return;
}