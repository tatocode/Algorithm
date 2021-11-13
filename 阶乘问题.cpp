#include <iostream>
using namespace std;


int getFactorial(int x){
    if(x == 0){
        return 1;
    }
    return x * getFactorial(x - 1);
}

int main(){
    int x;
    cin>>x;
    cout<<getFactorial(x);
    return 0;
}