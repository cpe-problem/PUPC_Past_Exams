// Kadane's algorithm
#include <bits/stdc++.h>
using namespace std;

int max_Kadane(int sum, int *x, int num)
{
    int initual=x[0], maxNum=x[0];
    for(int i=1;i<num;i++)
    {
        initual= max(x[i], initual+x[i]);
        maxNum = max(maxNum, initual);
    }
    return maxNum;
}

int min_Kadane(int sum, int *x, int num)
{
    int initual=x[0], minNum=x[0];
    for(int i=1;i<num;i++)
    {
        initual= min(x[i], initual+x[i]);
        minNum = min(minNum, initual);
    }
    return minNum;
}

int main()
{
    int Case;
    cin >> Case;
    while(Case--)
    {
        int num, sum=0;
        cin >> num;
        int x[num];
        for(int i=0;i<num;i++) 
        {
            cin >> x[i];
            sum+=x[i];
        }
        int n = sizeof(x) / sizeof(x[0]);
        int total=accumulate(x, x + n, 0);
        cout << max(max_Kadane(sum, x, num), total-min_Kadane(sum, x, num));
    }
}