#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100];
void solve()
{
    int x,mx,s;
    cin>>x;
    if(x==1)
    {
        cout<<"-1\n";
        return ;
    }
    
    map<int,int>mp;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            mp[i]++;
            x/=i;
        }
    }
    if(x!=1) mp[x]++;
    
    mx=s=0;
    for(auto i:mp) 
    {
        if(i.second>mx)
        {
            mx=i.second;
            x=i.first;
        }
        s+=i.second;
    }
    
    if(s==1||(s+1)>=2*mx)
    {
    	int i=1;
    	while(mx--) a[i]=x,i+=2;
    	if(i>s) i=2;
    	for(auto j:mp)
    	{
    		if(j.first==x) continue;
    		int t=j.second;
    		while(t--)
    		{
    			a[i]=j.first;
    			i+=2;
    			if(i>s) i=2;
			}
		}
		cout<<s<<"\n";
		for(int i=1;i<=s;i++) cout<<a[i]<<" ";
	}
	else cout<<"-1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

