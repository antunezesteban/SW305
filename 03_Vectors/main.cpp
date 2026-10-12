#include<vector>
#include <iostream>
#include "../01_Buildingblocks/Helpers.h"
#include <format>
#include <cmath>
#include <algorithm>

static void vector_example1(){
      std::vector<int> v1{1,2,3,4,5};
      std::vector<int> v2(v1.size());
      std::vector<int> v3(v1.size(),7);
      print_container("V1",v1);
      print_container("V2",v2);
      print_container("V3",v3);

    //operador [] or .at
    for (size_t i = 0; i < v1.size(); ++i) {
        v2[i] = v1[i] * v3.at(i);
    }

    print_container("V2",v2);

    //mas vectores

    std::vector<unsigned long long> v4{100, 200, 300, 400 ,500, 600,700,800,900,1000};
    std::vector<unsigned long long> v5(v4.size(),100);
    std::vector<unsigned long long> v6{v4.size()};
    std::vector<unsigned long long> v7{};
    print_container("V4",v4);
    print_container("V5",v5);
    print_container("V6",v6);
    print_container("V7",v7);

    //iteradores

    auto it4 = v4.begin();
    auto it5 = v5.begin();

    for (;it4 != v4.end();it4++,it5++) {
        *it5 = *it4/2;
    }

    print_container("V5 after operation",v5);

    //front or back

    std::cout<<std::format("v4.front():  {:6d}",v4.front())<<std::endl;

    std::cout<<std::format("v4.back():  {:6d}",v4.back())<<std::endl;
}

static void vector_example2() {
    constexpr size_t n{10};
    std::vector<double> v1{};
    //push_back
    for (size_t i= 0; i < n; ++i ) {
        v1.push_back(std::sqrt(i + 1));
    }

    print_container("V1 (initial values) : ",v1);

    while (v1.size() >= n/2) {
        v1.pop_back();
    }

    print_container("V2 (later values) : ",v1);

    //add elements

    std::array<double,n> a1{10,20,30,40,50,60,70,80,90,100};
    v1.insert(v1.begin() + 2,a1.begin(),a1.end());

    print_container("V1 (after insert values) : ",v1);

    //add elements

    std::array<double,6> a2{ -10.0,-20.0,-30.0,-40.0,-50.0,-60.0};
    v1.insert(v1.end(),a2.begin(),a2.end());

    //remove
    v1.erase(v1.begin() + 3,v1.begin()+ 5);
    //ps: uno no puede usar end en last porque el end de v1 ahi es el siguiente del ultimo respectivo valor, osea afuera de el vector


    print_container("V2 (after erasure values) : ",v1);


}


static void vector_example3() {
    std::vector<std::string> planets1;
    const char *planets_cstring1[] = {"Mercury", "Venus" , "Earth", "Mars"};
    const char *planets_cstring2[] = {"Jupiter", "Saturn" , "Uranus", "Neptune"};

    std::ranges::copy(planets_cstring1,std::back_inserter(planets1));
    print_container("Planets1",planets1);
    //emplace_back
    std::vector <std::string> planets2{planets1};
    planets2.emplace_back(planets_cstring2[0]);
    planets2.emplace_back(planets_cstring2[1]);
    planets2.emplace_back(planets_cstring2[2]);
    planets2.emplace_back(planets_cstring2[3]);
    print_container("Planets2",planets2);
    //std::ranges::find
    auto it_Mars = std::ranges::find(planets2, "Mars");
    bool found_mars= it_Mars != planets2.end();
    std::cout<<(found_mars ? "Found":"Not found") << std::endl;
    std::cout<<"Value : "<<*it_Mars<<std::endl;
    print_container("Mars",*it_Mars);
    //sort
    auto planets3{planets2};
    print_container("Planets3 : ",planets3);
    std::ranges::sort(planets3);
    print_container("Planets3 (after sort ) : ",planets3);
    //relational operators
    std::cout<<std::format("planets2 == planets3 : {:s}",planets2 == planets3)<<std::endl;
    //swap
    std::swap(planets3[3],planets3[4]);
    print_container("Planets3 (after swap): ",planets3);
}


static void vector_example4() {
    constexpr double rem_val{-1.0};
    std::vector<double> v1{10,20,rem_val,40,rem_val,60,rem_val,80,90,100};
    std::vector<double> v2{v1};
    print_container("V1 (initial values) : ",v1);

    //remove
    auto removed_items = std::ranges::remove(v1.begin(),v1.end(), rem_val);
    print_container("V1 (after removal) : ",v1);
    std::cout<<"size v1 : "<<v1.size()<<std::endl;
    print_container("removed items ",removed_items);
    //vector erase
    v1.erase(removed_items.begin(),removed_items.end());
    print_container("V1 (after removal) : ",v1);
    //std::erase      (ps : este erase esta realizando el proceso de .remove y .erase juntos)
    print_container("v2 (intial values)",v2);
    auto num_erased = std::erase(v2 , rem_val);
    std::cout<<std::format("num_erased : {:d}",num_erased)<<std::endl;
    print_container("V2 (after erasing values) : ",v2);


}

int main() {
    std::cout<<"Vectors : "<<std::endl;
    //vector_example1();
    //vector_example2();
    //vector_example3();
    vector_example4();
    return 0;
}