#include <bits/stdc++.h>

using namespace std;

int main()
{
    int count;
    cin >> count;
    char s, s1;
    double num;
    map <double, char> line;
    while(cin >> s >> s1)
    {
        if(s == '=') break;
        cin >> num;
        line.insert({num, s});
    }
    
    
    
}