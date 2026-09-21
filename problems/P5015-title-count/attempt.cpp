#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int sum=0;
    getline(cin,a);
    for(int i=0;i<(static_cast<int>(a.size()));i++){
        if(a[i]!=' ')sum++;
    }
    cout << sum << endl;
    return 0;
}