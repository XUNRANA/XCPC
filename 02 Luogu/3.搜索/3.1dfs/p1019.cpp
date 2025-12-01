#include <bits/stdc++.h>
using namespace std;
string s[21];
int n,v[21],yc[21][21],res,ans,f;
char ch;
int fx(int x,int y)
{
	int lx=s[x].size()-1,ly=s[y].size()-1;
	for(int i=lx,j=1;i>=0;i--,j++)
	if(j<=ly&&s[x].substr(i,j)==s[y].substr(0,j)) return j;
	return 0;	
}
void dfs(int p)
{
	f=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i]>=2||!yc[p][i]||yc[p][i]==s[p].size()||yc[p][i]==s[i].size()) continue;
		ans+=s[i].size()-yc[p][i];
		v[i]++;
		f=1;
		dfs(i);
		ans-=s[i].size()-yc[p][i];
		v[i]--;
	}
	if(f==0) res=max(res,ans);
	return ;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	cin>>ch;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) yc[i][j]=fx(i,j);
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]==ch)
		{
			v[i]++;
			ans=s[i].size();
			dfs(i);
			v[i]=0;
		}
	}
	cout<<res;
}
