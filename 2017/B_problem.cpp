#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    int T;
    cin >> T;
    while(T--){
        ull i, j;
        cin >> i >> j;
        // r 層編號（即此點所在的方框層數）
        ull r = max(i, j);
        // (r-1)^2
        ull base = (r - 1) * (r - 1);

        ull pos;
        if (r % 2 == 1) // 奇數層：先按第 r 列由左到右，再按第 r 欄由下往上
        {
            if (i == r)  // 在第 r 列上，偏移就是列內的 j
                pos = j;
            else // 在第 r 欄上 (i < r)，偏移要跳過整列 r，再往上數 (r-i) 個
                pos = r + (r - i);

        } 
        else // 偶數層：先按第 r 欄由上到下，再按第 r 列由右往左 
        {
            if (j == r) // 在第 r 欄上，偏移就是欄內的 i
                pos = i;
            else // 在第 r 列上 (j < r)，偏移要跳過整欄 r，再往左數 (r-j) 個
                pos = r + (r - j);
        }
        cout << base + pos << "\n"; // 最終答案 = 之前走過的點數 + 本層內偏移
    }
}
