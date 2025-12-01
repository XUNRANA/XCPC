#include <bits/stdc++.h>
using namespace std;
char a[11][11];
int ans;
void solve()
{
	ans=0;
	for(int i=1;i<=10;i++)
	for(int j=1;j<=10;j++) 
	{
		cin>>a[i][j];
		if(a[i][j]=='X') 
		{
			if(i==1||j==1||i==10||j==10) ans++;
			else if(i==2||j==2||i==9||j==9) ans+=2;
			else if(i==3||j==3||i==8||j==8) ans+=3;
			else if(i==4||j==4||i==7||j==7) ans+=4;
			else ans+=5;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
