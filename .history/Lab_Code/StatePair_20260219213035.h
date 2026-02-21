#ifndef STATEPAIR
#define STATEPAIR
#include <iostream>
#include <string>
#include "StatePair.h"
using namespace std;

template<typename T1, typename T2>
class StatePair {

public:
// TODO: Define constructors
    StatePair();
    StatePair(T1 userKey, T2 userValue);
    ~StatePair();

// TODO: Define mutators, and accessors for StatePair
    void SetKey(T1 userKey);
    void SetValue(T2 userValue);
    T1 GetKey();
    T2 GetValue();

// TODO: Define PrintInfo() method
    void PrintInfo();

protected:
    T1 key;
    T2 value;

};

template<typename T1, typename T2>
StatePair<T1, T2>::StatePair(T1 userKey, T2 userValue) {
    SetKey(userKey);
    SetValue(userValue);
}

template<typename T1, typename T2>
StatePair<T1, T2>::StatePair() {
    key = 0;
    value = 0;
}

template<typename T1, typename T2>
StatePair<T1, T2>::~StatePair() {

}

template<typename T1, typename T2>
void StatePair<T1, T2>::SetKey(T1 userKey) {
    key = userKey;
}

template<typename T1, typename T2>
void StatePair<T1, T2>::SetValue(T2 userValue) {
    value = userValue;
}

template<typename T1, typename T2>
T1 StatePair<T1, T2>::GetKey() {
    return key;
}

template<typename T1, typename T2>
T2 StatePair<T1, T2>::GetValue() {
    return value;
}

template<typename T1, typename T2>
void StatePair<T1, T2>::PrintInfo() {
    cout << key << " " << value << endl;
}

#endif //STATEPAIR
