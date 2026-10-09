#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << "Dimensions: " << a << "x" << b << "x" << c << endl;
  cout << "Volume(cubic inches): " << a*b*c << endl;
  cout << "Dimensional weight(pounds): " << (a*b*c)/166 << endl;
  
  
  return 0;
}