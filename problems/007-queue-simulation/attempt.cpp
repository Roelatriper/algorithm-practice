#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> ass,output;
    int n;
    cin >> n;
    int tmp_o,tmp_n;
    for(int i=0;i<n;i++){
        cin >> tmp_o;
        switch(tmp_o){
            case 1:
                cin >> tmp_n;
                ass.push(tmp_n);
                break;
            case 2:
                if(!ass.empty())ass.pop();
                break;
            case 3:
                if(!ass.empty()){
                    output.push(ass.front());
                }else output.push(-1);
                break;
        }
    }
    int tmp=static_cast<int>(output.size());
    // if(tmp==0){cout << "-1" << endl;return 0;}
    for(int i=0;i<tmp;i++){
        cout << output.front() << "\n";
        output.pop();
    }
    return 0;
}