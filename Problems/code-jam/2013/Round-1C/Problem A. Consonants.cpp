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
int v[260];
int main() {
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    v['a']=v['o']=v['e']=v['i']=v['u']=true;
	int T;
    cin>>T;
    for(int t=1,c,x;t<=T;++t){
        string s;
        int n;
        cin>>s>>n;
        long long ans=0,pre=0;
        c=x=0;
        for(int i=s.sz()-1;i>=0;--i){
            ans+=pre;
            if(v[s[i]])c=0;
            else ++c;
            ++x;
            if(c>=n){
                ans+=x-n+1;
                pre+=x-n+1;
                x=n-1;
            }
        }
        printf("Case #%d: %lld\n",t,ans);
    }
}
