#include <iostream>
#include <string_view>
#include <functional>
#include <unordered_map>
#include <stb_image.h>
//forward
typedef struct GLFWwindow GLFWwindow;
//typedef
using tTestKey = std::string_view;
using tTestFun = std::function<int(void)>;
using tTestTab = const std::unordered_map<tTestKey, tTestFun>;
using tTestRef = tTestTab::const_iterator;
//actions
int main(int vArgC, char **vArgV)
{
  if (vArgC == 3 ? (std::string_view(vArgV[1]) == "test") : 0)
  {
    extern tTestTab vTestTab;
    tTestRef vTestRef = vTestTab.find(vArgV[2]);
    if (vTestRef == vTestTab.end())
    {
      return EXIT_FAILURE;
    }
    else
    {
      std::cout << vTestRef->first << "=" << std::endl;
      auto vCode = vTestRef->second();
      std::cout << "=" << vTestRef->first << std::endl;
      return vCode;
    }
  }
  else
  {
    std::copy(
      &vArgV[0],
      &vArgV[vArgC],
      std::ostream_iterator<char*>(std::cout, "\n")
    );
  }
  return EXIT_SUCCESS;
}//main
tTestTab vTestTab = {
  { "HelloWorld",
    []()
    {
      std::cout << "HelloWorld" << std::endl;
      return EXIT_SUCCESS;
    }
  },//HelloWorld
};//vTestTab
