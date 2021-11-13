#include <iostream>
using namespace std;

// 数组 cs 从下标 a 到 b 中所有元素的全排列
void perm(char *cs, int a, int b){
    if (a == b) {
        cout << cs << endl;
    }
    else{
        for(int i = a; i <= b; i++){
            swap(cs[a], cs[i]);     // 保证始终对一段（块）序列进行全排列，而不是两端（块）
            perm(cs, a+1, b);
            swap(cs[a], cs[i]);     // 保证前一次递归调用和循环不会重复交换元素
        }
    }
}


int main(){
    char cs [] = {'a', 'b', 'c'};
    perm(cs, 0, sizeof(cs)-1);
    return 0;
}