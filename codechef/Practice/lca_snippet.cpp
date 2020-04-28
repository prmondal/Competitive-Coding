int d[mxN], anc[mxN][17];

void dfs(int u=0, int p=-1) {
	anc[u][0]=p;
	for(int i=1; i<17; ++i)
		anc[u][i]=~anc[u][i-1]?anc[anc[u][i-1]][i-1]:-1;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		d[v]=d[u]+1;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if(d[u]<d[v])
		swap(u, v);
	for(int i=16; ~i; --i)
		if(d[u]-(1<<i)>=d[v])
			u=anc[u][i];
	if(u==v)
		return u;
	for(int i=16; ~i; --i) {
		if(anc[u][i]^anc[v][i]) {
			u=anc[u][i];
			v=anc[v][i];
		}
	}
	return anc[u][0];
}

