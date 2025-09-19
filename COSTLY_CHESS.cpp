#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   // Precompute knight directions (8 moves)
   vector<pii> dir{{2,1},{2,-1},{-2,1},{-2,-1},
                   {1,2},{1,-2},{-1,2},{-1,-2}};

   auto check = [&](int a,int b){
       return (a>=0 && a<=7 && b>=0 && b<=7);
   };

   // Build adjacency for *all* 64 cells once
   map<pii,vector<pair<pii,int>>> adj;
   for(int x=0;x<8;x++){
       for(int y=0;y<8;y++){
           pii u={x,y};
           for(auto d:dir){
               int nx=x+d.first, ny=y+d.second;
               if(check(nx,ny)){
                   int w = x*nx + y*ny;
                   adj[u].pb({{nx,ny},w});
               }
           }
       }
   }

   int a,b,c,d;
   while(cin>>a>>b>>c>>d){
       pii start={a,b}, goal={c,d};
       if(start==goal){
           cout<<0<<"\n";
           continue;
       }

       // Dijkstra
       map<pii,int> cost;
       priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
       pq.push({0,start});
       cost[start]=0;

       while(!pq.empty()){
           auto [du,u]=pq.top(); pq.pop();
           if(du>cost[u]) continue;
           if(u==goal) break;

           for(auto [v,w]:adj[u]){
               if(!cost.count(v) || cost[v]>du+w){
                   cost[v]=du+w;
                   pq.push({cost[v],v});
               }
           }
       }

       if(cost.count(goal)) cout<<cost[goal]<<"\n";
       else cout<<-1<<"\n";
   }
   return 0;
}
