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
#define pr(a) printf("%d",a)
#define sc(a) scanf("%d",&a)
using namespace std;

class SegT{
#define data_type long long
private:
    int n,h;
    vector<data_type> t;
    vector<data_type> d;

public:
    void initi(vector<data_type>&v){
        n=v.size();
        t.resize(n<<1,0);
        d.resize(n,0);
        h = sizeof(int) * 8 - __builtin_clz(n);
        for (int i = 0; i < n; ++i) t [ n + i]=v[i];
        for (int i = n - 1; i > 0; --i) t[i] =t[i<<1] +t[i<<1|1];
    }
    void apply(int p, data_type value){
        t[p] += value;
        if (p < n) d[p] += value;
    }
    void build(int p){
        while (p > 1) p >>= 1, t[p] = t[p<<1]+ t[p<<1|1] + d[p];
    }
    void push(int p){
        for (int s = h; s > 0; --s){
            int i = p >> s;
            if (d[i] != 0){
                apply(i<<1, d[i]);
                apply(i<<1|1, d[i]);
                d[i] = 0;
            }
        }
    }
    data_type query(int l, int r){
        if(n==0)return 0;
        l += n, r += n+1;
        push(l);
        push(r - 1);
        data_type res = 0;
        for (; l < r; l >>= 1, r >>= 1){
            if (l&1) res +=t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }

};
class HLD{
public:
    vector<vector<pair<int,int> > >g;
    vector<pair<SegT,int> >ch;
    vector<vector<int> >chnd;
    vector<pair<int,int> >par;
    vector<pair<int,int> >ind;
    vector<int>ndsz;
    vector<int>mxch;
    vector<int>lev;
    int n;
    int dfs(int u,int p){
        int mxsz=0,tsz,tmxch=-1;
        ndsz[u]=1;
        lev[u]=lev[p]+1;
        for(int i=0;i<(int)g[u].size();++i)
            if(g[u][i].F!=p){
                par[g[u][i].F]=mp(u,g[u][i].S);
                tsz=dfs(g[u][i].F,u);
                ndsz[u]+=tsz;
                if(tsz>mxsz)mxsz=tsz,tmxch=g[u][i].F;
            }
        mxch[u]=tmxch;
        return ndsz[u];
    }
    void hld(int u,vector<long long>&v,vector<int>&w,int p){
        ind[u]=mp(ch.size(),v.size());
        if(mxch[u]==-1){
            SegT T;
            T.initi(v);
            ch.pb(mp(T,p));
            chnd.pb(w);
            return ;
        }
        v.pb(par[mxch[u]].S);
        w.pb(u);
        hld(mxch[u],v,w,p);
        for(int i=0,v;i<(int)g[u].size();++i){
            v=g[u][i].F;
            if(v!=par[u].F&&v!=mxch[u]){
                vector<long long>tmp;
                vector<int>tmpp;
                hld(v,tmp,tmpp,v);
            }
        }
    }
    void build(vector<vector<pair<int,int> > >&g){
        this->g=g;
        n=this->g.size();
        par.resize(n),ndsz.resize(n),mxch.resize(n),ind.resize(n),lev.resize(n);
        vector<long long>v;
        vector<int>w;
        par[0]=mp(0,0);
        lev[0]=0;
        dfs(0,-1);
        hld(0,v,w,0);
    }
    int max_edg(int u,int v){
        long long ret=0;
        int chv=ind[v].F,chu=ind[u].F;
        while(chu!=chv){
            if(lev[ch[chu].S]<lev[ch[chv].S])swap(u,v);
            chu=ind[u].F;
            ret+=ch[chu].F.query(0,ind[u].S-1),ret+=par[ch[chu].S].S,u=par[ch[chu].S].F,chu=ind[u].F;
            chv=ind[v].F;
        }
        if(u!=v){
            if(lev[u]<lev[v])ret+=ch[chu].F.query(ind[u].S,ind[v].S-1);
            else ret+=ch[chu].F.query(ind[v].S,ind[u].S-1);
        }
        return ret;
    }
    int kth_mem(int u,int v,int k){
        int cntv=0,v0=v;
        int chv=ind[v].F,chu=ind[u].F;
        while(chu!=chv&&k>1){
            if(lev[ch[chu].S]>lev[ch[chv].S]){
                if(k<=ind[u].S+1){
                    return chnd[chu][ind[u].S-k+1];
                }else{
                    k-=ind[u].S+1;
                    u=par[ch[chu].S].F,chu=ind[u].F;
                }
            }else{
                cntv+=ind[v].S+1;
                v=par[ch[chv].S].F,chv=ind[v].F;
            }
        }
        if(k==1)return u;
        if(lev[u]<lev[v]){
            cntv+=ind[v].S-ind[u].S;
            v=u,chv=ind[v].F;
        }else if(lev[u]>lev[v]){
            if(k<=ind[u].S-ind[v].S+1){
                return chnd[chu][ind[u].S-k+1];
            }
            else{
                k-=ind[u].S-ind[v].S;
                u=v,chu=ind[u].F;
            }
        }
        if(k==1)return u;
        k=cntv-k+2;
        u=v0;
        chu=ind[u].F;
        while(k>1){
                if(k<=ind[u].S+1){
                    return chnd[chu][ind[u].S-k+1];
                }else{
                    k-=ind[u].S+1;
                    u=par[ch[chu].S].F,chu=ind[u].F;
                }
        }
        return u;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    freopen("input.in","r",stdin);
//    freopen("output.out","w",stdout);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        vector<vector<pair<int,int> > >g;
        g.resize(n);
        for(int i=0,u,v,w;i<n-1;++i){
            scanf("%d%d%d",&u,&v,&w);
            --u;--v;
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }
        HLD d;
        d.build(g);
        char s[10];
        while(true){
            scanf("%s",s);
            int u,v;
            if(strcmp(s,"DONE")==0)break;
            if(strcmp(s,"DIST")==0){
                scanf("%d%d",&u,&v);
                --u,--v;
                printf("%d\n",d.max_edg(u,v));
            }else{
                int k;
                scanf("%d%d%d",&u,&v,&k);
                --u,--v;
                printf("%d\n",1+d.kth_mem(u,v,k));
            }
        }
    }
}

