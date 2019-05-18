// DSU (Disjoint-Set-Union, or Union-Find) 
int r[MAXN]; 
int p[MAXN]; 
// creates a new set consist of only the element v 
void makeSet (int v) { 
    p[v] = v; r[v] = 0; 
    
} 
// returns representative of the set in which v lies 
int findSet (int v) {
    return v == p[v] ? v : p[v] = findSet(p[v]);
}

// unite the sets in which a and b lie
void uniteSets (int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (r[a] < r[b]) {
            swap(a, b);
        }
        p[b] = a; 
        if (r[a] == r[b]) {
            r[a]++;
        } 
    }
}