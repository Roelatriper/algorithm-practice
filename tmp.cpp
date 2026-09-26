//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap_values(int* x, int* y);       // 交换两个地址指向的数值
void swap_addresses(int*& x, int*& y);  // 交换两个指针保存的地址
int main(){
    int x=1,y=2,*a=&x,*b=&y;
    swap_values(&x,&y);
    cout << x << y << endl;
    *a=1;*b=2;
    swap_addresses(a,b);
    cout << x << y;
    return 0;
}
void swap_addresses(int *&x,int *& y){
    int *tmp=x;
    x=y;y=tmp;
}
void swap_values(int *x,int *y){
    int tmp;
    tmp=*x;*x=*y;*y=tmp;
}