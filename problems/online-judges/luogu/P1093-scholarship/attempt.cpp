#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct student{
    int a,b,c;
    int sum,num;
    bool summing(){
        sum=a+b+c;
        return 1;
    }
};
bool istrue1(const student& a,const student& b){
    if(a.sum == b.sum){if(a.a == b.a){return a.num < b.num;}else return a.a > b.a;}else return a.sum > b.sum;
}
int main(){
    int n;
    cin >> n;
    vector<student> pupil(n);
    for(int i=0;i<n;i++){
        cin >> pupil[i].a >> pupil[i].b >> pupil[i].c;
        pupil[i].num=i;
        pupil[i].summing();
    }
    sort(pupil.begin(),pupil.end(),istrue1);
    //cout << endl << "br" << endl;
    for(int i=0;i<5;i++){
        cout << pupil[i].num+1 << " " << pupil[i].sum << endl;
    }
    return 0;
}

// if(pupil[i].sum==pupil[i+1].sum){
//             if(pupil[i].a==pupil[i+1].a){
//                 if(pupil[i].b==pupil[i+1].b){
//                     if(pupil[i].c==pupil[i+1].c){
//                         cout << pupil[i].num+1 << " " << pupil[i].sum << endl;i+=2;fin++;
//                     }else {cout << pupil[i+!(pupil[i].c > pupil[i].c)].num+1 << " " << pupil[i+!(pupil[i].c > pupil[i].c)].sum << endl;i+=2;fin++;}
//                 }else {cout << pupil[i+!(pupil[i].b > pupil[i].b)].num+1 << " " << pupil[i+!(pupil[i].b > pupil[i].b)].sum << endl;i+=2;fin++;}
//             }else {cout << pupil[i+!(pupil[i].a > pupil[i].a)].num+1 << " " << pupil[i+!(pupil[i].a > pupil[i].a)].sum << endl;i+=2;fin++;}
//         }else {cout << pupil[i].num+1 << " " << pupil[i].sum << endl;}