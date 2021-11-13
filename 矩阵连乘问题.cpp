#include <iostream>
using namespace std;

int a[] = {30, 35, 15, 5, 10, 20, 25};

// 使用递归法求最优值
int m(int i, int j)
{
    if(i == j) return 0;
    int min = 99999999, temp;
    for(int k = i; k < j; k++)
    {
        temp = m(i, k) + m(k+1, j) + a[i-1]*a[k]*a[j];
        if(temp < min)  min = temp;
    }
    return min;
}

int main()
{
    cout<<m(1, 6);
    return 0;
}