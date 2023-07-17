#include <iostream>
using namespace std;

namespace sp1
{
  void greeting()
  {
    cout << "greeting1";
  }
}

namespace sp2
{
  void greeting()
  {
    cout << "greeting2";
  }
}

int main()
{
  {
    using namespace sp2;
    greeting();
  }
  {
    using namespace sp1;
    greeting();
  }
  return 0;
}
