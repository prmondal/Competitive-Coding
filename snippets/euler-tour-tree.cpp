vector<int> entr, ext;
int timer = 1;

void dfs(int u, int p) {
    entr[u] = timer++;
    for (auto& e: adj[u]) {
        if (e != p) {
            dfs(e, u);
        }
    }
    ext[u] = timer++;
}