#include <iostream>
using namespace std;
int a[] = {30, 35, 10, 20, 25};
int m[5][5] = {0};
int s[5][5] = {0};

// 动态规划法求最优解和最优值

// 计算最优值
void matrixChain()
{
    int n = sizeof(a)/4 - 1;
    // cout<<n<<endl;
    for(int i = 1; i <= n; i++) m[i][i] = 0;
    for(int r = 2; r <= n; r++)
    {
        for(int i = 1; i <= n-r+1; i++)
        {
            int j = i+r-1;
            m[i][j] = m[i][i] + m[i+1][j]+a[i-1]*a[i]*a[j];
            s[i][j] = i;
            for(int k = i+1; k < j; k++)
            {
                int t = m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
                if(t<m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

// 通过最优值给到的 s 产生最优解
void traceback(int i, int j)
{
    if(i == j) return;
    traceback(i, s[i][j]);
    traceback(s[i][j]+1, j);
    cout<<"(A["<<i<<":"<<s[i][j]<<"])";
    cout<<"(A["<<(s[i][j]+1)<<":"<<j<<"])"<<endl;
}





int main()
{
    matrixChain();
    for(int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 5; j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    for(int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 5; j++)
        {
            cout<<s[i][j]<<"\t";
        }
        cout<<endl;
    }

    traceback(1, 4);
    return 0;
}