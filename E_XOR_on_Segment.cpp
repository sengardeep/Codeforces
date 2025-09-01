#include <bits/stdc++.h>
using namespace std;

#define lc (ind * 2)
#define rc ((ind * 2) + 1)

const int MAXN = 100 * 1000 + 2, L = 20;
int n, m, a[MAXN];
int seg[MAXN << 2][L], lazy[MAXN << 2];
void build(int b = 0, int e = n, int ind = 1){
    if(b + 1 == e){
        for(int i = 0; i < L; i ++){
            if((a[b] >> i) & 1)
                seg[ind][i] = 1;
        }
        return;
    }
    int mid = (b + e)/2;
    build(b, mid, lc);
    build(mid, e, rc);
    for(int i = 0; i < L; i ++){
        seg[ind][i] = seg[lc][i] + seg[rc][i];
    }
    return;
}
void shift(int b, int e, int ind){
    int mid = (b + e)/2;
    for(int i = 0; i < L; i ++){
        if((lazy[ind] >> i) & 1){
            seg[lc][i] = mid - b - seg[lc][i];
            seg[rc][i] = e - mid - seg[rc][i];
        }
    }
    lazy[lc] ^= lazy[ind];
    lazy[rc] ^= lazy[ind];
    lazy[ind] = 0;
    return;
}
void upd(int val, int l, int r, int b = 0, int e = n, int ind = 1){
    if(l >= e || r <= b) return;
    if(l <= b && e <= r){
        for(int i = 0; i < L; i ++){
            if((val >> i) & 1){
                seg[ind][i] = e - b - seg[ind][i];
            }
        }
        lazy[ind] ^= val;
        return;
    }
    int mid = (b + e)/2;
    shift(b, e, ind);
    upd(val, l, r, b, mid, lc);
    upd(val, l, r, mid, e, rc);
    for(int i = 0; i < L; i ++){
        seg[ind][i] = seg[lc][i] + seg[rc][i];
    }
}
long long get(int l, int r, int b = 0, int e = n, int ind = 1){
    if(l >= e || r <= b) return 0ll;
    long long ret = 0;
    if(l <= b && e <= r){
        for(int i = 0; i < L; i ++){
            ret += (1ll << i) * seg[ind][i];
        }
        return ret;
    }
    int mid = (b + e)/2;
    shift(b, e, ind);
    return get(l, r, b, mid, lc) + get(l, r, mid, e, rc);
}
int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    build();
    cin >> m;
    int t, l, r, x;
    while(m --){
        cin >> t >> l >> r;
        l --;
        if(t == 2){
            cin >> x;
            upd(x, l, r);
        }else{
            cout << get(l, r) << '\n';
        }
    }
    return 0;
}
