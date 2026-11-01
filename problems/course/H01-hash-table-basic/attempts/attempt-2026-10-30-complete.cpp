//first attempt at 20:30
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
struct entry{
    int key,value;
};
vector<vector<entry> > buckets(7);

void keystore(const int &key){
    int tmp=key%7;
    tmp<0?tmp+=7:1;
    for(int j=0;j<static_cast<int>(buckets[tmp].size());j++){
        if(buckets[tmp][j].key==key){
            buckets[tmp][j].value+=1;
            return ;
        }
    }
    entry ttmp;
    ttmp.key=key;ttmp.value=1;
    buckets[tmp].push_back(ttmp);
    return ;
}

int getvalue(const int &key){
    int tmp=key%7;
    tmp<0?tmp+=7:1;
    for(int j=0;j<static_cast<int>(buckets[tmp].size());j++){
        if(buckets[tmp][j].key==key)return buckets[tmp][j].value;
    }
    return 0;
}


int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> query(q),ans(q);
    for(int i=0;i<n;i++){
        cin >> a[i];
        keystore(a[i]);
    }for(int i=0;i<q;i++){
        cin >> query[i];
        ans[i]=getvalue(query[i]);
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << endl;
    }

    return 0;
}