#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],b[100000],c[100000],f[100000],ans,x,y;
vector<pair<int,int>>d(100005);
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i].first>>d[i].second;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>b[i];
    	a[b[i]]=i;
    }
    
    for(int i=1;i<=n;i++)
    {
    	x=d[i].first;
    	y=d[i].second;
    	if(a[x]&&a[y]) 
		{
			f[x]=f[y]=1;
			x=a[x];
			y=a[y];
			if(x>y) swap(x,y);
			if(x+1==y) 
			{
				c[x-1]++;
				c[x]--;
				c[y+1]++;
				c[y+2]--;
			}
			else 
			{
				c[x+1]++;
				c[y]--;
			}
		}
	}
	vector<int>res;
	for(int i=1;i<=m;i++) 
	{
		c[i]+=c[i-1];
		if(!f[i]) 
		{
			if(c[i]>ans)
			{
				res.clear();
				ans=c[i];
				res.push_back(b[i]);
			}
			else if(c[i]==ans) res.push_back(b[i]);
		}
	}
	//cout<<res.size()<<"\n";
	int f=0;
	sort(res.begin(),res.end());
	for(auto i:res) 
	{
		if(f==1) cout<<" ";
		printf("%05d",i);
		f=1;
	}
}
