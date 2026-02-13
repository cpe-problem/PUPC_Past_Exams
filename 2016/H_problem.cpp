#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// 定義邊的結構
struct Edge {
    int to;
    int weight;
};

int main() {
    int Case;
    if (!(cin >> Case)) return 0;
    while(Case--) {
        int point, building, road;
        cin >> point >> building >> road;

        // 使用鄰接表儲存圖，這樣可以正確處理重複但長度相同的邊
        vector<vector<Edge>> adj(point);
        for(int i = 0; i < road; i++) {
            int p1, p2, e;
            cin >> p1 >> p2 >> e;
            adj[p1].push_back({p2, e});
        }

        // Dijkstra 必要的陣列
        vector<int> dist(point, INF);
        vector<long long> paths(point, 0); // 用來記錄到達每個點的最短路徑數量

        int start_node = 0;
        dist[start_node] = 0;
        paths[start_node] = 1; 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start_node});

        while(!pq.empty()) 
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;
            for (auto& edge : adj[u]) {
                int next_v = edge.to;
                int weight = edge.weight;

                // 情況 1：發現更短的路徑
                if (dist[u] + weight < dist[next_v]) {
                    dist[next_v] = dist[u] + weight;
                    paths[next_v] = paths[u]; // 直接繼承前一個點的路徑數量
                    pq.push({dist[next_v], next_v});
                }
                // 情況 2：發現另一條同樣短的路徑
                else if (dist[u] + weight == dist[next_v]) paths[next_v] += paths[u]; 
                
            }
        }
        if (dist[building] == INF || paths[building] <= 1) cout << "no" << endl;
        else cout << "yes" << endl;
        
        if (dist[building] == INF) cout << "x" << endl;
        else cout << dist[building] << endl;
    }
}