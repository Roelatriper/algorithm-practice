#include <iostream>
#include <vector>


using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<unsigned int> s(n),each(n),ans(q);
    for(int i=0;i<n;i++){
        int buffer;
        cin >> buffer;
        if(buffer>=60 && i==0){
            s[0]=1;
            each[0]=1;
        }else{
            s[0]=0;
            each[0]=0;
        }
        if(buffer>=60 && i!=0){
            s[i]+=(s[i-1]+1);
            each[i]=1;
        }else {
            s[i]+=s[i-1];
            each[i]=0;
        }
    }
    vector<vector<int> > query(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin >> query[i][0] >> query[i][1];
        ans[i]=s[query[i][1]-1]-s[query[i][0]-1]+each[query[i][0]-1];
    }for(int i=0;i<q;i++){
        cout << ans[i]<< endl;
    }


    return 0;
}