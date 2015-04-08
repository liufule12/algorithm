#include <iostream>
#include <string>
using namespace std;

int center_ext(string s)
// 中心扩展法.
{
    int max_sum = 1;
    for (int i = 0; i < s.length(); ++i){
        // 奇数情况
        int temp_sum = 1;
        for (int j = 1; j <= s.length() / 2; ++j){
            if (i - j >= 0 && i + j < s.length())
                if (s[i - j] == s[i + j]){
                    //cout << i << s[i] << " " << s[i - j] << " " << s[i + j] << endl;
                    temp_sum += 2;
                }
                else{
                    //cout << s[i - j] << " " << s[i + j] << endl;
                    break;
                }
        }
        if (temp_sum > max_sum)
            max_sum = temp_sum;
        temp_sum = 0;

        // 偶数情况
        for (int j = 1; j <= s.length() / 2; ++j){
            if (i - j + 1 >= 0 && i + j < s.length())
                if (s[i - j + 1] == s[i + j])
                    temp_sum += 2;
                else
                    break;
        }
        if (temp_sum > max_sum)
            max_sum = temp_sum;
    }
    return max_sum;
}


string pre_process(string s)
// 对字符串插入起始符^和结束符$，并将原字符串以#分割。
{
    if (s.length() == 0)
        return "^$";
    string new_s = "^";
    for (int i = 0; i < s.length(); ++i){
        new_s += "#";
        new_s += s[i];
    }
    /* This is C++ 11, cannot work in C++ 98. :(
    for (char c : s){
        new_s += "#";
        new_s += c;
    }*/
    new_s += "#$";

    return new_s;
}


int manacher(string s)
{
    s = pre_process(s);
    int n = s.length();
    int p[n], C = 0, R = 0;
    for (int i = 1; i < n - 1; ++i){
        int i_mirror = 2 * C - i;
        if (R > i)
            p[i] = min(R - i, p[i_mirror]);
        else
            p[i] = 0;

        while(s[i + 1 + p[i]] == s[i - 1 - p[i]])
            ++ p[i];

        if (i + p[i] > R){
            C = i;
            R = i + p[i];
        }
    }

    int max_sum = 0;
    for (int i = 1; i < n - 1; ++i){
        if (max_sum < p[i])
            max_sum = p[i];
    }

    return max_sum;
}


int main()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; ++n){
        string s;
        cin >> s;
        // int max_sum = center_ext(s);
        int max_sum = manacher(s);
        cout << max_sum <<endl;
    }
}
