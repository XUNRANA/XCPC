#include <bits/stdc++.h>
using namespace std;

int op[1000];
int L[1000];
int R[1000];
string s;
int idx;
int dfs(int u)
{
	if(!u)
	{
		char ch;
		cin>>ch;
		return ch-'0';
	}
	if(op[u]==1) return dfs(L[u])&dfs(R[u]);
	else if(op[u]==2) return dfs(L[u])|dfs(R[u]);
	else return dfs(L[u])^1;
}
void solve()
{
	int n,l,r;
	cin>>n;
	vector<int>f(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>op[i];
		if(op[i]==3) 
		{
			cin>>l;
			f[l]=1;
			L[i]=l;
		}
		else
		{
			cin>>l>>r;
			f[l]=f[r]=1;
			L[i]=l;
			R[i]=r;
		}
	}
	int q;
	cin>>q;
	int rt;
	for(int i=1;i<=n;i++) 
	if(!f[i])
	{
		rt=i;
		break;
	}
	
	while(q--)
	{
        if(dfs(rt)) cout<<"Ai\n";
		else cout<<"BuAi\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
