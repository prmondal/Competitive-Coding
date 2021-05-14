int BLOCK_SIZE;

inline ll gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = 1LL << (2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
    int l;
    int r;
    int idx;
    int block;
    ll ord;

    Query() {}

    Query(int l, int r, int idx): l(l), r(r), idx(idx) {
        block = l / BLOCK_SIZE;
        ord = gilbertOrder(l, r, 21, 0);
    }

    bool operator<(const Query& o) const {
        return ord < o.ord;
    }
};


/// algorithm starts here
vector<Query> queries;
vector<int> answer(q);

for (int i = 0; i < q; i++) {
    int l,r;
    cin >> l >> r;
    l--;
    r--;
    queries.emplace_back(l,r,i);
}

sort(queries.begin(), queries.end());

int currL = 0;
int currR = -1;

// store ans

for (const auto& q: queries) {
    int qL = q.l;
    int qR = q.r;
    int qIdx = q.idx;

    while (currR < qR) {
        currR++;
        // add and update answer
    }

    while (currR > qR) {
        // remove and update answer
        currR--;
    } 

    while (currL < qL) {
        // remove and update answer
        currL++;
    }

    while (currL > qL) {
        currL--;
        // add and update answer
    }

    answer[qIdx] = ans;
}

for (int i = 0; i < q; i++) {
    cout << answer[i] << endl;
}
