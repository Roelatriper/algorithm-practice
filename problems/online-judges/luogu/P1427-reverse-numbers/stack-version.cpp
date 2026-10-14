#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> numbers;
    int tmp;
    while(1){
        cin >> tmp;
        if(tmp!=0){
            numbers.push(tmp);
        }else break;
    }
    while(!numbers.empty()){
        cout << numbers.top() << " ";
        numbers.pop();
    }cout << endl;
    return 0;
}