#include <iostream>
using namespace std;

// 动态规划得到最优值
int knapsack(int *w, int *v, int size, int n, int m[][100])
{
    int jMax = min(w[n-1]-1, size);
    for(int j = 0; j <= jMax; j++) m[n][j] = 0;
    for(int j = w[n-1]; j<=size; j++) m[n][j] = v[n-1];
    for(int i = n-1; i > 1; i--)
    {
        jMax = min(w[i-1]-1, size);
        for(int j = 0; j<=jMax; j++) m[i][j] = m[i+1][j];
        for(int j = w[i-1]; j<=size;j++) m[i][j] = max(m[i+1][j], m[i+1][j-w[i-1]]+v[i-1]); 
    }
    m[1][size] = m[2][size];
    if(size>=w[1]) m[1][size] = max(m[1][size], m[2][size-w[0]] + v[0]);
    return m[1][size];
}

// 最优解


int main()
{
    int w[] = {20,40,15,60,8,12,4};
    int v[] = {200,360,80,500,20,60,10};
    int size = 100;
    int m[100][100] = {0};
    cout<<knapsack(w,v, size, 7, m);
    // cout<<endl<<max(3,7)<<endl;
    return 0;
}