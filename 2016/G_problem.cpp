#include <bits/stdc++.h>
using namespace std;

// 1. 建立 Map 緩存
unordered_map<long long, int> factorCache;

int countPrimeFactors(long long m) {
    if (m == 1) return 0;
    if (factorCache.count(m)) return factorCache[m]; // 查 Map

    long long temp = m;
    int sum = 0;
    for (long long i = 2; i * i <= temp; i++) {
        while (temp % i == 0) {
            sum++;
            temp /= i;
        }
    }
    if (temp > 1) sum++;
    return factorCache[m] = sum; // 存入 Map 並回傳
}

struct KeyInfo {
    long long val;
    int factorCount;
    int originalPos;
};

// 2. 定義排序規則
bool compareKeys(const KeyInfo& a, const KeyInfo& b) {
    if (a.factorCount != b.factorCount)
        return a.factorCount < b.factorCount;
    if (a.val != b.val)
        return a.val < b.val;
    return a.originalPos < b.originalPos; // 穩定排序：位置小的在前
}

int main() {
    int T;
    cin >> T;
    string dummy;
    getline(cin, dummy); // 吃掉 T 後方的換行符

    while (T--) {
        string line, letter;
        if (!getline(cin, line)) break;
        if (!getline(cin, letter)) break;

        vector<long long> allKeys;
        istringstream ss(line);
        long long num;
        while (ss >> num) allKeys.push_back(num);

        int m = allKeys.size();
        int L = letter.length();
        string result = letter; // 用來存放解密後的結果

        // 3. 分區塊處理 (每區塊長度最多為 m)
        for (int i = 0; i < L; i += m) {
            int k = min(m, L - i); // 當前子字串長度
            vector<KeyInfo> currentBlockKeys;

            // 規則：如果最後一個子字串長度 k < m，只重排前 k 個金鑰
            for (int j = 0; j < k; j++) {
                currentBlockKeys.push_back({allKeys[j], countPrimeFactors(allKeys[j]), j});
            }

            // 進行 PFS 排序
            sort(currentBlockKeys.begin(), currentBlockKeys.end(), compareKeys);

            // 4. 解密填充
            // 邏輯：密文區塊的第 j 個字元，對應到明文區塊的 originalPos 位置
            for (int j = 0; j < k; j++) {
                result[i + currentBlockKeys[j].originalPos] = letter[i + j];
            }
        }
        cout << result << endl;
    }
    return 0;
}