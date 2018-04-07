#include <iostream>
#include <iomanip>
#include "vec2.h"

using namespace std;

vec2::vec2() {cout<<"● call: constructor, default"<<endl;}

vec2::vec2(double x, double y)
{
    m_x = x; m_y = y;
    cout<<"● call: constructor, double x double y"<<endl;
}

vec2::~vec2() {cout<<"● call: destructor, default"<<endl;}

double vec2::get_x() {return m_x;}

double vec2::get_y() {return m_y;}

void vec2::show()
{
    cout<<setw(4)<<m_x<<endl;
    cout<<setw(4)<<m_y<<endl;
}

vec2 vec2::add(vec2 v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    return *this;
}

double vec2::dot_product(vec2 v) {return m_x * v.m_x + m_y * v.m_y;}

vec2 vec2::scale(double r)
{
    m_x *= r;
    m_y *= r;
    return *this;
}