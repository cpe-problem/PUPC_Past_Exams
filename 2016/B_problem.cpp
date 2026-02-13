#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    while(num--)
    {
        string a, b;
        cin >> a >> b;
        int cw[10]={0,1,2,3,4,5,6,7,8,9}, ccw[10]={0,9,8,7,6,5,4,3,2,1}, sum=0;
        for(int i=0;i<b.length();i++)
        {
            if((a[i]-b[i])<0 || abs(a[i]-b[i])>5)
            {
                if(abs(a[i]-b[i])<5) sum+=cw[abs(a[i]-b[i])]; 
                else sum+=ccw[abs(a[i]-b[i])];
            }
            else if((a[i]-b[i])<=5) sum+=cw[a[i]-b[i]];
        }
        cout << sum << endl;
    }
}