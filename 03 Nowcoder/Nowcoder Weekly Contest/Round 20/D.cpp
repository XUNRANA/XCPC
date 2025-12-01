#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string a,b;
	int la,lb,ans=1e9;
	cin>>a>>b;
	la=a.size();
	lb=b.size();
	for(int i=1;i<(1<<la);i++)
	{
		int x=0;
		int ca=0;
		for(int i1=0;i1<la;i1++)
		{
			if(i>>i1&1) x=x*10+a[i1]-'0',ca++;
		}
		
		for(int j=1;j<(1<<lb);j++)
		{
			int y=0;
			int cb=0;
			for(int j1=0;j1<lb;j1++)
			{
				if(j>>j1&1) y=y*10+b[j1]-'0',cb++;
			}
			
			if(x%y==0||y%x==0)
			{
				ans=min(ans,la-ca+lb-cb);
			}
		}
	}
	if(ans==1e9) ans=-1;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}




/*

#include <bits/stdc++.h>
using namespace std;
int ans=30;
map<pair<int,int>,int>f;
void dfs(int a,int x,int b,int y,int s)
{
	if(s>ans||f.count({a,b})) return ;
	f[{a,b}]=1;
	if(!a||!b||a%b==0||b%a==0)
	{
		ans=min(ans,s);
		return ;
	}
	if(a>9) for(int i=x;i<a;i*=10) dfs(a/(i*10)*i+a%i,i,b,y,s+1); 
	if(b>9) for(int i=y;i<b;i*=10) dfs(a,x,b/(i*10)*i+b%i,i,s+1); 
}
void solve()
{
	int a,b;
	cin>>a>>b;
	dfs(a,1,b,1,0);
	if(ans==30) ans=-1;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}


*/
