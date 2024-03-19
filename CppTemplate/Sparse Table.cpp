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
const int K=25;
vector<vector<int>> st(K+1,vector<int>(500005));
vector<int> lg(500005);
int f(int a,int b)
{
    return min(a,b);
}
void sparse_table(vector<int> a,int n)
{
    st[0]=a;
    for(int i=1;i<=K;i++)
    {
        for(int j=0;j+(1LL<<i)-1<n;j++)
        {
            st[i][j]=f(st[i-1][j],st[i-1][j+(1LL<<(i-1))]);
        }
    }
}
void precompute()
{
    lg[1]=0;
    for(int i=2;i<500000;i++)
    {
        lg[i]=lg[i/2]+1;
    }
}

signed main()
{
    fastio();
    precompute();
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sparse_table(a,n);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        r--;
        int i=lg[r-l+1];
        cout << min(st[i][l],st[i][r-(1LL<<i)+1]) << '\n';
    }
    
    return 0;
}