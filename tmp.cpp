#include <iostream>
#include <vector>

using namespace std;

int main(){
  string a,b;
  bool istrue=1;
  getline(cin,a);
  getline(cin,b);
  for(int i=0;i<a.size();i++){
    if(a[i++]==b[0]){
      istrue=1;
      for(int j=1;j<b.size();j++){
        if(a[i++]!=b[j]){
          istrue=0;
        }
      }if(istrue){
        cout << "the pattern string:" << b << "is in the target string: " << a << ", the location is: " << i << endl;
        return 0;
      }
    }
  }
 	cout << "the pattern string is not " << b <<  " in the target string" << a << endl;
  
  return 0;
}