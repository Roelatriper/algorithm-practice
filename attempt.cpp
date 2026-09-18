#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct interval{
    int start;
    int end;
};
bool retr(const interval &a,const interval &b){
    return a.end < b.end;
}
int main(){
    int n,ans=0,tmp=0;
    cin >> n;
    if(n==0)goto flag;
    else {
        vector<interval> data(n);
        // vector<int> tmp(n);
            for(int i=0;i<n;i++){cin >> data[i].start >> data[i].end;}
            sort(data.begin(),data.end(),retr);
            ans++;
            for(int i=1;i<n;i++){
                if(data[i].start >= data[tmp].end){ans++;tmp=i;}
            }
    }
    flag:
    cout << ans << endl;
    return 0;
}