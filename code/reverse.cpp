/*
 * �ַ�����ת��
 */

#include <iostream>
using namespace std;

char *myReverse(char *s)
{
    int i = 0, j = 0;
    while(s[i])
        ++i;

    // ע�������for������������ֵi��j����ô���i��j������forѭ�����i��j��
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
