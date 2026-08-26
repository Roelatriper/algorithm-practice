#include <iostream>
using namespace std;
int n;
int a[1000];
int js(int i){
    if(i == 0 || i == 1) return 1;
    else if(a[i] != 0) return a[i];
    else{
        a[i] = js(i-1) + js(i-2);
        return a[i];
    }
}
int main(){
    cin >> n;
    cout << js(n) << endl;
    return 0;
}