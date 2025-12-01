#include <bits/stdc++.h>
using namespace std;
int y1,n,y2,s[100010],cnt;
void solve()
{
	cnt=0;
	cin>>y1>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	cin>>y2;
	for(int i=1;i<=n;i++)
	{
		if(s[i]<y2) cnt++;
		else break;
	} 
	cout<<y2-y1+1-cnt<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();  
}
