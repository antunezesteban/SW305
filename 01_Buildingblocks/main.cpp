#include <iostream>
using namespace std;
template<typename T>
void static Swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
};

template<typename P>
static void Print(const P& array) {
  for (auto element : array) {
    cout << element << " ";
  }
  cout << endl;


};
int main() {
  cout<<"Building blocks"<<endl;
  int A[] = {7,3};
  Print(A);
  Swap(A[0], A[1]);
  Print(A);


  return 0;
}