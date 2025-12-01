#include <bits/stdc++.h>
using namespace std;

struct p
{
	int g=-1;
	int f=-1;
	int m=-1;
}P[100000];
set<int>st;
int cnt;
void ck(int x,int d)
{
	if(d>5) return ;
	cnt++;
	st.insert(x);
	if(P[x].f!=-1) ck(P[x].f,d+1);
	if(P[x].m!=-1) ck(P[x].m,d+1);
}
void solve()
{
	int n,k;
	cin>>n;
	while(n--)
	{
		int id,x,y;
		char ch;
		cin>>id>>ch>>x>>y;
		if(ch=='M') P[id].g=1;
		else P[id].g=0;
		if(x!=-1) P[x].g=1;
		if(y!=-1) P[y].g=0;
		P[id].f=x;
		P[id].m=y; 
	}
	cin>>k;
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		st.clear();
		cnt=0;
		ck(x,1);
		ck(y,1);
		if(P[x].g==P[y].g) cout<<"Never Mind\n";
		else if(cnt!=st.size()) cout<<"No\n";
		else cout<<"Yes\n";
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

