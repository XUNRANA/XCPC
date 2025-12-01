#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,op,x,ans,n1,n2;
map<int,int>m[1000010];
void solve()
{
	cin>>n>>q;
	n1=n;
	map<int,int>t;
	for(auto i:m[n]) t[i.first]+=i.second;
	vector<int>v;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x;
			for(auto i:m[x]) t[i.first]+=i.second;
			ans=1;
			for(auto i:t) ans*=(i.second+1);
			v.push_back(x);
			
			n2=n;
			for(auto i:v) n2=n2*i%ans;
			if(n2==0) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else
		{
			v.clear();
			t.clear();
			for(auto i:m[n]) t[i.first]+=i.second;
		}
	} 
	cout<<"\n";
}
signed main()
{
	for(int k=2;k<=1e6;k++)
	{
		int j=k;
		for(int i=2;i*i<=j;i++)
		{
			while(j%i==0) 
			{
				m[k][i]++;
				j/=i;
			}
		}
		if(j!=1) m[k][j]++;		
	}

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
