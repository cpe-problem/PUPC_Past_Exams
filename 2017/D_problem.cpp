// Floyd-Warshall algorithm
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int x[305][305]; // 建議宣告在外面

int main() {
    int s, c, q, caseNum = 1;
    while (cin >> s >> c >> q && (s || c || q)) {
        // --- 1. 初始化 (針對站點 s) ---
        for (int i = 1; i <= s; i++) {
            for (int j = 1; j <= s; j++) {
                x[i][j] = (i == j) ? 0 : INF;
            }
        }

        // --- 2. 讀取邊 (針對連線數 c) ---
        for (int i = 0; i < c; i++) {
            int u, v, d; // 不要用 c 當變數名！
            cin >> u >> v >> d;
            if (d < x[u][v]) x[u][v] = x[v][u] = d;
        }

        // --- 3. Floyd-Warshall ---
        for (int k = 1; k <= s; k++) {
            for (int i = 1; i <= s; i++) {
                for (int j = 1; j <= s; j++) {
                    if (x[i][k] != INF && x[k][j] != INF) {
                        x[i][j] = min(x[i][j], max(x[i][k], x[k][j]));
                    }
                }
            }
        }

        // --- 4. 輸出 ---
        if (caseNum > 1) cout << endl;
        cout << "Case #" << caseNum++ << endl;
        for (int i = 0; i < q; i++) {
            int a1, a2;
            cin >> a1 >> a2;
            if (x[a1][a2] == INF) cout << "no path" << endl;
            else cout << x[a1][a2] << endl;
        }
    }
    return 0;
}