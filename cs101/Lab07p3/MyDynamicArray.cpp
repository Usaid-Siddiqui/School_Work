#include <iostream>

#include "exceptions.h"

using namespace std;

class MyDynamicArray {
    private:
        int size, capacity;
        int *a;
    public:
        MyDynamicArray() {
            capacity = 2;
            size = 0;
            a = new int[capacity];
        }
        MyDynamicArray(int s) {
            capacity = s;
            size = s;
            a = new int[capacity];
        }
        ~MyDynamicArray() {
            cout << "In the destructor" << endl;
            delete[] a;
        }
        int &operator[](int i) {
            if (i >= size || i < 0) {
                cout << "Out of bounds reference: " << i << endl;
                throw IndexOutOfRangeException("[]: Index was outside the bounds of the MyDynamicArray", i);
            }
            return *(a+i);
        }
        void add(int v) {
            if (size == capacity) {
                capacity *= 2;
                cout << "Doubling to: " << capacity << endl;
                int* newArr = new int[capacity];
                for (int i=0; i<size; i++) {
                   newArr[i] = a[i];
                }
                delete[] a;
                a = newArr;
            }
            a[size++] = v;
        }
        void del() {
            if (size > 0) {
                size--;
                if (size <= capacity / 4 && capacity > 1) {
                   capacity /= 2;
                   cout << "Reducing to: " << capacity << endl;
                   int *newArr = new int[capacity];
                   for (int i = 0; i < size; i++) {
                     newArr[i] = a[i];
                   }
                   delete[] a;
                   a = newArr;
                }
            }
            if (size==0) throw InvalidOperationException("MyDynamicArray empty");
        }
        int length() const {
            return size;
        }
        void clear() {
            delete[] a;
            capacity = 2;
            size = 0;
            a = new int[capacity];
        }
        MyDynamicArray &operator=(const MyDynamicArray &src) {
            if (this == &src) return *this;
            delete[] a;
            capacity = src.capacity;
            size = src.size;
            //error = src.error;
            a = new int[capacity];
            for (int i = 0; i < size; i++) {
                a[i] = src.a[i];
            }
            cout << "In the copy assignment operator" << endl;
            return *this;
        }
        
        MyDynamicArray(const MyDynamicArray &src) {
            capacity = src.capacity;
            size = src.size;
            //error = src.error;
            a = new int[capacity];
            for (int i = 0; i < size; i++) {
               a[i] = src.a[i];
            }
            cout << "In the copy constructor" << endl;
        }
};
