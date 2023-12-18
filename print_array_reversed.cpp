#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Input for array size.
    int n = 0;
    cin >> n;
    int mr_int_array[n];
    int tmp = 0;
    // Fill up array.
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        mr_int_array[i] = tmp;
    }
    // Reverse and print it.
    for (int i = n-1; i >= 0; i--) {
        cout << mr_int_array[i] << " ";
    }
    return 0;
}

