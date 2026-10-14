#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct excel{
    string name;
    unsigned short int y,m,d,num; 
};
bool istrue1(const excel& a,const excel& b){
    if(a.y == b.y){
        if(a.m == b.m){
            if(a.d == b.d){
                return a.num > b.num;
            }else return a.d < b.d;
        }else return a.m < b.m;
    }else return a.y < b.y;
}

int main(){
    int n;
    cin >> n;
    vector<excel> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i].name >> p[i].y >> p[i].m >> p[i].d;
        p[i].num = i;
    }    
    sort(p.begin(),p.end(),istrue1);
    for(int i=0;i<n;i++){
        cout << p[i].name << endl;
    }


    return 0;
}