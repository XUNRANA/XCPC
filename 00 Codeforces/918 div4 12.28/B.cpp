#include <bits/stdc++.h>
using namespace std;
int t;
string str[4];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>str[1]>>str[2]>>str[3];
		for(int i=1;i<=3;i++)
		sort(str[i].begin(),str[i].end());
		int i;
		for(i=1;i<=3;i++) if(str[i][0]=='?') break;
		int a[3];
		for(int j=0;j<3;j++) a[j]=0;
		for(int j=1;j<3;j++) a[str[i][j]-'A']++;
		for(int j=0;j<3;j++) if(a[j]==0) cout<<char(65+j)<<"\n";
	}
}
