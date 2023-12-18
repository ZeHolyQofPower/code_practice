#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    // Loop through ints between a and b
    for (int i = a; i <= b; i++) {
        // Less than ten
        if (i >= 1 && i <= 9) {
            switch (i) {
                case 1:
                    cout << "one";
                    break;
                case 2:
                    cout << "two";
                    break;
                case 3:
                    cout << "three";
                    break;
                case 4:
                    cout << "four";
                    break;
                case 5:
                    cout << "five";
                    break;
                case 6:
                    cout << "six";
                    break;
                case 7:
                    cout << "seven";
                    break;
                case 8:
                    cout << "eight";
                    break;
                case 9:
                    cout << "nine";
                    break;
                default:
                    cout << "i outside of [1, 9] ERROR";
                    return -1;
                }
                cout << endl;
        // Ten and Greater
        } else if (i > 9) {
            // Check for odd versus even
            if ((i % 2) == 0) {
                cout << "even" << endl;
            } else {
                cout << "odd" << endl;
            }
        } else {
            cout << "input outside of [1, infinity) ERROR" << endl;
            return -2;
        }
    }
    return 0;
}  
