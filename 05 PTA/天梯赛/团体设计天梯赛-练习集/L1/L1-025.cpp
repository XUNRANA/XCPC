#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b;
void solve()
{
	cin>>a;
	getline(cin,b);
	int sa=0,sb=0,fa=0,fb=0;
	for(auto i:a) 
	{
		if(i-'0'<0||i-'0'>9) 
		{
			fa=1;
			break;
		}
		sa=sa*10+i-'0';
	}
	
	b=b.substr(1);
	for(auto i:b)
	{
		if(i-'0'<0||i-'0'>9) 
		{
			fb=1;
			break;
		}
		sb=sb*10+i-'0';
	}
	if(sa<1||sa>1000) fa=1;
	if(sb<1||sb>1000) fb=1;
	if(fa&&fb) printf("? + ? = ?\n");
	else if(fa) printf("? + %d = ?\n",sb);
	else if(fb) printf("%d + ? = ?\n",sa);
	else printf("%d + %d = %d\n",sa,sb,sa+sb);
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

