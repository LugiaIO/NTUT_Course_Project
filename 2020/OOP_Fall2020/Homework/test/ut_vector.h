#ifndef _UT_VECTOR_H_
#define _UT_VECTOR_H_

#include <gtest/gtest.h>
#include "../src/vector.h"
#include "../src/bubbleSort.h"

TEST(HW5_NotConvexPolygon, Distance)
{
    double a[] = {10, 0};
    Vector v = Vector(a, 2);
    double b[] = {0, 5};
    Vector w = Vector(b, 2);
    ASSERT_NEAR(sqrt(125), distance(v, w), 0.001);
}

TEST(HW5_NotConvexPolygon, DistanceWithOriginalPoint)
{
    double a[] = {10, 0};
    Vector v = Vector(a, 2);
    //double b[] = {0, 5};
    Vector w = Vector(2);
    ASSERT_NEAR(10, distance(v, w), 0.001);
}

TEST(HW5_NotConvexPolygon, DistanceException)
{
    double a[] = {10, 0};
    Vector v = Vector(a, 2);
    double b[] = {0, 5, 1};
    Vector w = Vector(b, 3);
    ASSERT_ANY_THROW(distance(v, w));
}

TEST(HW5_NotConvexPolygon, TriangleArea)
{
    double a[] = {0, 6};
    Vector v = Vector(a, 2);
    double b[] = {4, 0};
    Vector w = Vector(b, 2);
    double c[] = {0, 0};
    Vector x = Vector(c, 2);
    ASSERT_NEAR(12, area(v, w, x), 0.001);
}

TEST(HW5_NotConvexPolygon, TriangleAreaUseVectorConstructerOnlyDim)
{
    double a[] = {0, 6};
    Vector v = Vector(a, 2);
    double b[] = {4, 0};
    Vector w = Vector(b, 2);
    Vector x = Vector(2);
    ASSERT_NEAR(12, area(v, w, x), 0.001);
}

TEST(HW5_NotConvexPolygon, TriangleAreaUseArray)
{
    double a[] = {0, 6};
    Vector v = Vector(a, 2);
    double b[] = {4, 0};
    Vector w = Vector(b, 2);
    double c[] = {0, 0};
    Vector x = Vector(c, 2);
    Vector vectors[3] = {v, w, x};
    ASSERT_NEAR(12, area(vectors, 3), 0.001);
}

TEST(HW5_NotConvexPolygon, TriangleAreaUseArrayAndUseVectorConstructerOnlyDim)
{
    double a[] = {0, 6};
    Vector v = Vector(a, 2);
    double b[] = {4, 0};
    Vector w = Vector(b, 2);
    Vector x = Vector(2);
    Vector vectors[3] = {v, w, x};
    ASSERT_NEAR(12, area(vectors, 3), 0.001);
}

TEST(HW5_NotConvexPolygon, QuadrilateralArea)
{
    double a[2] = {1, 0},
           b[2] = {4, 0},
           c[2] = {4, 4},
           d[2] = {1, 4};
    Vector u = Vector(a, 2);
    Vector v = Vector(b, 2);
    Vector w = Vector(c, 2);
    Vector x = Vector(d, 2);
    Vector vectors[4] = {u, v, w, x};
    ASSERT_NEAR(12, area(vectors, 4), 0.001);
}

TEST(HW5_NotConvexPolygon, TrianglePerimeter)
{
    double a[2] = {1, 0},
           b[2] = {4, 0},
           c[2] = {4, 4};
    Vector u = Vector(a, 2);
    Vector v = Vector(b, 2);
    Vector w = Vector(c, 2);
    Vector vectors[3] = {u, w, v};
    ASSERT_NEAR(12, perimeter(vectors, 3), 0.001);
}

TEST(HW5_NotConvexPolygon, QuadrilateralPerimeter)
{
    double a[2] = {1, 0},
           b[2] = {4, 0},
           c[2] = {4, 4},
           d[2] = {1, 4};
    Vector u = Vector(a, 2);
    Vector v = Vector(b, 2);
    Vector w = Vector(c, 2);
    Vector x = Vector(d, 2);
    Vector vectors[4] = {u, w, v, x};
    ASSERT_NEAR(14, perimeter(vectors, 4), 0.001);
}

TEST(HW5_ConvexPolygon, Centroid)
{
    double a[] = {0, 6};
    Vector v = Vector(a, 2);
    double b[] = {4, 0};
    Vector w = Vector(b, 2);
    Vector x[2] = {v, w};
    Vector y = centroid(x, 2);
    ASSERT_NEAR(2, y.at(1), 0.001);
    ASSERT_NEAR(3, y.at(2), 0.001);
}

TEST(HW5_ConvexPolygon, CentroidException)
{
    double a[] = {0, 6};
    Vector v = Vector(a, 2);
    double b[] = {4, 0, 5};
    Vector w = Vector(b, 3);
    Vector x[2] = {v, w};
    ASSERT_ANY_THROW(Vector y = centroid(x, 2));
}


TEST(HW5_ConvexPolygon, PentagonArea)
{
    double a[2] = {1, 0},
           b[2] = {4, 0},
           c[2] = {4, 4},
           d[2] = {1, 4},
           e[2] = {3, 5};
    Vector u = Vector(a, 2);
    Vector v = Vector(b, 2);
    Vector w = Vector(c, 2);
    Vector x = Vector(d, 2);
    Vector p = Vector(e, 2);
    Vector vectors[5] = {u, v, w, x, p};
    ASSERT_NEAR(13.5, area(vectors, 5), 0.001);
}

TEST(HW5_ConvexPolygon, HexagonArea)
{
    double a[2] = {1, 0},
           b[2] = {4, 0},
           c[2] = {5, 2},
           d[2] = {4, 4},
           e[2] = {1, 4},
           f[2] = {0, 2};
    Vector u = Vector(a, 2);
    Vector v = Vector(b, 2);
    Vector w = Vector(c, 2);
    Vector x = Vector(d, 2);
    Vector s = Vector(e, 2);
    Vector bs = Vector(f, 2);
    Vector vectors[6] = {bs, u, w, v, x, s};
    ASSERT_NEAR(16, area(vectors, 6), 0.001);
}

TEST(HW5_ConvexPolygon, PentagonPerimeter)
{
    double a[2] = {1, 0},
           b[2] = {4, 0},
           c[2] = {4, 4},
           d[2] = {1, 4},
           e[2] = {3, 5};
    Vector u = Vector(a, 2);
    Vector v = Vector(b, 2);
    Vector w = Vector(c, 2);
    Vector x = Vector(d, 2);
    Vector p = Vector(e, 2);
    Vector vectors[5] = {u, v, w, x, p};
    ASSERT_NEAR(sqrt(2) + sqrt(5) + 8 + 3, perimeter(vectors, 5), 0.001);
}

TEST(HW5_ConvexPolygon, HexagonPerimeter)
{
    double a[2] = {1, 0},
           b[2] = {4, 0},
           c[2] = {5, 2},
           d[2] = {4, 4},
           e[2] = {1, 4},
           f[2] = {0, 2};
    Vector u = Vector(a, 2);
    Vector v = Vector(b, 2);
    Vector w = Vector(c, 2);
    Vector x = Vector(d, 2);
    Vector s = Vector(e, 2);
    Vector bs = Vector(f, 2);
    Vector vectors[6] = {bs, u, w, v, x, s};
    ASSERT_NEAR(4 * sqrt(5) + 2 * 3, perimeter(vectors, 6), 0.001);
}

TEST(VectorTest, SimpleCreateVector1)
{
    double v1[] = {1, 2, 3};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    ASSERT_NEAR(sqrt(14), vec->length(), alpha);
    ASSERT_EQ(3, vec->dim());
}

TEST(VectorTest, SimpleCreateVector2)
{
    double v1[] = {1, 2, 3};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(*vec);
    ASSERT_NEAR(sqrt(14), vec->length(), alpha);
    ASSERT_EQ(3, vec->dim());
}

TEST(VectorTest, SimpleCreateVector3)
{
    double v1[] = {1, 2, 3};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    ASSERT_NEAR(sqrt(14), vec->length(), alpha);
    ASSERT_EQ(3, vec->dim());
}

TEST(VectorTest, Subtraction1)
{
    double v1[] = {1, 2, 3};
    double v2[] = {4, 5, 6};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 3);
    vec1->subtract(*vec);
    ASSERT_NEAR(sqrt(27), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(3, vec1->at(1));
    ASSERT_EQ(3, vec1->at(2));
    ASSERT_EQ(3, vec1->at(3));
}

TEST(VectorTest, Subtraction2)
{
    double v1[] = {1, 1, 4};
    double v2[] = {5, 1, 4};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 3);
    vec1->subtract(*vec);
    ASSERT_NEAR(sqrt(16), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(4, vec1->at(1));
    ASSERT_EQ(0, vec1->at(2));
    ASSERT_EQ(0, vec1->at(3));
}

TEST(VectorTest, Subtraction3)
{
    double v1[] = {1, 1, 4};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(*vec);
    vec1->subtract(*vec);
    ASSERT_NEAR(sqrt(0), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(0, vec1->at(1));
    ASSERT_EQ(0, vec1->at(2));
    ASSERT_EQ(0, vec1->at(3));
}

TEST(VectorTest, Subtraction4)
{
    double v1[] = {1, 1, 4};
    double alpha = 0.001;
    Vector vec = Vector(v1, 3);
    Vector *vec1 = new Vector(vec);
    vec1->subtract(vec);
    ASSERT_NEAR(sqrt(0), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(0, vec1->at(1));
    ASSERT_EQ(0, vec1->at(2));
    ASSERT_EQ(0, vec1->at(3));
}
TEST(VectorTest, SubtractionException)
{
    double v1[] = {1, 1, 4};
    double v2[] = {1, 1, 4, 5};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 4);
    ASSERT_ANY_THROW(vec1->subtract(*vec));
}
TEST(VectorTest, Subtract1)
{
    double v1[] = {1, 1, 4};
    double v2[] = {2, 3, 3};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 3);
    Vector temp = *vec1 - *vec;
    ASSERT_NEAR(sqrt(6), temp.length(), alpha);
    ASSERT_EQ(3, temp.dim());
    ASSERT_EQ(1, temp.at(1));
    ASSERT_EQ(2, temp.at(2));
    ASSERT_EQ(-1, temp.at(3));
}

TEST(VectorTest, Subtract2)
{
    double v1[] = {1, 1, 4};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(*vec);
    Vector temp = *vec1 - *vec;
    ASSERT_NEAR(sqrt(0), temp.length(), alpha);
    ASSERT_EQ(3, temp.dim());
    ASSERT_EQ(0, temp.at(1));
    ASSERT_EQ(0, temp.at(2));
    ASSERT_EQ(0, temp.at(3));
}

TEST(VectorTest, SubtractException)
{
    double v1[] = {1, 1, 4};
    double v2[] = {3, 1, 1, 4};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 4);
    ASSERT_ANY_THROW(Vector temp = *vec1 - *vec);
}

TEST(VectorTest, Addition1)
{
    double v1[] = {1, 2, 3};
    double v2[] = {4, 5, 6};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 3);
    vec1->add(*vec);
    ASSERT_NEAR(sqrt(155), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(5, vec1->at(1));
    ASSERT_EQ(7, vec1->at(2));
    ASSERT_EQ(9, vec1->at(3));
}

TEST(VectorTest, Addition2)
{
    double v1[] = {1, 1, 4};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(*vec);
    vec1->add(*vec);
    ASSERT_NEAR(sqrt(72), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(2, vec1->at(1));
    ASSERT_EQ(2, vec1->at(2));
    ASSERT_EQ(8, vec1->at(3));
}

TEST(VectorTest, Addition3)
{
    double v1[] = {1, 1, 4};
    double alpha = 0.001;
    Vector vec = Vector(v1, 3);
    Vector *vec1 = new Vector(vec);
    vec1->add(vec);
    ASSERT_NEAR(sqrt(72), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(2, vec1->at(1));
    ASSERT_EQ(2, vec1->at(2));
    ASSERT_EQ(8, vec1->at(3));
}
TEST(VectorTest, AdditionException)
{
    double v1[] = {1, 1, 4};
    double v2[] = {1, 1, 4, 5};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 4);
    ASSERT_ANY_THROW(vec1->add(*vec));
}

TEST(VectorTest, Add1)
{
    double v1[] = {1, 1, 4};
    double v2[] = {2, 3, 3};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 3);
    Vector temp = *vec1 + *vec;
    ASSERT_NEAR(sqrt(74), temp.length(), alpha);
    ASSERT_EQ(3, temp.dim());
    ASSERT_EQ(3, temp.at(1));
    ASSERT_EQ(4, temp.at(2));
    ASSERT_EQ(7, temp.at(3));
}

TEST(VectorTest, Add2)
{
    double v1[] = {1, 1, 4};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(*vec);
    Vector temp = *vec1 + *vec;
    ASSERT_NEAR(sqrt(72), temp.length(), alpha);
    ASSERT_EQ(3, temp.dim());
    ASSERT_EQ(2, temp.at(1));
    ASSERT_EQ(2, temp.at(2));
    ASSERT_EQ(8, temp.at(3));
}

TEST(VectorTest, AddException)
{
    double v1[] = {1, 1, 4};
    double v2[] = {3, 1, 1, 4};
    double alpha = 0.001;
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(v2, 4);
    ASSERT_ANY_THROW(Vector temp = *vec1 + *vec);
}

TEST(VectorTest, AssignmentOperator1)
{
    double v1[] = {1, 2, 3};
    Vector vec = Vector(v1, 3);
    double alpha = 0.001;
    ASSERT_NEAR(sqrt(14), vec.length(), alpha);
    ASSERT_EQ(3, vec.dim());
}

TEST(VectorTest, AssignmentOperator2)
{
    double v1[] = {1, 2, 3};
    Vector *vec1 = new Vector(v1, 3);
    Vector vec = Vector(*vec1);
    double alpha = 0.001;
    ASSERT_NEAR(sqrt(14), vec.length(), alpha);
    ASSERT_EQ(3, vec.dim());
}

TEST(VectorTest, AssignmentOperator3)
{
    double v1[] = {1, 2, 3};
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(*vec);
    Vector vec2 = Vector(*vec1);
    double alpha = 0.001;
    ASSERT_NEAR(sqrt(14), vec2.length(), alpha);
    ASSERT_EQ(3, vec2.dim());
}

TEST(VectorTest, AssignmentOperator4)
{
    double v1[] = {1, 2, 3};
    double v2[] = {2, 3, 3};
    Vector *vec = new Vector(v1, 3);
    Vector *vec1 = new Vector(*vec);
    Vector vec2 = Vector(v2, 3);
    double alpha = 0.001;
    vec2.add(*vec1);
    vec1->subtract(vec2);
    vec1->add(*vec);
    ASSERT_NEAR(sqrt(70), vec2.length(), alpha);
    ASSERT_EQ(3, vec2.dim());
    ASSERT_EQ(3, vec2.at(1));
    ASSERT_EQ(5, vec2.at(2));
    ASSERT_EQ(6, vec2.at(3));
    ASSERT_NEAR(sqrt(2), vec1->length(), alpha);
    ASSERT_EQ(3, vec1->dim());
    ASSERT_EQ(-1, vec1->at(1));
    ASSERT_EQ(-1, vec1->at(2));
    ASSERT_EQ(0, vec1->at(3));
}

#endif