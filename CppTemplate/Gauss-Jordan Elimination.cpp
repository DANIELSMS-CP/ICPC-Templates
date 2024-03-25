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

const int INF=2;
int gauss_jordan(vector<vector<double>> a,vector<double> &ans)
{
    int n=(int)a.size();
    int m=(int)a[0].size()-1;
    vector<int> where(m,-1);
    for(int row=0,col=0;row<n and col<m;col++)
    {
        int sel=row;
        for(int i=row;i<n;i++)
        {
            if(abs(a[i][col])>abs(a[sel][col]))
            {
                sel=i;
            }
        }
        if(abs(a[sel][col])<eps)
        {
            continue;
        }
        for(int i=col;i<=m;i++)
        {
            swap(a[sel][i],a[row][i]);
        }
        where[col]=row;
        for(int i=0;i<n;i++)
        {
            if(i!=row)
            {
                double c=a[i][col]/a[row][col];
                for(int j=col;j<=m;j++)
                {
                    a[i][j]-=a[row][j]*c;
                }
            }
        }
        row++;
    }
    ans.assign(m,0);
    for(int i=0;i<m;i++)
    {
        if(where[i]!=-1)
        {
            ans[i]=a[where[i]][m]/a[where[i]][i];
        }
    }
    for(int i=0;i<n;i++)
    {
        double sum=0;
        for(int j=0;j<m;j++)
        {
            sum+=ans[j]*a[i][j];
        }
        if(abs(sum-a[i][m])>eps)
        {
            return 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(where[i]!=-1)
        {
            return INF;
        }
    }
    return 1;
}
signed main()
{
    fastio();
    /*
        Ax=B
        A is the matrix and B is its last column
        returns ans
    */
    
    return 0;
}