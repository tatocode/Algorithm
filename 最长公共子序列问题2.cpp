#include <iostream>
using namespace std;

int a[] = {1, 6, 3, 2, 4, 8, 1, 5, 4, 9, 7};
int b[] = {5, 6, 4, 8, 9, 5, 2, 4, 0, 1};
int result[12][11] = {0};
int s[12][11] = {0};

// 动态规划法求最优解
int lcsLength(int m, int n)
{
    for(int i = 0; i <= m; i++) result[i][0] = 0;
    for(int i = 0; i <= n; i++) result[0][i] = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i-1] == b[j-1]) 
            {
                result[i][j] = result[i-1][j-1]+1;
                s[i][j] = 1;
            }
            else if(result[i-1][j] >= result[i][j-1])
            {
                result[i][j] = result[i-1][j];
                s[i][j] = 2;
            }
            else
            {
                result[i][j] = result[i][j-1];
                s[i][j] = 3;
            } 
        }
    }
    return result[m][n];
}

// 构建最长子序列
void lcs(int i, int j)
{
    if(i == 0 || j == 0) return;
    if(s[i][j] == 1)
    {
        lcs(i-1, j-1);
        cout<<a[i-1];
    }
    else if(s[i][j] == 2)
    {
        lcs(i-1, j);
    }
    else
    {
        lcs(i, j-1);
    }
}


int main()
{
    cout<<lcsLength(11, 10)<<endl;
    lcs(11, 10);
    return 0;
}