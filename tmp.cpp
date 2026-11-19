#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int istrue(const void *a,const void *b){
  int tmp_1 = *(const int*)a;
  int tmp_2 = *(const int*)b;
  return (tmp_1<tmp_2)-(tmp_1>tmp_2);
}

int main(){
  int n;
  cin >> n;
	vector<int> a(n);5
  for(int i=0;i<n;i++)cin >> a[i];
  qsort(a.data(),n,sizeof(int),istrue);
  cout << a[0] << " " << a[1] << endl;
  
  
  
  return 0;
}



/*
int cmp_int(const void* a,const void* b){
  int x=*(const int*)a;
  int y=*(const int*)b;
  return (x>y) - (y<x);
}

  int n;
  int a[100];
  qsort(&a,100,sizeof(int),cmp_int);
*/