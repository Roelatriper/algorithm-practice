#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
    int val,num;
};
bool istrue(const node& a,const node& b){
    return a.val > b.val;
}
int main(){
    int n;
    cin >> n;
    vector<node> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i].val;
        s[i].num=i;
    }sort(s.begin(),s.end(),istrue);
    int beg=0,ans=0;
    bool f=1;
    for(int i=0;i<n;i++){
        if(f==0){
            beg=i;
            f=1;
        }else {
            if(s[i+1].val != s[i].val){
                f=0;
                if(beg==i+1)continue;
                for(int j=beg;j<=i-1;j++){
                    for(int k=beg+1;k<=i;k++){
                        ans+=abs(s[k].num-s[j].num);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
