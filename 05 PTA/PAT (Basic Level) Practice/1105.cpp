#include <bits/stdc++.h>
using namespace std;


int a[100000];
int d[100000];
int nxt[100000];
int h1,h2,n;
void solve()
{
	cin>>h1>>h2>>n;
	while(n--)
	{
		int ad,da,ne;
		cin>>ad>>da>>ne;
		d[ad]=da;
		nxt[ad]=ne;
	}
	int h11=h1;
	int c1=0,c2=0;
	vector<int>a,b;

	while(h11!=-1)
	{
		a.push_back(h11);
		c1++;
		// cout<<d[h11]<<" ";
		h11=nxt[h11];
	}
	// cout<<"\n";

	int h22=h2;
	while(h22!=-1)
	{
		b.push_back(h22);
		c2++;
		// cout<<d[h22]<<" ";
		h22=nxt[h22];
	}
	// cout<<"\n";


	vector<int>ans;
	if(c1>c2)
	{
		int j=c2-1;
		for(auto i:a)
		{
			ans.push_back(i);
			if((ans.size()+1)%3==0&&j>=0) 
			{
				ans.push_back(b[j]);
				j--;
			}
		}
	}
	else
	{
		// cout<<"?\n";
		int j=c1-1;
		for(auto i:b)
		{
			ans.push_back(i);
			if((ans.size()+1)%3==0&&j>=0) 
			{
				ans.push_back(a[j]);
				j--;
			}
			
		}
	}


	for(int i=0;i<ans.size();i++)
	if(i!=ans.size()-1) printf("%05d %d %05d\n",ans[i],d[ans[i]],ans[i+1]);
	else printf("%05d %d %d\n",ans[i],d[ans[i]],-1);
	// for(auto i:ans) cout<<d[i]<<"? ";
	// cout<<"\n";
	// cout<<c1<<" "<<c2<<"\n";
}



signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
