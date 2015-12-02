/// LCA
int n,l;
vector <vector <int> > G;
vector <int> tin, tout;
int timer;
vector <vector <int> > up;

void DFS (int v, int P = 0) {
    tin [v] = ++ timer;
    up [v] [0] = P;
    for (int i = 1; i <= l; i ++)
        up [v] [i] = up [up [v] [i-1]] [i-1];
    for (size_t i = 0 ; i <G [v] .size (); i ++) {
        int to  = G [v] [i];
        if (to!= P)
            DFS (to, v);
    }
    tout [v] = ++ timer;
}

bool upper (int a, int b) {
    return tin [a] <= tin [b] && tout [a]>= tout [b];
}

int lca (int a, int b) {
    if (upper (a, b)) return a;
    if (upper (b, a)) return b;
    for (int i = l; i>= 0; --i)
        if (! upper (up [a] [i], b))
            a = up [a] [i];
    return up [a][0];
}
/// LCA

///LCA main
    tin.resize (n), tout.resize (n), up.resize (n);
    l = 1;
    while ((1 << l) <= n) ++ l;
    for (int i = 0; i <n; i ++) up [i] .resize (l + 1);
    DFS (0);
///LCA
