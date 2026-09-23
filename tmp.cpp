//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool down_sort(const int& a,const int& b){
    return a > b;
}
int main(){
    vector<int> a;
    int tmp;
    while(cin >> tmp){a.push_back(tmp);}
    sort(a.begin(),a.end(),down_sort);
    for(int t=0;t<static_cast<int>(a.size());t++){cout << a[t] << " ";}
    return 0;
}
