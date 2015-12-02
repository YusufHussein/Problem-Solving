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
vector<int>lvl;
class SegT{
#define data_type int
private:
    int n;
    vector<data_type> t;
public:
    SegT(){
    }
    SegT(int x){
        n=x;
        t.resize(n<<2 ,lvl.size()-1);
    }
    int q(int l, int r,int b,int e,int nd){
        if(b>=l&&e<=r)return t[nd];
        if(e<l||b>r)return lvl.sz()-1;
        int m=(b+e)>>1;
        int ql=q(l,r,b,m,nd<<1);
        int qr=q(l,r,m+1,e,(nd<<1)|1);
        return lvl[ql]<lvl[qr]?ql:qr;
    }int query(int l, int r){return q(l,r,0,n-1,1);}
    void update(int p,int v,int b,int e,int nd){
        if(b==e&&e==p){
            t[nd]=v;
            return ;
        }
        if(e<p||b>p)return ;
        int m=(b+e)>>1;
        update(p,v,b,m,nd<<1);
        update(p,v,m+1,e,(nd<<1)|1);
        t[nd]=lvl[t[(nd<<1)|1]]<lvl[t[nd<<1]]?t[(nd<<1)|1]:t[nd<<1];
    }
    void set(int p,int v){update(p,v,0,n-1,1);}
};
class HLD{
public:
    struct node{
        int p,ch,chi,mch,lvl,sz;
    };
    vector<vector<int> >g;
    vector<pair<SegT,int> >ch;
    vector<node>N;
    int n;
    void dfs(int u){
        N[u].sz=1,N[u].mch=-1;
        if(u!=0)N[u].lvl=N[N[u].p].lvl+1;
        int mxsz=0;
        for(int i=0,v;i<(int)g[u].sz();++i){
            v=g[u][i];
            if(v!=N[u].p){
                N[v].p=u;
                dfs(v);
                N[u].sz+=N[v].sz;
                if(N[v].sz>mxsz)mxsz=N[v].sz,N[u].mch=v;
            }
        }
    }
    void hld(){
        queue<pair<int,pair<int,int> > >q;
        q.push(mp(0,mp(0,0)));
        int cnt=1;
        N[0].ch=0;
        ch.resize(n);
        while(!q.empty()){
            int u=q.front().F,chc=q.front().S.F,p=q.front().S.S;
            q.pop();
            N[u].ch=N[p].ch,N[u].chi=chc++;
            if(N[u].mch==-1){
                ch[N[p].ch]=mp(SegT(chc),p);
                continue ;
            }
            q.push(mp(N[u].mch,mp(chc,p)));
            for(int i=0,v;i<(int)g[u].sz();++i){
                v=g[u][i];
                if(v!=N[u].p&&v!=N[u].mch){
                    N[v].ch=cnt++;
                    q.push(mp(v,mp(0,v)));
                }
            }
        }

    }
    void build(){
        n=g.sz();
        N.resize(n);
        N[0].lvl=0,N[0].p=0;
        dfs(0);
        lvl.resize(n+1,n);
        for(int i=0;i<n;++i)lvl[i]=N[i].lvl;
        hld();
    }
    int max_edg(int u){
        int t,ans=n,chu=N[u].ch;
        while(chu!=0){
            t = ch[chu].F.query(0,N[u].chi);
            if(t!=n)ans=t;
            u=N[ch[chu].S].p;
            chu=N[u].ch;
        }
        t = ch[chu].F.query(0,N[u].chi);
        if(t!=n)return t;
        if(ans!=n)return ans;
        return -2;
    }
    void update(int u){
        int chu=N[u].ch;
        if(ch[chu].F.query(N[u].chi,N[u].chi)==n){
            ch[chu].F.set(N[u].chi,u);
        }else{
            ch[chu].F.set(N[u].chi,n);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.in","r",stdin);
//    freopen("output.out","w",stdout);
        int n,q;
        cin>>n>>q;
        HLD d;
        d.g.resize(n);
        for(int i=0,u,v;i<n-1;++i){
            cin>>u>>v;
            --u;--v;
            d.g[u].pb(v);
            d.g[v].pb(u);
        }
        d.build();
        while(q--){
            int u,v;
            cin>>u>>v;
            if(u){
                cout<<d.max_edg(v-1)+1<<endl;
            }else{
                d.update(v-1);
            }
        }
}
