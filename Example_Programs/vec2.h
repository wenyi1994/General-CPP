#ifndef VEC2_
#define VEC2_

class vec2
{
private:
    double m_x;
    double m_y;
public:
    vec2();
    vec2(double x, double y);
    ~vec2();
    double get_x();
    double get_y();
    void show();
    vec2 add(vec2 v);
	double dot_product(vec2 v);
	vec2 scale(double r);
};

#endif