// 赛场作答（CCPC 荆州站正式赛，打印稿 00001145，14:01:45 打印）
// 原样保留，订正与参考实现另存 solutions/。
#include <iostream>
#include <vector>

using namespace std;
int js(double x, double b, double d){
    if(x/2-d/2<=b){
        double tmp=b-x/2;
        if(x/2+tmp<=b){
            return 1;
        }else {
            double r_tmp=x/2+d/2;
            return js(r_tmp,b,d)+1;
        }
    }else {
        double f_1=x/2-d/2;
        double f_2=x/2+d/2;
        return js(f_1,b,d)+js(f_2,b,d);
    }
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    double x,b,d;
    vector<int> ans(T);
    for(int i=0;i<T;i++){
        cin >> x >> b >> d;
        if(x<=b){
            ans[i]=0;
        }else ans[i]=js(x,b,d);
    }
    for(int i=0;i<T;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
