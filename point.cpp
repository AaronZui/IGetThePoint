#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class point
{
private:
float x;
float y;
    
public:
    point(float a, float b){
        x = a;
        y = b;
    };
float operator-(const point& b){
    return(sqrt((pow(b.x-this->x,2))+(pow(b.y-this->y,2))));
}
point operator/(const point& b){
    return point(((b.x+this->x)/2),((b.y+this->y)/2));
}
bool operator==(const point& b){
    return ((b.x == this->x)&&(b.y == this->y));
}
bool operator !=(const point& b){
    return !((b.x == this->x)&&(b.y == this->y));
}
friend ostream& operator<<(ostream& out, const point& p){
    out << "(" << p.x << " , " << p.y << ")";
    return out;
}
point& operator++() {
    ++x;
    return *this;
    }
point& operator--() {
    --x;
    return *this;
    }
point operator++(int) {
    point temp = *this;
    y++;
    return temp;
    }
point operator--(int) {
    point temp = *this;
    y--;
    return temp;
    }
float& operator[](int index) {
    assert(index == 0 || index == 1);
    return (index == 0) ? x : y;
}
friend istream& operator>>(istream& in, point& p){
    in >> p.x >> p.y;
    return in;
}
};

main (){
    point a(1,2);
    cout<< a;
    point b(2,3);
    assert(b!=a);
    ++a;
    assert(a[0]==2);
    a++;
    assert(a[1]==3);
    assert(a==b);
    a--;
    --a;
    assert(a[0]==1);
    assert(a[1]==2);
    point c(3,3);
    point d(4,4);
    point e(3.5,3.5);
    assert((c-d)==1);
    assert((c/d)==e);
    cout<<endl<< "all test sucessfull";
}

