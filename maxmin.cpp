#include <iostream>
using namespace std;

void maxmin(int a[], int n, int &max, int &min)
{
    if(n==2)
    {
        max = a[0]>a[1]?a[0]:a[1];
        min = a[0]>a[1]?a[1]:a[0];
        return;
    }
    if(n==1)
    {
        max = min = a[0];
        return;
    }

    int *mm = (int *)malloc((n/2) * 4);
    int *nn = (int *)malloc((n-(n/2)) *4);

    int j=0, k=0;
    for(int i = 0; i < n; i++)
    {
        if(i < n/2) mm[j++]=a[i];
        else nn[k++]=a[i];
    }

    int max1, max2, min1, min2;
    maxmin(mm, n/2, max1, min1);
    maxmin(nn, n-n/2, max2, min2);

    max = max1>max2?max1:max2;
    min = min1<min2?min1:min2;
}


int main()
{
    int a[] = {2,-1,8,-8,9,6,1,-4,10};
    int max, min;
    maxmin(a, 9, max, min);
    cout<<max<<" "<<min<<endl;
    return 0;
}