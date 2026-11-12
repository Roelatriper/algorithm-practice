#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int t;
    cin >> t;
    vector<int> ans(t);
    
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool pen=1;
        ans[i]=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='B'/*B->0 */){
                if(pen==1){
                    ans[i]++;
                }else pen=1;
            }if(s[j]=='R'){
                if(pen==0){
                    ans[i]++;
                }else pen=0;
            }
        }
    }
    for(int i=0;i<t;i++){
        cout << ans[i] << endl;
    }

    return 0;
}