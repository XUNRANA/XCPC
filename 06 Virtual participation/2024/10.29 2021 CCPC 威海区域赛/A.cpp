#include <bits/stdc++.h>
using namespace std;
int n,u,v,d[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
 		cin>>u>>v;
 		d[u]++;
 	    d[v]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) 
	if(d[i]<3) continue;
	else if(d[i]==3) cnt++;
	else
	{
		cout<<"0\n";
		return ;
	}
	
	cout<<n-cnt<<"\n";
	
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
