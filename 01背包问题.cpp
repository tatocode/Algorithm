#include <iostream>
using namespace std;

// 递归法计算最优值
int maxValue(int *w, int *v, int size, int n)
{
    if(n == 1){
        if(w[n-1] <= size) return v[n-1];
        else return 0;
    }
    if(w[n-1] > size) return maxValue(w, v, size, n-1);
    else
    {
        int x = maxValue(w, v, size-w[n-1], n-1) + v[n-1];
        int y = maxValue(w, v, size, n-1);
        return x>y?x:y;
    }
}

int main()
{
    int w[] = {20,40,15,60,8,12,4};
    int v[] = {200,360,80,500,20,60,10};
    int size = 100;
    cout<<maxValue(w, v, size, 7);

    return 0;
}