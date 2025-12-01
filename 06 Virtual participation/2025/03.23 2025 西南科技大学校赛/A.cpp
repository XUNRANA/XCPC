#include <bits/stdc++.h>
using namespace std;

int a[26],p[26];
void solve()
{
    string s;
    int n,m;
    for(int i=0;i<26;i++) a[i]=p[i]=i;
    cin>>n>>m>>s;
    while(m--)
    {
        char c,d;
        cin>>c>>d;
        swap(a[p[c-'a']],a[p[d-'a']]);
        swap(p[c-'a'],p[d-'a']);
    }
    for(auto i:s) cout<<char(a[i-'a']+'a');
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
