#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> array(n);
        for(int i=0;i<n;i++) cin >> array[i];
        int max_num=array[0], temp=array[0], flag=1;
        int max_start = 0, max_end = 0, start = 0, max_len = 1;
        bool is_negative = (array[0] >= 0);
        for(int i=1;i<n;i++)
        {
            if(temp+array[i]>=array[i])
                temp+=array[i];
            else
            {
                temp=array[i];
                start=i;
            }
            int temp_len=i-start+1;//目前連續子序列的長度。
            //1.如果當前子陣列的和更大，就更新。 2.如果和一樣大，但目前子陣列更短，更新。 
            //3.如果和、長度都一樣，但這段子陣列更早出現（起點位置更小），更新。
            if (temp > max_num ||
                (temp == max_num && temp_len < max_len) ||
                (temp == max_num && temp_len == max_len && start < max_start))
            {
                max_num = temp;
                max_start = start;
                max_end = i;
                max_len = temp_len;
            }
            if(array[i]>=0) is_negative=true;
            
        }
        if(!is_negative) 
        {
            auto pos=find(array.begin(), array.end(), max_num);
            cout << max_num << " " << (pos-array.begin()+1) << " " << (pos-array.begin()+1) << endl;
        }
        else 
        {
            cout << max_num << " " << (max_start + 1) << " " << (max_end + 1) << endl;
        }
    }
}