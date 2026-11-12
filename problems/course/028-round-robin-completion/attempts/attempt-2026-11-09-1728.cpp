#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct node{
    int proc,num;
};

int main(){
    int n;
    cin >> n;
    queue<node> process;
    queue<int> ans;
    if(n==0){
        cout << "EMPTY" << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        node a;
        cin >> a.proc;a.num=i+1;
        process.push(a);
    }
    while(!process.empty()){
        if(process.front().proc-1==0){
            ans.push(process.front().num);
            process.pop();
            continue;
        }else {
            process.front().proc--;
            process.push(process.front());
            process.pop();
        }
    }
    for(int i=0;i<n;i++){
        cout << ans.front() << " ";
        ans.pop();
    }cout << endl;
    


    return 0;
}

//1->empty 设计边界
//4 1 3 2 4->1 2 3 4 测试正常条件
//3 10 10 10 10->1 2 3 4测试全相等