#include<iostream>
#include<cmath>

bool is_prime(int n) {
    // 0、1不是素数,字节返回flase
    if(n < 2) return false;
    
    // 计算num的平方根，用于下一步判断
    int sqrtn = sqrt(n);

    // 判断num是否为素数
    for(int i = 2; i < sqrtn; i ++)
    {
        if( n %i ==0) return false;
    }
    return true;
}


bool is_prime(int n) {
    if(n < 2) return false;

    int sqrtn = sqrt(n);

    for(int i = 2; i < sqrtn ;++i)
    {
        if(n %i == 0) return false;
    }

    return true;
}