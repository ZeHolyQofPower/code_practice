#include <vector>
#include <iostream> // Using cin, cout, and endl
#include <sstream>  // Using istringstream
using namespace std;

void print_ragged_array(const vector<vector<int>>& ragged_array);

int main() {
    // First create a ragged int array out of vectors.
    size_t number_of_arrays = 0;  // 'n' in prompt
    size_t queries = 0;  // 'q' in prompt
    cin >> number_of_arrays >> queries;
    //cout << number_of_arrays << " " << queries << endl;
    vector<vector<int>> ragged_array(                   // Construct a vector of vectors.
                                     number_of_arrays,  // Column length or 'm'
                                     vector<int>(0));   // Default Row length or 'n'
    string line = "";
    int tmp = 0;
    // For each line, terminated by a newline
    for (size_t i = 0; i < number_of_arrays+1; i++) {
        getline(cin, line);                 // Input as a string so endline is preserved
        istringstream line_stream(line);    // Convert to string stream
        //cout << "i: " << i << endl;
        while (line_stream >> tmp) {        // Easy conversion to ints
            // The line above is iterating 'i' TODO Why?
            //cout << "i: " << i << endl;
            ragged_array[i-1].push_back(tmp);
        }
    }
    // Second create our list of queries and output them
    int m = 0;
    int n = 0;
    for (size_t i = 0; i < queries; i++) {
        getline(cin, line);
        istringstream line_stream(line);
        line_stream >> m;
        line_stream >> n;
        //cout << "(m,n) " << m << "," << n << endl;
        cout << ragged_array[m][n+1] << endl;
        // Their second value into each vector is wrong. 
    }
    return 0;
}

void print_ragged_array(const vector<vector<int>>& ragged_array) {
    for (size_t i = 0; i < ragged_array.size(); i++) {
        cout << "row " << i << ": ";
        for (size_t j = 0; j < ragged_array[i].size(); j++)
            cout << ragged_array[i][j] << " ";
        cout << endl;
    }
    return;
}

