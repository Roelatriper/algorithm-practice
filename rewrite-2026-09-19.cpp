#include <iostream>
#include <algorithm>
#include <vector>
struct interval{
    int begin;
    int end;
};
bool comp(interval &a,interval &b){
  return a.end < b.end;  
}
using namespace std;
int main(){
    int n=0,point=0,ans=0;
    cin >> n;
    if(n==0){
        cout << "0" << endl;
        return 0;
    }
    vector<interval> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i].begin >> s[i].end;
    }
    sort(s.begin(),s.end(),comp);
    ans++;
    for(int i=1;i<n;i++){
        if(s[point].end <= s[i].begin){ans++;point=i;}
    }
    cout << ans << endl;
    return 0;
}