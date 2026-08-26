// 第1题 DFS 枚举子集（递归回溯）
// 给 N 个互不相同的数，输出它的所有子集和（每个元素的"选/不选"组合）
// 样例 [1,2,3] 输出：0 3 2 5 1 4 3 6（8 个子集和）
// 未做出来——本代码为课后整理思路版（DFS 回溯：每个元素二选一，递归到底输出 sum）
#include <stdio.h>
int arr[100], n;

void dfs(int idx, int sum){
    if(idx == n){           // 走到底，输出当前子集和
        printf("%d ", sum);
        return;
    }
    dfs(idx + 1, sum + arr[idx]);  // 选它
    dfs(idx + 1, sum);             // 不选它
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    dfs(0, 0);
    printf("\n");
    return 0;
}
