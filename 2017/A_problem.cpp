#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    string s;
    while(cin >> s)
    {
        if(s=="0") break;
        size_t pos = s.find('.');
        if(pos==string::npos) 
        {
            cout << s << "/1\n";
            continue;
        }
        long long int num=0;
        int count=0, i=0, temp=0, a=0;
        bool flag=false;
        while(i<s.length()-1)
        {
            if(s[i]=='.') 
            {
                flag=true;
                temp=i+1;
            }
            if(!flag)
            {
                a=a*10+(s[i]-'0');
                i++;
            }
            if(flag) 
            {
                i++;
                num=num*10+(s[i]-'0');
            }
        }
        num=a*pow(10, (s.length()-temp))+num;
        long long int n=pow(10, (s.length()-temp));
        count=gcd(num, n);
        cout << num/count << "/" <<(long long)pow(10, (s.length()-temp))/count << endl;
    }
}