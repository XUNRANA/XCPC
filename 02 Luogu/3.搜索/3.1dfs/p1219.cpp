#include <bits/stdc++.h>
using namespace std;
int r[15],l[15],f[30],s[30],n,ans;
void dfs(int i)
{
	if(i>n)
	{
		if(ans<=2) 
		{
			for(int j=1;j<=n;j++) cout<<r[j]<<" ";
			cout<<"\n";
		}
		ans++;
		return ;
	}
	else
	{
		for(int j=1;j<=n;j++)
		{
			if((!l[j])&&(!f[i+j])&&(!s[i-j+n]))
			{
				r[i]=j;
				l[j]=f[i+j]=s[i-j+n]=1;
				dfs(i+1);
				l[j]=f[i+j]=s[i-j+n]=0;
			}
		}
	}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<ans;
} 
