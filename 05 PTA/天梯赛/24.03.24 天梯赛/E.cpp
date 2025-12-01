#include <bits/stdc++.h>
using namespace std;
int t,t1,n;
int f[10010];
int in[10010];
vector<int>g[10010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==0) in[i]=1;
        while(t--)
        {
            cin>>t1;
            f[t1+1]=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
    	if(in[i])
    	{
    		int i1=i;
    		g[i].push_back(i1-1);
    		while(f[i1]!=0)
    		{
    			g[i].push_back(f[i1]-1);
    			i1=f[i1];
			}
		}
	}
	int mx=0,f=0,cnt=0;
	for(int i=1;i<=n;i++) mx=max(mx,(int)g[i].size());
	vector<int>ans(mx);
	for(int i=1;i<=n;i++) 
	if(g[i].size()==mx) 
	{
		cnt++;
		/*
		cout<<mx<<"\n";
		for(auto j:g[i]) cout<<j<<" ";
		cout<<"\n";
		*/
		if(f==0)
		{
			ans=g[i];
			f=1;
		}
		
		for(int j=mx-1;j>=0;j--)
		{
			//cout<<g[i][j]<<" "<<ans[j]<<"\n";
			if(g[i][j]<ans[j])
			{
				for(int j1=j;j1>=0;j1--) ans[j1]=g[i][j1];
				break;
			}
			else if(g[i][j]>ans[j]) break;
		}
	}
	
	cout<<mx<<"\n";
	cout<<ans[mx-1];
	for(int i=mx-2;i>=0;i--) cout<<" "<<ans[i];
	
}
