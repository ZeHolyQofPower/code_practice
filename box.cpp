/* Inlined Header */
#include <iostream>
#include <tuple>    // Using tie
//#include <format> // LIES, this isn't really c++20!
using namespace std;

// Box class, made up of l, b, and h
class Box {
  public:
    Box();
    Box(int l, int b, int h);
    Box(const Box& rhs_box);
    int getLength();
    int getBreadth();
    int getHeight();
    long long CalculateVolume();
    friend bool operator<(const Box& lhs, const Box& rhs);
    friend ostream& operator<<(ostream& lhs, const Box& rhs);
  private:
    int l, b, h;
};

// Default Contructor
Box::Box() {
    l = b = h = 0;
}
// Parameterized constructor
Box::Box(int l, int b, int h) {
    this->l = l;
    this->b = b;
    (*this).h = h;
    // Because I felt like it.
}
// Copy Constructor
Box::Box(const Box& rhs_box) {
    this->l = rhs_box.l;
    this->b = rhs_box.b;
    this->h = rhs_box.h;
}
// Accessers
int Box::getLength() {
    return this->l;
}
int Box::getBreadth() {
    return this->b;
}
int Box::getHeight() {
    return this->h;
}
// Methods
long long Box::CalculateVolume() {
    return ((long long)this->l * (long long)this->b * (long long)this->h);
    // Test case 4 checks for overflow. I guess without casts, this was returning an int.
}
// Overloaded Operators
bool operator<(const Box& lhs, const Box& rhs) {
    return tie(lhs.l, lhs.b, lhs.h)
         < tie(rhs.l, rhs.b, rhs.h);
}
ostream& operator<<(ostream& lhs, const Box& rhs){
    lhs << to_string(rhs.l) + " " + to_string(rhs.b) + " " + to_string(rhs.h);
    return lhs;
}

/* Provided Driver */
void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}

