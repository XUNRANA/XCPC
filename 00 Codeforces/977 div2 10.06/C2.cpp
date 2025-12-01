#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int a[200010];
int b[200010];
int pos[200010];
int val[200010];
set<int>g[200010];
int bad,s,t;

void update(int i)
{
//	cout<<"up:"<<i<<" "<<a[i]<<" "<<bad<<"\n";
	if(i-1>=1)   bad-=val[i-1]>val[i];
	if(i+1<=n) bad-=val[i]>val[i+1];
//	cout<<"bad:"<<bad<<"\n";
//	cout<<val[i]<<"?\n" ;
	val[i]=*g[a[i]].begin();
//	cout<<"af:"<<val[i]<<"\n";
	if(i-1>=1)   bad+=val[i-1]>val[i];
	if(i+1<=n) bad+=val[i]>val[i+1];
//	cout<<"up:"<<i<<" "<<a[i]<<" "<<bad<<"\n";
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) g[i].clear(),g[i].insert(m+1);
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;//pos[x]:x在数组a中的下标 
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		g[b[i]].insert(i);//g[x]：x在b数组中的下标的集合 
	}
/*
3
4 2 2
1 2 3 4
1 1
1 2
1 1

3 6 2
1 2 3
1 1 2 3 3 2
3 3
2 2

4 6 2
3 1 4 2
3 1 1 2 3 4
3 4
4 2
*/	
	for(int i=1;i<=n;i++) val[i]=*g[a[i]].begin();//*g[x].begin()：x在b中第一次出现的下标 
	bad=0;
	//n-1对前后关系 
	for(int i=1;i<=n-1;i++) bad+=val[i]>val[i+1];//首次出现：a[i]比a[i+1]更早，坏点 
	
//	for(int i=1;i<=n;i++) cout<<val[i]<<" ";
//	cout<<"\n";
	
//	cout<<bad<<"\n";
	if(bad) cout<<"TIDAK\n";
	else cout<<"YA\n";
	
	for(int i=1;i<=q;i++)
	{
		cin>>s>>t;
		int old=b[s];
		
		g[b[s]].erase(s);
		
		b[s]=t;
		
		g[b[s]].insert(s);
		
		update(pos[old]);//maybe affect 数组a的第pos[old]个数 
		update(pos[b[s]]);//maybe affect 数组a的第pos[t]个数 
		
//		cout<<bad<<"\n";
//		for(int i=1;i<=n;i++) cout<<val[i]<<" ";
//		cout<<"\n";
		if(bad) cout<<"TIDAK\n";
		else cout<<"YA\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
