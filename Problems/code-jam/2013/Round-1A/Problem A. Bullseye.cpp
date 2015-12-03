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
    int T;
    cin>>T;
    for(int x=1;x<=T;++x){
        long long t,r;
        long double a,b,c;
        cin>>r>>t;
        a=2.0;
        b=2.0*r-1.0;
        c=-1.0*t;
        long long ans = ((-1.0*b+sqrt(b*b-4.0*a*c))/(2.0*a));
        if(ans*(2*ans+2*r-1)>t)--ans;
        ++ans;
        if(ans*(2*ans+2*r-1)>t)--ans;
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
}
