#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int temp=num;
    int x[num+1];
    x[0]=0;
    for(int i=1;i<=num;i++) cin >> x[i];
    while(temp--)
    {
        int a, b;
        cin >> a >> b;
        auto it = min_element(x+a, x+b+1);
        cout << *it << endl;
    }
}