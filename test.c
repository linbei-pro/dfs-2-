#include <stdio.h>
#include <stdlib.h>

#define N 4

int arr[N][N] = { 0 }; // 用于记录方格是否被访问过
int cnt = 0;

void dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N || arr[x][y] != 0)
        return;
    
    arr[x][y] = 1; // 标记当前方格已被访问
    
    // 如果所有方格都已被访问，则增加方案数
    int all_visited = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) {
                all_visited = 0;
                break;
            }
        }
        if (!all_visited) break;
    }
    if (all_visited) {
        cnt++;
    }
    
    dfs(x + 1, y); // 向右
    dfs(x, y + 1); // 向上
    dfs(x - 1, y); // 向左
    dfs(x, y - 1); // 向下
    
    arr[x][y] = 0; // 回溯，恢复方格状态
}

int main()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            dfs(x, y);
        }
    }
    printf("%d", cnt);
    return 0;
}
