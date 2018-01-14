#include <iostream>
#include <string>

using namespace std;

bool isNum   (const char c);
bool isLetter(const char c);
bool isOK    (const char c);

int main()
{
    string s;
    cin >> s;

    if( isNum(s[0]) )
    {
        cout << "no";
        return 0;
    }

    for(int i = 1; i < s.length(); i++)
    {
        if( !isOK(s[i]) )
        {
            cout << "no";
            return 0;
        }
    }

    cout << "yes";
    return 0;
}

bool isNum(const char c)
{
    return ('0' <= c && c <= '9');
}

bool isLetter(const char c)
{
    return (
             ('a' <= c && c <= 'z') ||
             ('A' <= c && c <= 'Z') ||
             (c =='_') 
            );
}

bool isOK(const char c)
{
    return isNum(c) || isLetter(c);
}