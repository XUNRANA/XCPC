#include <bits/stdc++.h>
using namespace std;
int n;
#define N 1000
int a[N];
int b[N];
int L[N];
int R[N];
int idx[N];
void pre(int rt,int l,int r)
{
	if(l>r) return ;
	int i=l;
	while(i<=r&&a[i]!=b[rt]) i++;
	//cout<<b[rt]<<" ";
	if(l>i-1) L[b[rt]]=-1;
	else L[b[rt]]=b[rt-(r-i)-1];
	if(i+1>r) R[b[rt]]=-1;
	else R[b[rt]]=b[rt-1];
	pre(rt-(r-i)-1,l,i-1);
	pre(rt-1,i+1,r);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	pre(n,1,n);
	for(int i=1;i<=n;i++) cout<<L[i]<<" "<<R[i]<<"\n";
	queue<int>q;
	q.push(b[n]);
	vector<int>ans1,ans2;
	ans1.push_back(b[n]);
	ans2.push_back(b[n]);
	while(1)
	{
		queue<int>q1;
		int f=0,l=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(L[u]!=-1) 
			{
				q1.push(L[u]);
				if(!f) f=L[u];
				l=L[u];
			}
			if(R[u]!=-1) 
			{
				q1.push(R[u]);
				if(!f) f=R[u];
				l=R[u];
			}
		}
////		cout<<l<<" "<<f<<"\n";
		if(l==f&&l==0) break;
		ans1.push_back(f);
		ans2.push_back(l);
		q=q1;
	}
	cout<<"R:";
	for(auto i:ans2) cout<<" "<<i;
	cout<<"\n";
	
	cout<<"L:";
	for(auto i:ans1) cout<<" "<<i;
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
