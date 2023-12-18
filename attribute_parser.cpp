#include <iostream> // Using cin, cout, and endl
#include <sstream>  // Using istringstream
#include <vector>   // Using vectors to store raw input.
#include <map>  // Using a map to store tags.
using namespace std;

void print_map(const map<string, string>& m);
void print_vector(const vector<string>& string_vector);

int main() {
    int number_of_lines = 0;    // 'N' in the prompt
    int number_of_queries = 0;            // 'Q' in the prompt
    cin >> number_of_lines >> number_of_queries;
    // Loop through and store all lines in a vector.
    string line = "";
    getline(cin, line); // getline takes stream to string
    // TODO Why? Is the above line needed?
    // Is it because getline starts from start of file regardless of cin's state?
    vector<string> raw_lines;
    for (size_t i = 0; i < number_of_lines; i++) {
        getline(cin, line);
        raw_lines.push_back(line);
    }
    // Loop through and find all queries.
    vector<string> queries;
    for (size_t i = 0; i < number_of_queries; i++) {
        getline(cin, line);
        queries.push_back(line);
    }
    print_vector(queries);
    // 
    return 0;
}

// Modified from cppreference.com/w/cpp/container/map
void print_map(const map<string, string>& m)
{
    // Iterate using C++17 facilities
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";
    std::cout << '\n';
}

void print_vector(const vector<string>& string_vector) {
    for (size_t i = 0; i < string_vector.size(); i++)
        cout << i << ":" << string_vector[i] << " ";
    cout << endl;
    return;
}
