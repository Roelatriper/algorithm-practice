#include <iostream>
using namespace std;
bool a[10000][10000];
int x=0,y=0;
int js(int nx,int ny,int step){
    step++;
    js(nx+1,ny,step);
    js(nx-1,ny,step);
    js(nx,ny+1,step);
    js(nx,ny-1,step);
    if(nx-1 <= 0 || ny-1 <=0)return 0;
    if(nx == x && ny == y)return step;
}
int main(){
    cin >> x >> y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin >> a[i][j];
        }
    }
    cout << js(0,0,1) << endl;    
    getchar();
    return 0;
}