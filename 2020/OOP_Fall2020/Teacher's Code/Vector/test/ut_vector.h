#include "../src/vector.h"
#include "../src/dot.h"

TEST(CHKDOT, case1){
  double input[2] = {1,1};
  double input1[2] = {1,0};

  double result = dot(input, 2, input1, 2);

  ASSERT_EQ(1, result);
}
TEST(CHKDOT, case2){
  double input[3] = {1,1,0};
  double input1[2] = {1,0};
  try{
    double result = dot(input, 3, input1, 2);
    FAIL() << "Shuold not be here"; // added before class
  }catch(string s){
    ASSERT_EQ("ERROR",s);
  }
}

TEST(CHKDOT, case3){
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);
  double a[]={1, 1, 1};
  mathVector x = mathVector(a, 3);

  ASSERT_EQ(dot(x, v), 13);
}

TEST(CHKVECTOR,case1){
  double a[2];
  double b[]={2, 5, 6};
  double *c = new double[2];

  string x = string("123");
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.dimension(), 3);

  delete [] c;
}

TEST(CHKVECTOR,case2){
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);

  double c[]={1, 7, 8};
  mathVector w = mathVector(c, 3);

  ASSERT_EQ(v.dot(w), 85);
}

TEST(CHKVECTOR,case3){ // copy constructer test case
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);

  mathVector w(v); // copy constructer
  mathVector x = v; // copy constructer
  mathVector y = mathVector(v); // copy constructer

  ASSERT_EQ(w.dimension(),3);
}

TEST(CHKVECTOR,case4){ // copy assignment test case
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);

  double c[]={1, 7};
  mathVector w = mathVector(c, 2);

  w = v; // copy assignment !

  ASSERT_EQ(w.dimension(),3);
}

TEST(CHKVECTOR,case5){ // copy assignment test case
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);

  double c[]={1, 7};
  mathVector w = mathVector(c, 2);

  double d[]={1, 7, 9, 8};
  mathVector z = mathVector(d, 4);

  w = v = z; // copy assignment !

  ASSERT_EQ(w.dimension(), 4);
}

TEST(CHKLEN,case1){
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.dimension(), 3);
  v.setDimension(1);
  ASSERT_EQ(v.dimension(), 1);
}

TEST(CHKCOMPONENT,case1){
  double b[]={2, 5, 6};
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.component(1), 2);
  v.component(1) =18;
  ASSERT_EQ(v.component(1), 18);
}

TEST(CHKLENGTH,case1){
  double b[]={3, 4, 12};
  mathVector v = mathVector(b, 3);
  ASSERT_EQ(v.length(), 13);
}

TEST(CHKSUB,case1){
  double a[]={6, 8, 24};
  mathVector v = mathVector(a, 3);
  double b[]={3, 4, 12};
  mathVector w = mathVector(b, 3);
  mathVector r = v - w;
  ASSERT_EQ(3,r.component(1));
}

TEST(CHKAREA,case1){
  double a[]={0, 6};
  mathVector v = mathVector(a, 2);
  double b[]={4, 0};
  mathVector w = mathVector(b, 2);
  double c[] = {0, 0};
  mathVector x = mathVector(c, 2);
  ASSERT_NEAR(12, x.getArea(v, w), 0.001);
}
/*TEST(CHKALPHA,case1){
  string test="AA1b3CCC";
  int result = checkAlpha(test);
  ASSERT_EQ(1,result);
}
TEST(CHKERROR,case1){
  string input="!!!";

  try{
    checkError(input);
  }catch(const invalid_argument& ia){
    ASSERT_EQ(ia.what(), string("checkError")); // string
    //ASSERT_STREQ(ia.what(), "Error"); // char * = c string
  }
}*/
TEST(CHKANGLE,case1){
  double a[]={0, 6};
  mathVector v = mathVector(a, 2);
  double b[]={4, 0};
  mathVector w = mathVector(b, 2);
  ASSERT_NEAR(90, v.angle(w), 0.001);
}
TEST(CHKCENTROID,case1){
  double a[]={0, 6};
  mathVector v = mathVector(a, 2);
  double b[]={4, 0};
  mathVector w = mathVector(b, 2);
  mathVector x[2] = {v,w};
  mathVector y = mathVector::centroid(x, 2);
  ASSERT_NEAR(2, y.component(1), 0.001);
  ASSERT_NEAR(3, y.component(2), 0.001);
}
