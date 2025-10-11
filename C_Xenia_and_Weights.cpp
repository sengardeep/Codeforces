#include <bits/stdc++.h>
using namespace std;

/*
Problem restated succinctly:
We must build a sequence of m weights (values 1..10, only allowed if present in input)
placed alternately on left/right pans:
 - Step 1: left, step 2: right, step 3: left, ...
Rules:
 1. No two consecutive chosen weights have the same numeric value.
 2. Each time we place a weight, the pan we place it on must become strictly heavier
    than the other pan after the placement.

Key observation to reduce state:
Let diff = (current difference) = (heavier pan total) - (lighter pan total) after the last placement.
At the next step we are forced to put a weight onto the currently lighter pan.
For that lighter pan to become heavier, the weight we put (w) must satisfy: w > diff.
After placing w, the new difference becomes: new_diff = w - diff.
We also must remember the last chosen weight to forbid repeating it.
*/

string s;                // availability string of length 10 ('1' means weight (index+1) is available)
int m;                   // target number of placements
vector<int> avail;       // list of available weight values

// vis[step][diff][last]:
//   Memoization to avoid revisiting states.
//   step: 1..m (next position to fill). We allow step = m+1 as success terminal.
//   diff: 0..10 (difference never exceeds 10 given constraints explained above).
bool vis[1005][11][11];

// Parent recovery arrays to reconstruct one valid sequence once dfs returns true.
int parW[1005][11][11];    // weight chosen at this state
int parDiff[1005][11][11]; // diff to move to next state
int parLast[1005][11][11]; // last weight for next state (same as chosen weight here)

/*
DFS state meaning:
 step: next placement index (1-based). If step > m, we have filled all positions.
 diff: current positive difference after previous placement.
       (Heavier pan total - lighter pan total; heavier pan is the one we just placed on last step.)
 last: last weight value used (to prevent consecutive equal weights).
*/
bool dfs(int step, int diff, int last){
    // Base case: placed m weights successfully
    if(step > m) return true;

    // Already processed this state -> no solution from here
    if(vis[step][diff][last]) return false;
    vis[step][diff][last] = true;

    // Try all available weights
    for(int w : avail){
        if(w == last) continue;   // rule: no two consecutive identical weights
        // We are forced to place on lighter pan; need w > diff to overturn and become heavier
        if(w > diff){
            int ndiff = w - diff; // new difference after placement (now this pan is heavier)
            if(dfs(step + 1, ndiff, w)){
                // Record choice for reconstruction
                parW[step][diff][last] = w;
                parDiff[step][diff][last] = ndiff;
                parLast[step][diff][last] = w;
                return true;
            }
        }
    }
    return false; // no usable weight at this state
}

void solve(){
    cin >> s;
    cin >> m;

    // Build list of available weights
    for(int i = 0; i < 10; ++i)
        if(s[i] == '1') avail.push_back(i+1);

    // Start with step=1, diff=0 (no weights yet), last=0 (sentinel)
    if(dfs(1, 0, 0)){
        cout << "YES\n";
        vector<int> ans;
        int step = 1, diff = 0, last = 0;
        // Reconstruct sequence following stored parent info
        while(step <= m){
            int w = parW[step][diff][last];
            ans.push_back(w);
            int ndiff = parDiff[step][diff][last];
            int nlast = parLast[step][diff][last];
            diff = ndiff;
            last = nlast;
            ++step;
        }
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
