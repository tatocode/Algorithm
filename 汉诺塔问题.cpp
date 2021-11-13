#include<iostream>
using namespace std;

// 把顶部 n 个盘子从 a 移到 b 借助 c
void move(int n, char a, char b, char c){
    if (n == 1){
        cout << a << "---->" << b <<endl;
    }else if(n>=2){
        move(n-1, a, c, b);
        move(1, a, b, c);
        move(n-1, c, b, a);
    }
}

int main(){
    int x;
    cin>>x;

    move(x, 'a', 'b', 'c');

    return 0;
}