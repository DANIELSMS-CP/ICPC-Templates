//and in that light, I find deliverance
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
//defines
#define int long long
#define debug(x) cerr << "(" << #x << "=" << x << "," << __LINE__ << ")\n";
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);i++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
//constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 
const char dir[4]{'D','R','U','L'};
const int MOD=1e9+7; // change every problem
const int maxn=2e5+5;
const double eps=1e-9;
 
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
 
//Template
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
//Mods
int add(int a, int b) 
{
    if((a+=b)>=MOD)
    {
        a-=MOD;
    }
    return a;
}
int sub(int a, int b) 
{
  if((a-=b)<0)
  {
        a+=MOD;
  }
  return a;
}
int mul(int a,int b) 
{
    int ret=(a%MOD*b%MOD)%MOD;
    if(ret<0)
    {
        ret+=MOD;
    }
    return ret;
}

int n,l;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v]=++timer;
    up[v][0]=p;
    for (int i=1;i<=l;i++)
        up[v][i]=up[up[v][i-1]][i-1];

    for (int u:adj[v]) {
        if (u!=p)
            dfs(u,v);
    }
    tout[v]=++timer;
}

bool is_ancestor(int u,int v)
{
    return tin[u]<=tin[v] and tout[u]>=tout[v];
}

int lca(int u,int v)
{
    if (is_ancestor(u,v))
        return u;
    if (is_ancestor(v,u))
        return v;
    for (int i=l;i>=0;i--) {
        if (!is_ancestor(up[u][i],v))
            u=up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer=0;
    l=ceil(log2(n));
    up.assign(n,vector<int>(l + 1));
    dfs(root,root);
}
signed main()
{
    fastio();
    
    return 0;
}
