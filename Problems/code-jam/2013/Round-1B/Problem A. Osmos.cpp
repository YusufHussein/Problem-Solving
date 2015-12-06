#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz size
#define endl '\n'
#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define MOD 1000000007
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define pr(a) printf("%d\n",a)
#define sc(a) scanf("%d",&a)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T,n,A;
    vector<int>m;
    cin>>T;
    for(int t=1;t<=T;++t){
        cin>>A>>n;
        m.resize(n);
        for(int i=0;i<n;++i)cin>>m[i];
        sort(m.begin(),m.end());
        vector<int>dp(2000000);
        vector<int>tmp(2000000);
        for(int i=n-1;i>=0;--i){
            tmp=dp;
            dp.resize(2000000,0);
            for(int j=m[n-1]+1;j>=A;--j){
                if(j>m[i])dp[j]=tmp[j+m[i]];
                else dp[j]=min(tmp[j],dp[(j<<1)-1])+1;
            }
        }
        cout<<"Case #"<<t<<": "<<dp[A]<<endl;
    }
}
