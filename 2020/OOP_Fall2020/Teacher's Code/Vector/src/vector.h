#ifndef VECTOR
#define VECTOR
#include <cmath>
#include <string>
using namespace std;
//class PolygonFactory;

//template <typename T> class PolygonFactory;
class mathVector
{

private:
  double *content;
  int len;
  void initialize(double *input, int l)
  {
    content = new double[l];
    for (int i = 0; i < l; i++)
    {
      content[i] = input[i];
    }
    len = l;
  }

public:
  //friend class Polygon;
  //template <typename T = mathVector>
  // mathVector centroid(mathVector vectors[], int num);
  template <class T>
  friend class PolygonFactory;
  //friend mathVector centroid(mathVector vectors[], int num);
  mathVector()
  { //constructer
    //content = {};
    len = 0;
    content = new double[len];
  }

  mathVector(int l)
  {
    len = l;
    content = new double[len];
    for (int i = 0; i < len; i++)
    {
      content[i] = 0;
    }
  }

  mathVector(double *input, int l)
  { //constructer
    initialize(input, l);
  }

  mathVector(mathVector const &input)
  { //copy constructer
    printf("copy constructer \n");

    initialize(input.vector(), input.len);
  }
  template <class T>
  mathVector centroid(mathVector vectors[], int num)
  { // static function
    mathVector sum(2);
    for (int i = 0; i < num; i++)
    {
      sum.component(1) += vectors[i].component(1);
      sum.component(2) += vectors[i].component(2);
      //sum += vectors[i];
    }
    sum.component(1) /= num;
    sum.component(2) /= num;
    //sum /= num;
    return sum;
  }

  mathVector &operator=(mathVector const &input)
  { //operator overloadding for copy assignment
    printf("copy assignment \n");
    if (content != NULL)
    {
      delete[] content;
    }

    len = input.len;
    //this->len = input.len;
    //(*this).len = input.len;
    content = new double[len];
    for (int i = 0; i < len; i++)
    {
      content[i] = input.vector()[i];
    }

    return *this; // we will discuss more abuot this
  }

  ~mathVector()
  { //destructer
    if (content != NULL)
    {
      delete[] content;
    }
  }

  int dimension() const
  { //getter
    return len;
  }

  double *vector() const
  {
    return content;
  }

  void setDimension(int input) // setter
  {
    len = input;
  }

  double &component(int index) const
  {
    return content[index - 1];
  }

  double dot(mathVector input)
  {
    double result = 0;
    //input.len also works, beacuse
    // input is an object of the same class
    if (len != input.dimension())
    {
      throw string("ERROR");
    }
    for (int i = 0; i < len; i++)
    {
      // input.content[i] also works, beacuse
      // input is an object of the same class
      result += content[i] * input.vector()[i];
    }

    return result;
  }

  double length()
  {
    double l = 0;
    for (int i = 0; i < len; i++)
    {
      l += content[i] * content[i];
    }
    return sqrt(l);
  }

  mathVector operator-(const mathVector &input)
  {
    if (this->len != input.len)
    {
      throw std::string("Error in Length");
    }

    mathVector result = *this; // copy constructer

    for (int i = 1; i <= len; i++)
    {
      result.component(i) -= input.component(i);
    }

    return result;
  }
  double getArea(mathVector inputA, mathVector inputB)
  {
    double A = (inputA - *this).length();
    double B = (inputB - *this).length();
    double C = (inputA - inputB).length();
    double S = (A + B + C) / 2;
    return sqrt(S * (S - A) * (S - B) * (S - C));
  }
  bool larger180(mathVector input)
  {
    return (this->component(1) * input.component(2) - this->component(2) * input.component(1)) >= 0;
  }
  double angle(mathVector input)
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
};

class angleComparator
{
private:
  mathVector _a;
  mathVector _b;

public:
  angleComparator()
  {
  }

  angleComparator(mathVector &a, mathVector &b)
  {
    _a = a;
    _b = b;
  }

  bool operator()(mathVector &u, mathVector &v)
  {
    return _b.angle(u - _a) < _b.angle(v - _a);
  }
};

#endif
