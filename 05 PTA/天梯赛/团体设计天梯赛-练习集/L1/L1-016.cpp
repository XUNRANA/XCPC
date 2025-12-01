#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char z[]={'1','0','X','9','8','7','6','5','4','3','2'};
void solve()
{
	int n;
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int cnt=0;
		int f=0;
		for(int j=0;j<17;j++) 
		{
			if(isdigit(s[j])) cnt+=(s[j]-'0')*c[j];
			else
			{
				f=1;
				break;
			}
		}
		if(!f&&z[cnt%11]!=s.back()) f=1;
		if(f==1) cout<<s<<"\n";
		flag|=f;
	}
	if(!flag) cout<<"All passed\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

