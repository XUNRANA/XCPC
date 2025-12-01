#include <bits/stdc++.h>
using namespace std;
#define int long long

int nex[100010][26];
int cnt[100010*26];
int cnt1;
void insert(string s)//插入trie树 
{
	int now=0;
    cnt[now]++;
	for(auto i:s)
	{
		int t=i-'a';
		if(!nex[now][t]) nex[now][t]=++cnt1;
		now=nex[now][t];
        cnt[now]++;
	}
}
int find(string s)
{
	int now=0;
	for(auto i:s)
	{
		int t=i-'a';
		if(!nex[now][t]) return 0;
		now=nex[now][t];
	}
    return cnt[now];
}
char ch[100010];
int op[100010];
void solve() 
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) 
    {
        string s;
        cin>>s;
        insert(s);
    }
    string t="";
    while(q--)
    {
        int a;
        char b;
        cin>>a;
        if(a==1)
        {
            cin>>b;
            t+=b;
        } 
        else
        {
            if(t.size()>1) t=t.substr(0,t.size()-1);
            else t=""; 
        }
        cout<<find(t)<<"\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}