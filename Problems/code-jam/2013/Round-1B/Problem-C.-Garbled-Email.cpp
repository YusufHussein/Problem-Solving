///70sec :(
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
string a[521197];
int dp[4010][6],dsz=521196;
string s;
int solve(int i,int j);
void rec(int i,int j,const string &t,int m,int c){
    int k=lower_bound(a,a+dsz,t)-a;
    if(k<dsz&&t.compare(a[k])==0)
        dp[i][j]=min(dp[i][j],solve(i+t.sz(),min((int)t.sz()-m,5))+c);
}
int solve(int i,int j){
    if(i==(int)s.sz())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=1e9;
    string t;
    char c1,c2;
    for(int k=0;k<10&&i+k<(int)s.sz();++k){
        t.pb(s[i+k]);
        rec(i,j,t,-j,0);
        for(int l=5-j;l<=k;++l){
            c1=t[l];
            for(int m='a';m<='z';++m){
                t[l]=m;
                rec(i,j,t,l,1);
                for(int n=l+5;n<=k;++n){
                    c2=t[n];
                    for(int o='a';o<='z';++o){
                        t[n]=o;
                        rec(i,j,t,n,2);
                    }
                    t[n]=c2;
                }
            }
            t[l]=c1;
        }
    }
    return dp[i][j];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    filebuf fb;
    fb.open ("dic.txt",std::ios::in);
    istream in(&fb);
    for(int i=0;i<dsz;++i){
        in>>a[i];
    }
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
	int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        cin>>s;
        memset(dp,-1,sizeof dp);
        printf("Case #%d: %d\n",t,solve(0,5));
    }
}
