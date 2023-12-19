#include <list>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    list<string> *mr_list_ptr;
    mr_list_ptr = new list<string>[7];
    mr_list_ptr->push_back("buh");
    cout << mr_list_ptr->size() << endl;
    return 0;
}