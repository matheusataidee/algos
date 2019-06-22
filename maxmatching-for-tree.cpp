// Solution for https://www.spoj.com/problems/PT07X/
// Also can be used for vertex cover in a tree
// For more dense bipartite graph, use dinic maxflow

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

typedef long long ll;

vector<int> g[MAXN];
set<int> bip[MAXN];
int colour[MAXN];
int n;

void dfs(int p) {
    if (colour[p] == 0) {
        bip[0].insert(p);
    } else {
        bip[p].insert(n + 1);
    }
    for (int i = 0; i < g[p].size(); i++) {
        int to = g[p][i];
        if (colour[to] == -1) {
            colour[to] = 1 - colour[p];
            dfs(to);
        }
        if (colour[p] == 0) {
            bip[p].insert(to);
        }
    }
}

bool augmentingPath(int p) {
    if (bip[p].find(n+1) != bip[p].end()) {
        bip[p].erase(n+1);
        return true;
    }
    for (set<int>::iterator it = bip[p].begin(); it != bip[p].end(); it++) {
        int to = *it;
        if (augmentingPath(to)) {
            bip[p].erase(to);
            if (p != 0) bip[to].insert(p);
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    memset(colour, -1, sizeof(colour));
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    colour[1] = 1;
    dfs(1);

    int ans = 0;
    while (augmentingPath(0)) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
