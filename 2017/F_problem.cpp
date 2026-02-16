#include<bits/stdc++.h>
using namespace std;

int main()
{
    int Case;
    cin >> Case;
    while(Case--)
    {
        double CP, AP, RP, FF;
        int count=0;
        cin >> CP >> AP >> RP >> FF;
        double temp=CP;
        //bool flag=true;
        while(CP>0)
        {
            count++;
            CP=CP-AP;
            if(CP<=0) break;
            CP=CP+RP;
            AP=AP-AP*(FF/100.0);
            if (AP <= RP && CP >= (CP + AP - RP)) break;
        }
        if(AP <= RP && CP >= (CP + AP - RP)) cout << "Fail to win the battle.\n";
        else cout << "Win in Round " << count << "."<< endl;
    }
}