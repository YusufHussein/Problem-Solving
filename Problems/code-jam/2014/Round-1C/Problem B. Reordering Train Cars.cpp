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
int b[30],e[30],be[30],in[30],p[101];
int main() {
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
	int T;
    cin>>T;
    p[0]=1;
    for(int i=1;i<=100;++i)p[i]=(p[i-1]*1LL*i)%MOD;
    for(int t=1,c,x;t<=T;++t){
        int n,ans=1;
        memset(b,0,sizeof b);
        memset(e,0,sizeof e);
        memset(be,0,sizeof be);
        memset(in,0,sizeof in);
        string s;
        cin>>n;
        while(n--){
            cin>>s;
            int sz=s.sz();
            if(s[0]==s[sz-1]){
                for(int i=0;i<sz;++i)
                    if(s[i]!=s[0])
                        ans=0;
                ++be[s[0]-'a'];
            }else if(in[s[0]-'a']||in[s[sz-1]-'a']||b[s[0]-'a']||e[s[sz-1]-'a']){
                ans=0;
            }else{
                b[s[0]-'a']=e[s[sz-1]-'a']=true;
                int i=1;
                for(i=1;i<sz&&s[i]!=s[sz-1];++i){
                    if(s[i]!=s[i-1]){
                        if(in[s[i]-'a']||b[s[i]-'a']||e[s[i]-'a'])ans=0;
                        in[s[i]-'a']=true;
                    }
                }
                for(;i<sz;++i)if(s[i]!=s[sz-1])ans=0;
            }
        }
        x=0,c=0;
        for(int i=0;i<26;++i){
            if(b[i]&&!e[i])++x,++c;
            if(!b[i]&&e[i])--x;
        }
        for(int i=0;i<26;++i){
            if(be[i]!=0&&!b[i]&&!e[i])c++;
            ans=(ans*1LL*p[be[i]])%MOD;
        }
        if(x!=0||c<1)ans=0;
        ans=(ans*1LL*p[c])%MOD;
        printf("Case #%d: %d\n",t,ans);
    }
}
