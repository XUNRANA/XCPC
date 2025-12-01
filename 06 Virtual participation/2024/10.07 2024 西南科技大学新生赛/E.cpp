#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(string a,string b)
{
	if(a[0]==b[1]&&a[1]==b[0]) return 1;
	return 0;
}
int f[1500];
void init()
{
	for(int i=0;i<=23;i++)
	{
		for(int j=0;j<=59;j++)
		{
			string a;
			string b;
			if(i<10) a+='0',a+=i+'0';
			else a+='0'+i/10,a+='0'+i%10;
			
			if(j<10) b+='0',b+=j+'0';
			else b+='0'+j/10,b+='0'+j%10;
			
			if(ck(a,b)) f[i*60+j]=1;
		}
	}
}
void solve()
{
	string s;
	cin>>s;
	int sum=0,ans=0;
	sum+=s[4]-'0';
	sum+=(s[3]-'0')*10;
	sum+=(s[1]-'0'+(s[0]-'0')*10)*60;
	while(!f[sum])
	{
		sum++;
		sum%=1440;
		ans++;
	}
	printf("%02d:%02d\n%d\n",sum/60,sum%60,ans);
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
