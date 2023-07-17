#include "../src/chk_string.h"

TEST(CHKUPPER, case1){
  string test = "AAAbCCCdEE";
  vector<int> result = checkUpper(test);
  ASSERT_EQ(3, result[0]);
  ASSERT_EQ(3, result[1]);
  ASSERT_EQ(2, result[2]);
}
TEST(CHKUPPER,case2){
  string test="AA1b3CCC";
  vector<int> result = checkUpper(test);
  ASSERT_EQ(2,result[0]);
  ASSERT_EQ(3,result[1]);
}
/*TEST(CHKALPHA,case1){
  string test="AA1b3CCC";
  int result = checkAlpha(test);
  ASSERT_EQ(1,result);
}*/
TEST(CHKERROR,case1){
  string input="!!!";

  try{
    checkError(input);
  }catch(const invalid_argument& ia){
    ASSERT_EQ(ia.what(), string("checkError")); // string
    //ASSERT_STREQ(ia.what(), "Error"); // char * = c string
  }
}
