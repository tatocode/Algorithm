#include <iostream>
using namespace std;

// 动态规划法
int getFibonacci(int x)
{
    if(x == 1 || x == 2) return 1;
    int temp, last=1, before=1;
    for(int i = 3; i <= x; i++)
    {
        temp = last + before;
        before = last;
        last = temp;
    }
    return temp;
}


int main()
{
    int x;
    cin>>x;
    cout<<getFibonacci(x);
    return 0;
}
