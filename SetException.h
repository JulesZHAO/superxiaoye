#pragma once

#include<iostream>
using namespace std;

class SetException {
public:
    SetException(const string& i) :info(i) {}
    string getInfo() const { return info; }
private:
    string info;
};
