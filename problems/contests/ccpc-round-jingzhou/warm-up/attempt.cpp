#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  double tmp=0;
  cin >> n;
 	vector<int> a(n);
  for(int i=0;i<n;i++){cin >> a[i];tmp+=a[i];}
  sort(a.begin(),a.end());
  cout << "Max=" << a[n-1] << endl;
  cout << "Min=" << a[0] << endl;
  printf("%.2f\n",tmp/n);
  
  
  return 0;
}