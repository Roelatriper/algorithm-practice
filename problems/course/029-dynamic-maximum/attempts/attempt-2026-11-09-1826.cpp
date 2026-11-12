#include <iostream>
#include <vector>
#include <queue>
#include <optional>
typedef long long int ll;
using namespace std;


bool istrue(const int&a,const int&b){
    return a<b;
}

void output_func(vector<ll>& array){
    if(array.size()!=0)cout << array.back() << endl;
    else cout << "EMPTY" << endl;
    return ;
}

int main(){
    queue<int> buffer;
    vector<ll> array;
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        char letter;
        cin >> letter;
        switch(letter){
            case 'A':
                ll tmp;
                cin >> tmp;
                array.push_back(tmp);
                break;
            case 'R':
                buffer.push(1);
                break;
            case 'Q':
                if(buffer.size()!=0)buffer.push(0);
                else buffer.push(2);
                break;
            default:
                return 1;
        }
    }
    int tmp=static_cast<int>(buffer.size());
    sort(array.begin(),array.end(),istrue);
    for(int i=0;i<tmp;i++){
        if(buffer.front()==2){
            cout << "EMPTY" << endl;
            buffer.pop();
            continue;
        }
        if(buffer.front()==1){
            if(array.size()!=0)array.pop_back();
            buffer.pop();
        }else {
            output_func(array);
            buffer.pop();
        }
    }

    return 0;
}
//十分丑陋
//3 A 1 R Q ->EMPTY 测试各项功能正常
//2 R Q -> EMPTY 测试空数组问题
//3 A -1000000000 Q Q ->-1000000000 -1000000000 测试数据边界
//19:33-18:26=0:53用时