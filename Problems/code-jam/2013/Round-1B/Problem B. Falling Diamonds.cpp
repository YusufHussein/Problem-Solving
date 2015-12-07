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
//    freopen("input.in","r",stdin);
//    freopen("output.out","w",stdout);
    vector<vector<long double> >pas(2);
    pas[0].pb(1);
    pas[1].pb(0.5);
    for(int i=2; i<=10010; ++i){
        pas.pb(vector<long double>(1+(i>>1)));
        if(i&1)pas[i][0]=(pas[i-1][0]+pas[i-1][1])/2.0;
        else pas[i][0]=pas[i-1][0];
        pas[i][pas[i].sz()-1]=pas[i-1][pas[i-1].sz()-1]/2.0;
        for(int j=1; j<(int)pas[i].sz()-1; ++j){
            if(i&1)pas[i][j]=(pas[i-1][j]+pas[i-1][j+1])/2.0;
            else pas[i][j]=(pas[i-1][j]+pas[i-1][j-1])/2.0;
        }
    }
	int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        int n,x,y;
        cin>>n>>x>>y;
        int m=(y+abs(x))>>1;
        n-=m+((m*(m-1))<<1);
        if(n<=0||(x==0&&n<=4*m)){
            printf("Case #%d: %.7lf\n",t,0.0);
            continue;
        }if(n>=4*m){
            printf("Case #%d: %.7lf\n",t,1.0);
            continue;
        }
        long double ans=0.0;
        if(n<=(m<<1)){
            int j=0,u=n,c=u-y;
            for(int i=pas[u].sz()-1;i>=0&&j<c;--i,++j){
                ans+=pas[u][i];
            }for(int i=((u&1)==0);i<(int)pas[u].sz()&&j<c;++i,++j){
                ans+=pas[u][i];
            }
        }else{
            int j=0,u=(m<<2)-n,c=(m<<1)-y;
            for(int i=pas[u].sz()-1;i>=0&&j<c;--i,++j){
                ans+=pas[u][i];
            }for(int i=((u&1)==0);i<(int)pas[u].sz()&&j<c;++i,++j){
                ans+=pas[u][i];
            }
        }
        printf("Case #%d: %.7lf\n",t,(double)ans);
    }
}
