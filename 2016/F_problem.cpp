#include <bits/stdc++.h>
using namespace std;

int main() {
    int count; 
    cin >> count;
    while(count--) 
    {
        int l, m; 
        cin >> l >> m;
        vector<int> x(l);
        for(int i=0; i<l; i++) cin >> x[i];

        int sum = 0;
        for(int i=0; i < m-1; i++) if((x[i]>0 && x[i+1]<0) || (x[i]<0 && x[i+1]>0)) sum++;
        double max_num = (double)sum / (m-1);
        int p_temp = 1;

        //滑動
        for(int i = 1; i <= l - m; i++) 
        {
            if((x[i-1]>0 && x[i]<0) || (x[i-1]<0 && x[i]>0)) sum--;
            int last = i + m - 2;//移出最後一個
            if((x[last]>0 && x[last+1]<0) || (x[last]<0 && x[last+1]>0)) sum++;

            double result = (double)sum / (m-1);
            if(result > max_num) {
                max_num = result;
                p_temp = i + 1;
            }
        }
        cout << p_temp << endl;
    }
}