#include <iostream>
using namespace std;

// 分治法
int getFibonacci(int x){
    if(x == 1 || x == 2){
        return 1;
    }
    return getFibonacci(x-1) + getFibonacci(x-2);
}


int main(){
    int x;
    cin>>x;
    cout<<getFibonacci(x);
    return 0;
}