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

/*
    Fenwick Tree (1-indexed)
*/
template<typename T=int> 
struct FT
{
    vector<int> bit;
    FT(int n=0)
    {
        bit=vector<T>(n+1);
    }
    inline void merge(T&a,T&b)
    {
        a+=b;
        /*
            You can replace with other stuff, like a=max(a,b) or min.
        */
    }
    void update(int id,T x)
    {
        id++;
        while(id<sz(bit))
        {
            merge(bit[id],x);
            id+=id&-id;
        }
    }
    T query(int id)
    {
        id++;
        T ret=T();
        while(id)
        {
            merge(ret,bit[id]);
            id-=id&-id;
        }
        return ret;
    }
};
signed main()
{
    fastio();
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    FT<int> Fenwick_Tree(n+1);
    for(int i=0;i<n;i++)
    {
        Fenwick_Tree.update(i,a[i]);
    }
    while(q--)
    {
        int type;
        cin >> type;
        if(type==0)
        {
            int p,x;
            cin >> p >> x;
            Fenwick_Tree.update(p,x);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << Fenwick_Tree.query(r-1)-Fenwick_Tree.query(l-1) << '\n';
        }
    }
    
    return 0;
}