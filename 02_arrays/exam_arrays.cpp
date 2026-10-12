#include <algorithm>
#include <iostream>
#include <array>
#include <format>
#include <random>


#include "../01_Buildingblocks/Helpers.h"



static void array_example(){
     std::array<int, 9> x_vals {100, 200, 300, 400, 500, 600, 700, 800, 900};
      std::cout<<"x_vals"<<std::endl;
      for(auto value : x_vals){
        std::cout<<value<<"   "<<std::endl;
      }
      std::cout<<std::endl;

    for (auto it = x_vals.begin(); it != x_vals.end(); it++) {
      std::cout<<*it;
    }
  std::cout<<"size"<<x_vals.size()<<std::endl;
}


static void array_example3() {
  std::array<double,8> radios{1.0 ,1.4 ,2.8,4.0,5.6,8.0,11.0};
  std::array<double,radios.size()> areas{};
  double pi = 3.1415;
  auto it_a = areas.begin();
  for (auto it_r = radios.begin(); it_r != radios.end(); ++it_r, ++it_a) {
    *it_a =  pi * (*it_r)*(*it_r);
  }

  //print
  it_a = areas.begin();
  std::cout<<"Radios\tAreas"<<std::endl;
  for (auto it_r = radios.begin(); it_r != radios.end(); ++it_r, ++it_a) {
    std::cout<<*it_r<<"\t"<<*it_a<<std::endl;
  }

}


static void array_example4() {
  constexpr size_t epl_max{5};
  std::array<std::string,15> colors_1{"Yellow","Black","White","Red", "Pink","Brown","Orange", "Green","Blue","Purple","Amber","Pearl","Grey","Magenta", "Dust"};
  auto colors_2 {colors_1};
  print_container("colors_1 : ", colors_1, epl_max);
  print_container("colors_2 : ", colors_2, epl_max);

  std::sort(colors_1.begin(), colors_1.end());
  print_container("colors_1 : ", colors_1, epl_max);

  std::sort(colors_2.begin(), colors_2.end());
  print_container("colors_2 (after::ranages sort): ", colors_2, epl_max);

  //comparar
  std::cout<<std::format("colors_1 == colors_2 : {:s} ", colors_1 == colors_2);
}
int main() {

  array_example4();

    return 0;
}