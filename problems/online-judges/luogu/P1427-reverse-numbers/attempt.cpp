#include <iostream>
#include <vector>
using namespace std;
int main(){
    int tmp=0;
    vector<int> s;
    bool a=1;
    while(a){
        cin >> tmp;
        if(tmp == 0){a=0;break;}
        s.push_back(tmp);
    }
    for (int i=static_cast<int>(s.size()); i > 0; --i) {
        cout << s[i - 1] << " ";
    }cout << endl;
    return 0;
}