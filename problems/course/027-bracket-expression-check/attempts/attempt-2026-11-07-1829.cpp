#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    bool istrue=1;
    cin >> n;
    stack<char> array;
    for(int i=0;i<n;i++){
        char tmp;
        cin >> tmp;
        if(tmp=='(' || tmp=='[' || tmp=='{'){
            array.push(tmp);
        }
        else if(array.empty())istrue=0;
        if(istrue==1){
            if((tmp==')' && array.top()=='(') 
            || (array.top()=='{' && tmp=='}')
            || (tmp==']' && array.top()=='[')){
                array.pop();
            }else {
                istrue=0;
            }
        }
    }
    if(istrue==1)cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}