#include <iostream>
#include <string>
#include "my_vector.h"
#include <climits>

using namespace std;

template<class T>
void printVector(const Vector<T> & v, string name) {
    cout << string(40, '-') << '\n';
    cout << name << " size = " << v.size() << '\n';
    cout << name << " capacity = " << v.capacity() << '\n';
    cout << name << " empty = " << v.empty() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << name << "[" << i << "] = " << v[i] << '\n';
    }
}
void testVectorofString() {

    Vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    for (int i = 0; i < vs.size(); i++) {
        cout << "vs[" << vs[i] << "]" << '\n';
    }
    cout << "before vs.size() = " << vs.size() << '\n';
    cout << "before vs.capacity() = " << vs.capacity() << '\n';
}

int findMax (const Vector<int> & v) {
    int max = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

void testPointer() {
    Vector<int> * vp = new Vector<int>;
    vp->push_back(4);
    cout << "vp.size() = " << vp->size() << '\n';
    cout << "vp.capacity() = " << vp->capacity() << '\n';
    //delete vp;
}


int main() {
    Vector<int> v1;
    cout << "v1 is empty? : " << v1.empty() << '\n';
    for (int i = 0; i < 10; i++) {
        v1.push_back(i + 1);
    }
    cout << "before v1.size() = " << v1.size() << '\n';
    cout << "before v1.capacity() = " << v1.capacity() << '\n';
    //v1.insert(100,3);
    // cout << "after v1.size() = " << v1.size() << '\n';
    // cout << "after v1.capacity() = " << v1.capacity() << '\n';
    for (int i = 0; i < v1.size(); i++) {
        cout << "v1[" << i << "]" << " = " << v1[i] << '\n';
    }
    cout << "v1 is empty? : " << v1.empty() << '\n';
    cout << "max is: " << findMax(v1) << '\n';
    testPointer();
    testVectorofString();
    printVector(v1, "This");
    return 0;
}
