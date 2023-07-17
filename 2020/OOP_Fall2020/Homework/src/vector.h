#ifndef VECTOR
#define VECTOR
#include <iostream>
#include <string>
#include <cmath>
#include "bubbleSort.h"
using namespace std;

class Vector
{
public:
    Vector(double v[], int dim)
    {
        copy(dim, v);
    }

    Vector(Vector const &v)
    {
        copy(v._dim, v._v);
    }
    Vector()
    { //constructer
        //content = {};
        _dim = 0;
        _v = new double[_dim];
    }

    Vector(int l)
    {
        _dim = l;
        _v = new double[_dim];
        for (int i = 0; i < _dim; i++)
        {
            _v[i] = 0;
        }
    }

    // destructor
    ~Vector()
    {
        if (_v != NULL)
        {
            delete[] _v;
        }
    }

    // constant member function
    int dim() const
    {
        return _dim;
    }

    double &at(int i) const
    {
        return _v[i - 1];
    }

    double *vector() const
    {
        return _v;
    }

    void subtract(Vector const &v)
    {
        if (_dim != v._dim)
        {
            throw string("ERROR");
        }
        *this = *this - v;
    }

    void add(Vector const &v)
    {
        if (_dim != v._dim)
        {
            throw string("ERROR");
        }
        *this = *this + v;
    }

    Vector &operator=(Vector const &u)
    {
        if (_v != NULL)
        {
            delete[] _v;
        }
        _dim = u._dim;
        _v = new double[_dim];
        for (int i = 0; i < _dim; i++)
        {
            _v[i] = u._v[i];
        }

        return *this; // we will discuss more abuot this
    }

    Vector operator-(Vector const &v) const
    {
        if (this->_dim != v._dim)
        {
            throw string("ERROR");
        }
        Vector result = *this;
        for (int i = 1; i <= _dim; i++)
        {
            result.at(i) -= v.at(i);
        }
        return result;
    }

    Vector operator+(Vector const &v) const
    {

        if (this->_dim != v._dim)
        {
            throw string("ERROR");
        }
        Vector result = *this;
        for (int i = 1; i <= _dim; i++)
        {
            result.at(i) += v.at(i);
        }
        return result;
    }

    double length() const
    {
        double l = 0;
        for (int i = 0; i < _dim; i++)
        {
            l += _v[i] * _v[i];
        }
        return sqrt(l);
    }
    bool larger180(Vector input)
    {
        return (this->at(1) * input.at(2) - this->at(2) * input.at(1)) >= 0;
    }

    double angle(Vector input)
    {
        double sum1 = 0, sum2 = 0;
        sum1 = this->dot(input);
        sum2 = this->length() * input.length();
        if (this->larger180(input))
        {
            return 360 - acos(sum1 / sum2) * 180 / M_PI;
        }
        return acos(sum1 / sum2) * 180 / M_PI;
    }
    double dot(Vector input)
    {
        double result = 0;
        if (_dim != input.dim())
        {
            throw string("ERROR");
        }
        for (int i = 0; i < _dim; i++)
        {
            result += _v[i] * input.vector()[i];
        }

        return result;
    }

private:
    int _dim;
    double *_v;
    void copy(int dim, double *v)
    {
        _v = new double[dim];
        for (int i = 0; i < dim; i++)
        {
            _v[i] = v[i];
        }
        _dim = dim;
    }
};

class angleComparator
{
private:
    Vector _a;
    Vector _b;

public:
    angleComparator()
    {
    }

    angleComparator(Vector &a, Vector &b)
    {
        _a = a;
        _b = b;
    }

    bool operator()(Vector &u, Vector &v)
    {
        return _b.angle(u - _a) < _b.angle(v - _a);
    }
};

Vector centroid(Vector vectors[], int num)
{
    Vector sum(2);
    for (int i = 0; i < num; i++)
    {
        if (vectors[i].dim() != vectors[i + 1].dim() && i != num - 1)
        {
            throw string("ERROR");
        }
        else
        {
            sum.at(1) += vectors[i].at(1);
            sum.at(2) += vectors[i].at(2);
        }
    }
    sum.at(1) /= num;
    sum.at(2) /= num;
    return sum;
}

double distance(Vector u, Vector v)
{
    if (u.dim() != v.dim())
    {
        throw string("ERROR");
    }
    double distance_two_vectors = 0;
    for (int i = 0; i < u.dim(); i++)
    {
        distance_two_vectors += pow(u.at(i + 1) - v.at(i + 1), 2);
    }
    return sqrt(distance_two_vectors);
}

double area(Vector u, Vector v, Vector w)
{
    double a_side_length = (u - v).length();
    double b_side_length = (v - w).length();
    double c_side_length = (u - w).length();
    double semi_perimeter = (a_side_length + b_side_length + c_side_length) / 2;
    return sqrt(semi_perimeter * (semi_perimeter - a_side_length) * (semi_perimeter - b_side_length) * (semi_perimeter - c_side_length));
} //(25 points) //回傳三個 vector 所圍成的三角形面積

double area(Vector a[], int sides)
{
    double convex_polygon_area = 0;
    if (sides == 3)
    {
        for (int i = 0; i < (sides - 2); i++)
        {
            double a_side_length = (a[i + 1] - a[0]).length();
            double b_side_length = (a[i + 2] - a[0]).length();
            double c_side_length = (a[i + 1] - a[i + 2]).length();
            double semi_perimeter = (a_side_length + b_side_length + c_side_length) / 2;
            double small_triangle_area = sqrt(semi_perimeter * (semi_perimeter - a_side_length) * (semi_perimeter - b_side_length) * (semi_perimeter - c_side_length));
            convex_polygon_area += small_triangle_area;
        }
        return convex_polygon_area;
    }
    else if (sides > 3)
    {
        Vector c = centroid(a, sides);
        Vector b = a[0] - c;
        angleComparator comp(c, b);
        BubbleSort(a, a + sides, comp);
        for (int i = 0; i < (sides - 2); i++)
        {
            double a_side_length = (a[i + 1] - a[0]).length();
            double b_side_length = (a[i + 2] - a[0]).length();
            double c_side_length = (a[i + 1] - a[i + 2]).length();
            double semi_perimeter = (a_side_length + b_side_length + c_side_length) / 2;
            double small_triangle_area = sqrt(semi_perimeter * (semi_perimeter - a_side_length) * (semi_perimeter - b_side_length) * (semi_perimeter - c_side_length));
            convex_polygon_area += small_triangle_area;
        }
        return convex_polygon_area;
    }
    return 0;
} //(25 points) //回傳多個 vector 所圍成的多邊形面積

double perimeter(Vector a[], int sides)
{
    if (sides > 3)
    {
        double convex_polygon_primeter = 0;
        Vector c = centroid(a, sides);
        Vector b = a[0] - c;
        angleComparator comp = angleComparator(c, b);
        BubbleSort(a, a + sides, comp);
        for (int i = 0; i < sides; i++)
        {
            convex_polygon_primeter += (a[(i + 1) % sides] - a[i]).length();
        }
        return convex_polygon_primeter;
    }
    else if (sides == 3)
    {
        double convex_polygon_primeter = 0;
        for (int i = 0; i < sides; i++)
        {
            convex_polygon_primeter += (a[(i + 1) % sides] - a[i]).length();
        }
        return convex_polygon_primeter;
    }
    return 0;
} //(25 points) //回傳多個 vector 所圍成的多邊形周長

#endif
