#include <iostream>
#include <stack>

using namespace std;

void isOK(string s);
string ss;

int main()
{
    int n = 0;
    cin >> n;

    for(int i = 1; i < n; i++)
    {
        string s;
        cin >> s;
        isOK(s);
        ss.append("\n");
    }

    string s;
    cin >> s;
    isOK(s);

    cout << ss;

    return 0;
}

void isOK(string s)
{
    stack<int> left;
    static const char leftChar[4]  = {'<', '(', '[', '{'};
    static const char rightChar[4] = {'>', ')', ']', '}'};
    bool flag = false;

    int weight = -1;

    for(int i = 0; i < s.size(); i++)
    {
        bool continueFlag = false;

        for(int n = 0; n < 4; n++)
        {
            if(s[i] == leftChar[n]){
                left.push(n);
                weight = n;
                continueFlag = true;
            }
        }
        if(continueFlag) continue;

        for(int n = 0; n < 4; n++)
        {
            if(s[i] == rightChar[n]){
                if(left.empty() || n != left.top() || n > weight){
                    ss.append("NO");
                    flag = true;
                }
                else    left.pop();
            }
        }
        if(flag) break;
    }

    if(left.empty() && !flag)   ss.append("YES");
}
