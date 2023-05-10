bool isPalindrome(int x)
{
    // 小于等于零为非回文数 或者 最后一位为0
    if( x <= 0 || x%10 == 0)
    {
        return false;
    }
        

    int rev = 0;
    //将x翻转过半
    while(x > rev) {
        rev = rev*10 + x%10;
        x /= 10;
    }

    //将剩余的x与翻转值做比较
    if(x == rev || x == rev/10)
    {
        return true;
    }

    return false;
}