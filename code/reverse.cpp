/*
 * 字符串反转。
 */

#include <iostream>
using namespace std;

char *myReverse(char *s)
{
    int i = 0, j = 0;
    while(s[i])
        ++i;

    // 注意如果在for重新声明并赋值i，j，那么这个i，j并不是for循环外的i，j。
    // for (int j = 0, i = i - 1; j < i; --i, ++j){
    for (j = 0, i = i - 1; j < i; --i, ++j){
        char tempC = s[j];
        s[j] = s[i];
        s[i] = tempC;
    }

    return s;
}


int main()
{
    char s[12] = "12345678910";

    cout << myReverse(s) << endl;

    return 0;
}
