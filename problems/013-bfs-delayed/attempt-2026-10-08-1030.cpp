//tmp file.the code could be changed at any time.plz backup important code before it change.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
// #define ll long long
using namespace std;
typedef vector<vector<char> > mapp;
typedef vector<vector<bool> > visited;
int a,b,dots[2][2];
struct node{
    int x,y,dest;
};queue<node> pipe;


int bfs(const mapp &chr,visited &mapps){
    if(a==1 && b==1)return 0;
    node tmp;
    tmp.x=dots[0][0];tmp.y=dots[0][1];tmp.dest=0;
    pipe.push(tmp);
    mapps[tmp.x][tmp.y]=1;
    const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    while(!pipe.empty()){
        tmp=pipe.front();
        pipe.pop();
        for(int i=0;i<4;i++){
            if(tmp.x+dx[i]<0 || tmp.y+dy[i]<0 || tmp.x+dx[i]>=a || tmp.y+dy[i]>=b)continue;
            if(mapps[tmp.x+dx[i]][tmp.y+dy[i]]==1)continue;
            if(chr[tmp.x+dx[i]][tmp.y+dy[i]]!='#'){
                if(tmp.x+dx[i]==dots[1][0] && tmp.y+dy[i]==dots[1][1]){
                    tmp.dest++;
                    return tmp.dest;
                }else{
                    node ttmp;
                    ttmp.x=tmp.x+dx[i];
                    ttmp.y=tmp.y+dy[i];
                    ttmp.dest=tmp.dest+1;
                    mapps[ttmp.x][ttmp.y]=1;
                    pipe.push(ttmp);
                }
            }else continue;
        }
    }
    return -1;
}

int main(){
    cin >> a >> b;
    mapp chr(a,vector<char>(b));
    visited mapps(a,vector<bool>(b));
    int tmp=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> chr[i][j];
            if(chr[i][j]=='S' || chr[i][j]=='D'){dots[tmp][0]=i;dots[tmp++][1]=j;}
            // cout << tmp << endl;
            mapps[i][j]=false;
        }
    }
    cout << bfs(chr,mapps) << endl;


    return 0;
}