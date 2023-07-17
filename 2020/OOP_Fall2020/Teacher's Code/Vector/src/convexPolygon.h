#ifndef POLYGON
#define POLYGON
#include "vector.h"
#include "bubbleSort.h"
/*
static mathVector c;
static mathVector old;

bool a(mathVector a1, mathVector a2){
    double d1 = (a1-c).angle(old-c);
    double d2 = (a2-c).angle(old-c);

    return (d1 > d2);
}*/
//class mathVector;
class Polygon
{
private:
  int _numVertices;
  mathVector *_vertices;

public:
  //friend mathVector mathVector::centroid(mathVector vectors[], int num);
  //friend mathVector mathVector::centroid(mathVector vectors[], int num);
  /*static Polygon CreatePolygon(int numVertices, mathVector * input){
      c = mathVector::centroid(input, numVertices);
      old = input[0];

      std::sort(input,input+numVertices, a);

      return Polygon(numVertices,input);
  }*/
  static Polygon CreatePolygon(int numVertices, mathVector *input)
  {
    // mathVector::centroid
    mathVector c = input->centroid<mathVector>(input, numVertices);
    mathVector b = input[0] - c;
    angleComparator comp = angleComparator(c, b);
    //std::sort(input,input+numVertices,comp);
    BubbleSort(input, input + numVertices, comp);
    return Polygon(numVertices, input);
  }

  Polygon()
  {
    _numVertices = 0;
    _vertices = new mathVector[_numVertices];
  }
  Polygon(int inputVerties, mathVector *input)
  {
    _numVertices = inputVerties;
    _vertices = new mathVector[_numVertices];
    for (int i = 0; i < _numVertices; i++)
    {
      _vertices[i] = input[i];
    }
  }
  int getNumberOfVerties() const
  {
    return _numVertices;
  }
  double getPrimeter() const
  {
    double primeter = 0;
    for (int i = 0; i < _numVertices; i++)
    {
      primeter += (_vertices[(i + 1) % _numVertices] - _vertices[i]).length();
    }
    return primeter;
  }
  double getArea() const
  {
    double area = 0;
    for (int i = 0; i < (_numVertices - 2); i++)
    {
      area += _vertices[0].getArea(_vertices[i + 1], _vertices[i + 2]);
    }
    return area;
  }
  mathVector centroid()
  {
    mathVector sum(2);
    for (int i = 0; i < _numVertices; i++)
    {
      sum.component(1) += _vertices[i].component(1);
      sum.component(2) += _vertices[i].component(2);
    }
    sum.component(1) /= _numVertices;
    sum.component(2) /= _numVertices;
    return sum;
  }
};

template <class T>
class PolygonFactory
{
public:
  //template <typename T>
  //friend class mathVector;
  Polygon CreatePolygon(mathVector vertices[], int num)
  {
    //*vertices->centroid
   // <T=mathVector>
    mathVector c =centroid<T>(vertices, num);
    //mathVector c = //vertices->centroid(vertices, num);
    
    mathVector b = vertices[0] - c;
    angleComparator comp = angleComparator(c, b);
    BubbleSort(vertices, vertices + num, comp);
    return Polygon(num, vertices);
  }
};

#endif
