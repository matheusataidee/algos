#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int maxFlow(vector<vector<int>>& g, int s, int t) {
	int flow = 0;
	
	int n = g.size();
	
	vector<int> deg(n, 0);
	vector<int> q(n, 0);
	vector<int> prv;
	vector<vector<int>> adj(n);
	
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if(g[u][v] || g[v][u]) {
				adj[u].push_back(v);
				deg[u]++;
			}
        }
    }
    while(true) {
		prv = vector<int>(n, -1);
        int qf = 0, qb = 0;
        prv[q[qb++] = s] = -2;
        while( qb > qf && prv[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prv[v = adj[u][i]] == -1 && g[u][v] )
                    prv[q[qb++] = v] = u;
        if( prv[t] == -1 ) break;
        for (int z = 0; z < n; z++) if( g[z][t] && prv[z] != -1 ) {
            int bot = g[z][t];
            for(int v = z, u = prv[v]; u >= 0; v = u, u = prv[v])
                bot = min(bot, g[u][v]);
            if(!bot) continue;
            g[z][t] -= bot;
            g[t][z] += bot;
            for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] ) {
                g[u][v] -= bot;
                g[v][u] += bot;
            }
            flow += bot;
        }
    }
    return flow;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		vector<vector<int> > g(2 * n + 2, vector<int>(2 * n + 2, 0));
		int source = 0;
		int sink = 2 * n + 1;
		for (int i = 1; i <= n; i++) {
			g[source][i] = 1;
			g[n + i][sink] = 1;
			int x;
			cin >> x;
			while (x) {
				if (x <= n) g[i][n + x] = 1;
				x /= 2;
			}
		}
		
		if (maxFlow(g, 0, 2 * n + 1) == n) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}
