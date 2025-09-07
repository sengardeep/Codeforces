
struct SegTree2D {
    int n, m;
    vector<vector<int>> tree;

    SegTree2D(int n, int m) : n(n), m(m) {
        tree.assign(4*n, vector<int>(4*m, 0));
    }

    // Build column tree for one row segment
    void build_y(int node_x, int lx, int rx, int node_y, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx) tree[node_x][node_y] = A[lx][ly];
            else tree[node_x][node_y] = tree[node_x*2][node_y] + tree[node_x*2+1][node_y];
        } else {
            int my = (ly + ry) / 2;
            build_y(node_x, lx, rx, node_y*2, ly, my);
            build_y(node_x, lx, rx, node_y*2+1, my+1, ry);
            tree[node_x][node_y] = tree[node_x][node_y*2] + tree[node_x][node_y*2+1];
        }
    }

    // Build row tree
    void build_x(int node_x, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(node_x*2, lx, mx);
            build_x(node_x*2+1, mx+1, rx);
        }
        build_y(node_x, lx, rx, 1, 0, m-1);
    }

    // Query column tree
    int query_y(int node_x, int node_y, int ly, int ry, int qly, int qry) {
        if (qly > ry || qry < ly) return 0;
        if (qly <= ly && ry <= qry) return tree[node_x][node_y];
        int my = (ly + ry) / 2;
        return query_y(node_x, node_y*2, ly, my, qly, qry)
             + query_y(node_x, node_y*2+1, my+1, ry, qly, qry);
    }

    // Query row tree
    int query_x(int node_x, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if (qlx > rx || qrx < lx) return 0;
        if (qlx <= lx && rx <= qrx) return query_y(node_x, 1, 0, m-1, qly, qry);
        int mx = (lx + rx) / 2;
        return query_x(node_x*2, lx, mx, qlx, qrx, qly, qry)
             + query_x(node_x*2+1, mx+1, rx, qlx, qrx, qly, qry);
    }

    // Update column tree
    void update_y(int node_x, int lx, int rx, int node_y, int ly, int ry, int x, int y, int new_val) {
        if (ly == ry) {
            if (lx == rx) tree[node_x][node_y] = new_val;
            else tree[node_x][node_y] = tree[node_x*2][node_y] + tree[node_x*2+1][node_y];
        } else {
            int my = (ly + ry) / 2;
            if (y <= my) update_y(node_x, lx, rx, node_y*2, ly, my, x, y, new_val);
            else update_y(node_x, lx, rx, node_y*2+1, my+1, ry, x, y, new_val);
            tree[node_x][node_y] = tree[node_x][node_y*2] + tree[node_x][node_y*2+1];
        }
    }

    // Update row tree
    void update_x(int node_x, int lx, int rx, int x, int y, int new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) update_x(node_x*2, lx, mx, x, y, new_val);
            else update_x(node_x*2+1, mx+1, rx, x, y, new_val);
        }
        update_y(node_x, lx, rx, 1, 0, m-1, x, y, new_val);
    }
};