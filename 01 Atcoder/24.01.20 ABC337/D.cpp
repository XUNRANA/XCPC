#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h,w,k,s1,s2,s3,ans=1e9;
	
	cin>>h>>w>>k;
	
	vector<vector<char>> s(h+1,vector<char>(w+1));
	
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin>>s[i][j];
	
	for(int i=1;i<=h;i++)
	{
		s1=s2=s3=0;
		for(int j=1;j<=w;j++)
		{
			if(s[i][j]=='.') s1++;
			else if(s[i][j]=='o') s2++;
			else s3++;
			if(j>k)
			{
				if(s[i][j-k]=='.') s1--;
				else if(s[i][j-k]=='o') s2--;
				else s3--;
			}
			if(j>=k&&!s3) ans=min(ans,s1);
		}
	}
	
	for(int i=1;i<=w;i++)
	{
		s1=s2=s3=0;
		for(int j=1,k1=1;j<=h;j++)
		{
			if(s[j][i]=='.') s1++;
			else if(s[j][i]=='o') s2++;
			else s3++;
			if(j>k)
			{
				if(s[j-k][i]=='.') s1--;
				else if(s[j-k][i]=='o') s2--;
				else s3--;
			}
			if(j>=k&&!s3) ans=min(ans,s1);
		}
	}
	
	if(ans==1e9) cout<<"-1";
	else cout<<ans;
}
