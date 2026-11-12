#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > piles; 

int main(){
    int n;
    cin >> n;
    piles a(n,vector<int>(3));
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)cin >> a[i][j];
        if(a[i][0]!=a[i][1] && a[i][0]!=a[i][2] && a[i][1]!=a[i][2]){
            int tmp=a[i][0]+a[i][1]+a[i][2];
            if(tmp%3!=0){
                ans[i]=0;
                continue;
            }tmp/=3;
            for(int k=0;k<3;k++){
                if(tmp==a[i][k]){
                    a[i][k]=0;
                    int ttmp=0;
                    for(int sp=0;sp<3;sp++){
                        if(a[i][sp] && !ttmp){
                            ttmp=a[i][sp];
                            // cout << "ttmp is valued." << endl;
                            continue;
                        }
                        if((ttmp && a[i][sp]) && (ttmp-a[i][sp]==2 || ttmp-a[i][sp]==-2)){
                            ans[i]=1;
                            goto flag;
                        }
                    }ans[i]=0;
                    goto flag;
                }
            }
            flag:
        }else {ans[i]=0;}
    }
    for(int i=0;i<n;i++){
        if(ans[i]==1)std::cout << "YES" << endl;
        else std::cout << "NO" << endl;
    }

    return 0;
}