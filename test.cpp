#include <iostream>
using namespace std;


int func2(int n, int *a)
{
    int s = 0, b = 0;
    for(int i = 1; i<=n; i++)
    {
        if(b>0) b+=a[i];
        else b=a[i];
        if(b>s) s =b;
    }
    return s;
}

int main()
{
    int a[] = {0,-2,11,-4,13,-5,-2};
    cout<<func2(7, a)<<endl;

    return 0;
}