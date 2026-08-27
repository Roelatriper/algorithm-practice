//Failed because dk how to eof.

#include <iostream>
#include <queue>
using namespace std;
struct node{
    int data;
    node* child[2];
};
int dfs(node* root){
    if(root->child[0]==nullptr || root->child[1]==nullptr)return 0;
    else return 1+max(dfs(root->child[0]),dfs(root->child[1]));
}



int main(){
    queue<node> a;
    queue<int> b;
    while(1){
        b.push(getchar());
        if(b.back() == NULL)break;
    }
    node tmp;
    for(int i=1;i<=b.size();i++){
        tmp.data=b.front();
        
    }
    
    return 0;
}