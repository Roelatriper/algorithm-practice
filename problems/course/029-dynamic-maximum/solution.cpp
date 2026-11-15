#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

int main(){
    ll int n,tmp;
    cin >> n;
    priority_queue<ll int> aminos;
    queue<ll int> ans;
    for(int i=0;i<n;i++){
        char a;
        cin >> a;
        switch(a){
            case 'A':      
                cin >> tmp;
                aminos.push(tmp);
                continue;
            case 'Q':
                if(!aminos.size()){cout << "EMPTY" << endl;}
                else {
                    cout << aminos.top() << endl;
                }continue;
            case 'R':
                if(!aminos.size())continue;
                else {
                    aminos.pop();
                }continue;
            default:
                break;   
        }
    }



    return 0;
}