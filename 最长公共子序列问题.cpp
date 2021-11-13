#include <iostream>
using namespace std;

int a[] = {1, 6, 3, 2, 4, 8, 1, 5, 4, 9, 7};
int b[] = {5, 6, 4, 8, 9, 5, 2, 4, 0, 1};

// 递归解法
int c(int i, int j)
{
    if(i == 0 || j == 0) return 0;
    if(a[i-1] == b[j-1]) return c(i-1, j-1)+1;
    else
    {
        int m = c(i, j-1);
        int n = c(i-1, j);
        return m>n?m:n;
    }
}


int main()
{

    cout<<c(11, 10);    // 6, 4, 8, 5, 4
    return 0;
}
