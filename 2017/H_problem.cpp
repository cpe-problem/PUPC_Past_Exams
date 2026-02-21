#include <bits/stdc++.h>

using namespace std;

// 使用 __int128 處理超過 long long 的組合數
typedef __int128_t int128;

// 由於 __int128 無法直接用 cin/cout，寫個簡單的轉換（如果需要輸出調試）
int128 nCr[76][76];

void precompute() //combination
{ 
    for (int i = 0; i <= 75; i++) 
    {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; j++) 
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    }
}

// 擴展歐幾里得演算法求 q
int128 extended_gcd(int128 a, int128 b, int128 &x, int128 &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int128 x1, y1;
    int128 gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// 編號轉組合 (1-based index)
vector<int> rankToCombination(int128 target_rank, int n, int m) {
    vector<int> res;
    int current_num = 1;
    for (int k = n; k >= 1; k--) {
        while (true) {
            int128 combinations_count = nCr[m - current_num][k - 1];
            if (target_rank <= combinations_count) {
                res.push_back(current_num);
                current_num++;
                break;
            } else {
                target_rank -= combinations_count;
                current_num++;
            }
        }
    }
    return res;
}

void solve() {
    long long n_in, m_in, p_in, w_in;
    if (!(cin >> n_in >> m_in >> p_in >> w_in)) return;

    int128 n = n_in, m = m_in, p = p_in, w = w_in;
    int128 N = nCr[m_in][n_in];

    // 1. 求 q
    int128 q, junk;
    extended_gcd(p, N, q, junk);
    q = (q % N + N) % N;

    // 2. 找出剩下的 w 個編號
    // 剩下的 k 為 N-w, N-w+1, ..., N-1
    vector<vector<int>> all_tickets;
    for (int128 k = N - w; k < N; k++) {
        int128 target_rank = (q * k % N) + 1;
        all_tickets.push_back(rankToCombination(target_rank, n_in, m_in));
    }

    // 3. 按字典序排序所有組合
    sort(all_tickets.begin(), all_tickets.end());

    // 4. 格式化輸出
    cout << "Tickets:" << endl;
    for (const auto& ticket : all_tickets) {
        for (int i = 0; i < ticket.size(); i++) {
            cout << setfill('0') << setw(2) << ticket[i] << (i == ticket.size() - 1 ? "" : "-");
        }
        cout << endl;
    }
}

int main() {
    precompute();
    int test_cases;
    cin >> test_cases;
    while (test_cases--) solve();
}