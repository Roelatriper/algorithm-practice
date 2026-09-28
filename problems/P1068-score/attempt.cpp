#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct comp{
    unsigned short int num,score;
};
bool istrue1(const comp& a,const comp& b){
    if(a.score == b.score){
        return a.num < b.num;
    }else return a.score > b.score;
}
int main(){
    int tmp,n,enroll;
    cin >> n >> enroll;
    vector<comp> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].num >> a[i].score;
    }
    if(enroll%2!=0){
        tmp=(enroll+1)/2+enroll;
    }else tmp=enroll*1.5;
    sort(a.begin(),a.end(),istrue1);
    cout << a[tmp-1].score << " " << tmp << endl;
    for(int i=0;i<tmp;i++){
        cout << a[i].num << " " << a[i].score << endl;
    }

    return 0;
}