//first attempt at 20:30
#include <iostream>
#include <vector>

using namespace std;
struct entry{
    int key,value;
};
int altogether=10003;
vector<vector<entry> > buckets(altogether);

void keystore(const int &key){
    int tmp=key%altogether;
    tmp<0?tmp+=altogether:1;
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
    int tmp=key%altogether;
    tmp<0?tmp+=altogether:1;
    for(int j=0;j<static_cast<int>(buckets[tmp].size());j++){
        if(buckets[tmp][j].key==key)return buckets[tmp][j].value;
    }
    return 0;
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(getvalue(a[i])>0){cout << i+1<< endl;return 0;}
        keystore(a[i]);
    }
    cout << 0 << endl;
    return 0;
}
