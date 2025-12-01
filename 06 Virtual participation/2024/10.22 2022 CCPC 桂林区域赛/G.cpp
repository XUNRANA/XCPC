#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
vector<int>g[N];
int n,a[N],ans; 
struct node {
    multiset<int>st;
    void add(int x) {
        st.insert(x);
    }
    void del(int x) {
        st.erase(st.find(x));
    }
    int operator [] (int id)const {
        auto it = st.end();
        for (int i = 0; i <= id; i++)it--;
        return *it;
    }
}mx_line[N], mx_sub[N];
void dfs(int u, int fa) {
    //多添加一些0，放置取越界了
    mx_line[u].add(0); mx_line[u].add(0); mx_line[u].add(0); mx_line[u].add(0);
    mx_sub[u].add(0); mx_sub[u].add(0);
    for (int v : g[u]) 
	{
        if (v == fa)continue;
        dfs(v, u);
        mx_line[u].add(mx_line[v][0] + a[v]);
        mx_sub[u].add(mx_sub[v][0]);
    }
    mx_sub[u].add(mx_line[u][0] + a[u] + mx_line[u][1]);
}
void dfs1(int u, int fa) {
    // get ans
    ans = max(ans, mx_line[u][0] + mx_line[u][1] + mx_line[u][2] + mx_line[u][3]);
    for (int v : g[u]) {
        if (v == fa)continue;
        int del_sub1 = mx_line[u][0] + a[u] + mx_line[u][1];
        int del_sub2 = mx_sub[v][0];
        int del_line = mx_line[v][0] + a[v];
        mx_sub[u].del(mx_line[u][0] + a[u] + mx_line[u][1]);
        mx_sub[u].del(del_sub2);
        mx_line[u].del(del_line);
        mx_sub[u].add(mx_line[u][0] + a[u] + mx_line[u][1]);

        // get ans
        ans = max(ans, mx_sub[u][0] + mx_sub[v][0]);

        mx_sub[v].del(mx_line[v][0] + a[v] + mx_line[v][1]);
        mx_line[v].add(mx_line[u][0] + a[u]);
        mx_sub[v].add(mx_line[v][0] + a[v] + mx_line[v][1]);
        dfs1(v, u);


        mx_sub[u].del(mx_line[u][0] + a[u] + mx_line[u][1]);
        mx_line[u].add(del_line);
        mx_sub[u].add(del_sub2);
        mx_sub[u].add(del_sub1);

    }
}

void solve() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    dfs(1, 0);
    ans = mx_sub[1][0];
    dfs1(1, 0);
    cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
