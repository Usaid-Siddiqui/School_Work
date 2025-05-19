#include <iostream>
#include <sstream>

#include "exceptions.h"
#include "MyDynamicArray.cpp"

using namespace std;

void foo(MyDynamicArray<int> param) {
    for (int i = 0; i < param.length(); i++) {
        param[i] = 0;
    }
}

int main() {
    MyDynamicArray<int> x;
    for (int i = 0; i < 130; i++) {
        x.add(i);
    }
    int sum = 0;
    for (int i = 0; i < x.length(); i++) {
        sum += x[i];
    }   
    cout << "The sum is : " << sum << endl;
    for (int i = 0; i < 125; i++) {
        x.del();
    }
    try {
        x[10] = 27;
        cout << "does not reach" << endl;
    }
    catch (IndexOutOfRangeException &e) {
       cout << e.getMessage() << "\nBad index: " << e.getIndex() << endl;
    }
    
    MyDynamicArray<int> y(100);
    for (int i = 0; i < y.length(); i += 2) {
        y[i] = i*i;
    }
    for (int i = 0; i < 200; i++) {
        y.add(i);
    }
    sum = 0;
    for (int i = 0; i < y.length(); i += 2) {
        sum += y[i];
    }   
    cout << "The sum is : " << sum << endl;
    for (int i = 0; i < 195; i++) {
        y.del();
    }
    y[60] = 27;
    for (int i = 0; i < 200; i++) {
        y.add(i);
    }
    sum = 0;
    for (int i = 0; i < y.length(); i += 2) {
        sum += y[i];
    }   
    cout << "The sum is : " << sum << endl;
    MyDynamicArray<int> z(10);
    z[9] = 1000;
    cout << z.length() << endl;
    z.clear();
    try {
        z[2] = 5;
        cout << "does not reach" << endl;
    }
    catch (IndexOutOfRangeException &e) {
       cout << e.getMessage() << "\nBad index: " << e.getIndex() << endl;
    }
    
    try {
        z[-1] = 5;
        cout << "does not reach" << endl;
    }
    catch (IndexOutOfRangeException &e) {
       cout << e.getMessage() << "\nBad index: " << e.getIndex() << endl;
    }
    
    try {
        z.del();
        cout << "does not reach" << endl;
    }
    catch (InvalidOperationException &e) {
       cout << e.getMessage() << endl;
    }
    
    z.add(9);
    z.add(5);
    cout << z.length() << endl;
    
    MyDynamicArray<int> b;
    b = x;
    x[1] += 100;
    
    sum = 0;
    for (int i = 0; i < x.length(); i++) {
        sum += x[i];
    }   
    cout << "The x sum is : " << sum << endl;
    
    sum = 0;
    for (int i = 0; i < b.length(); i++) {
        sum += b[i];
    }   
    cout << "The b sum is : " << sum << endl;   
    
    foo(b);
    
    sum = 0;
    for (int i = 0; i < b.length(); i++) {
        sum += b[i];
    }   
    cout << "The b sum is : " << sum << endl;
    
    try {
       while (true) {
          x.del();
       }
       cout << "does not reach" << endl;
    }
    catch (InvalidOperationException &e) {
       cout << e.getMessage() << endl;
    }
    
    MyDynamicArray<string> sv1;
    sv1.add("hello");
    sv1.add("world");
    
    MyDynamicArray<string> sv2 = sv1;
    
    sv1.del();
    sv1.del();
    sv1.add("foo");
    
    sv2.del();
    sv2.add("bar");
    
    sv1 = sv2;
    
    sv1.add("foobar");
    
    cout << sv1.length() << " " << sv2.length() << endl;
    ostringstream oss;
    for (int i = 0; i < sv1.length(); i++) {
       oss << sv1[i];
    }
    for (int i = 0; i < sv2.length(); i++) {
       oss << sv2[i];
    }
    cout << oss.str().length() << endl;
    
    sv1.clear();
    sv2.clear();
    
    return 0;
}
