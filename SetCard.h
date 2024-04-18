#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>

using namespace std;

class SetCard{
private:
    string m_info;
public:
    SetCard(const string& i) : m_info(i) { std::cout<< m_info <<endl;}
    string getInfo() const { return m_info; }
};

enum class Color {red, orange, yellow, green, blue, purple,black};
enum class Number {zero = 0, one = 1, two = 2, three = 3, four = 4, five = 5,six = 6, seven = 7, eight = 8, nine = 9};

string toString(Color c);
string toString(Number n);

ostream& operator<<(ostream&f, Color c);
ostream& operator<<(ostream&f, Number n);

extern initializer_list<Color> Colors;
extern initializer_list<Number> Numbers;