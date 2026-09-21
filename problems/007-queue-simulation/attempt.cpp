#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> ass,output;
    int n=getchar();
    int tmp_o,tmp_n;
    for(int i=0;i<n-1;i++){
        tmp_o=getchar();
        switch(tmp_o){
            case 1:
                tmp_n=getchar();
                ass.push(tmp_n);
                break;
            case 2:
                if(!ass.empty())ass.pop();
                break;
            case 3:
                if(!ass.empty()){
                    output.push(ass.front());
                }
                break;
        }
    }
    for(int i=0;i<static_cast<int>(output.size());i++){
        cout << output.front() << " ";
        output.pop();
    }
    return 0;
}