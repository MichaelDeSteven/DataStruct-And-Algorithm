#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 1e6;
int son[N][26], inx, n, cnt[N]; // cnt[i]统计以结点i为结尾的字符串数量

void insert(string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ inx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string op, str;
        cin >> op >> str;
        if (op == "I") insert(str);
        else cout << query(str) << endl;
    }
    
    return 0;
}
