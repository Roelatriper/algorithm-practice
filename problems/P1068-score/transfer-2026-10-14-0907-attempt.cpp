//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
struct node{
    int penalty,score,id;
};
bool cmp(const node& a,const node&b){
    if(a.score==b.score){
        if(a.penalty==b.penalty){
            return a.id > b.id;
        }else return (a.penalty < b.penalty);
    }else return a.score > b.score;
}

int main(){
    int a;
    cin >> a;
    vector<node> str(a);
    for(int i=0;i<a;i++){
        cin >> str[i].score >> str[i].penalty;
        str[i].id=i+1;
    }sort(str.begin(),str.end(),cmp);
    for(int i=0;i<a;i++){
        cout << str[i].id << endl;
    }

    return 0;
}