int BLOCK_SIZE;

struct Query {
    int l;
    int r;
    int idx;
    int block;

    Query() {}
    
    Query(int l, int r, int idx): l(l), r(r), idx(idx) {
        block = l / BLOCK_SIZE;
    }

    bool operator<(const Query& o) const {
        if (block != o.block) return block < o.block;
        return (block & 1) ? r < o.r : r > o.r;
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
