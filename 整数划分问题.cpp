#include <iostream>
using namespace std;

// 获取数字 a 中所有加数小于等于 b 的式子的数量
int getAllAdd(int a, int b){
    if((a == 1) || (b == 1)){
        return 1;
    }else if(a < b){
        return getAllAdd(a, a);
    }else if(a == b){
        return 1 + getAllAdd(a, b - 1);
    }else if((a > b) && (b > 1)){
        return getAllAdd(a, b - 1) + getAllAdd(a-b, b);
    }else{
        return 0;
    }
}


int main(){
    int x;
    cin>>x;
    cout<<getAllAdd(x, x);
    return 0;
}