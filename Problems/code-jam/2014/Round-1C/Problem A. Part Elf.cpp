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
int rec(long long p,long long q){
    int t,ret;
    if(p==q||p==0)return 0;
    if(q&1)return -1;
    if(p<=(q>>1)){
        t=rec(p,q>>1);
        if(t==-1)return -1;
        return t+1;
    }else{
        t=rec(p-(q>>1),q>>1);
        if(t==-1)return -1;
        return 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin),freopen("output.out","w",stdout);
	int T;
    cin>>T;
    long long p,q;
    for(int t=1,c,i;t<=T;++t){
        c=0;
        string s;
        cin>>s;
        p=q=0;
        for(i=0;s[i]!='/';++i)p=p*10+(s[i]-'0');
        for(i=i+1;i<(int)s.sz();++i)q=q*10+(s[i]-'0');
        c=rec(p,q);
        if(c==-1)printf("Case #%d: impossible\n",t);
        else printf("Case #%d: %d\n",t,c);
    }
}
