#include <iostream>
#include "LongLong.h"

using namespace std;

int main()
{
    LongLong a(100000);
    LongLong b(2000);

    cout << "a = " << a.toString() << "\n";
    cout << "b = " << a.toString() << "\n";
    cout << "a == b? " << a.equal(b) << "\n";
    cout << "a != b? " << a.notEqual(b) << "\n";
    cout << "a > b? " << a.more(b) << "\n";
    cout << "a < b? " << a.less(b) << "\n";
    cout << "a <= b? " << a.lessEqual(b) << "\n";
    cout << "a >= b? " << a.moreEqual(b) << "\n";
    cout << "a + b = " << a.add(b).toString() << "\n";
    cout << "a - b = " << a.subtr(b).toString() << "\n";
    cout << "a * b = " << a.mult(b).toString() << "\n";
    cout << "a / b = " << a.div(b).toString() << "\n";
    cout << "a % b = " << a.mod(b).toString() << "\n";
}

