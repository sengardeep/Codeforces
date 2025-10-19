#include <bits/stdc++.h>
using namespace std;

static inline bool can_reach_all(const vector<long long>& A, long long h){
    int n = (int)A.size();
    if(n==0) return true;
    vector<char> vis(n+1, 0); // 0 = ground, 1..n platforms
    deque<int> q;
    // Start from ground: enqueue all platforms reachable from ground
    for(int i=1;i<=n;i++){
        if(A[i-1] <= h){
            vis[i] = 1;
            q.push_back(i);
        }
    }
    int reached = (int)q.size();
    while(!q.empty()){
        int i = q.front(); q.pop_front();
        // i-1 neighbor
        if(i-1>=1 && !vis[i-1]){
            if(llabs(A[i-1] - A[i-2]) <= h){
                vis[i-1] = 1;
                q.push_back(i-1);
                reached++;
            }
        }
        // i+1 neighbor
        if(i+1<=n && !vis[i+1]){
            if(llabs(A[i] - A[i-1]) <= h){
                vis[i+1] = 1;
                q.push_back(i+1);
                reached++;
            }
        }
    }
    return reached == n;
}

long long solve_binary(const vector<long long>& A){
    if(A.empty()) return 0;
    long long maxA = 0, maxDiff = 0;
    for(long long x: A) maxA = max(maxA, x);
    for(size_t i=1;i<A.size();i++) maxDiff = max(maxDiff, llabs(A[i]-A[i-1]));
    long long lo = 0, hi = max(maxA, maxDiff);
    while(lo < hi){
        long long mid = (lo + hi) >> 1;
        if(can_reach_all(A, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    vector<long long> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    cout << solve_binary(A) << "\n";
    return 0;
}