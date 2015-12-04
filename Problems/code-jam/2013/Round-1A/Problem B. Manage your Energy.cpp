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
int v[10010],n,e,r,leave[10010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T;
    cin>>T;
    for(int x=1;x<=T;++x){
        cin>>e>>r>>n;
        r=min(e,r);
        for(int i=0;i<n;++i)cin>>v[i];
        stack<int>s;
        for(int i=n-1;i>=0;--i){
            while(!s.empty()&&v[s.top()]<v[i])s.pop();
            if(s.empty())leave[i]=0;
            else leave[i]=max(e-(s.top()-i)*1LL*r,0LL);
            s.push(i);
        }
        unsigned long long ans=0;
        for(int i=0;i<n;++i){
            if(e>leave[i])ans=ans+v[i]*1LL*(e-leave[i]),e=leave[i]+r;
            else e+=r;
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
}
