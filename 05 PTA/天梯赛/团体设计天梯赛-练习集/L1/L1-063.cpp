#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		int g,h,w;
		cin>>g>>h>>w;
		if(g)
		{
			if(h==130) cout<<"wan mei! ";
			else if(h>130) cout<<"ni li hai! ";
			else cout<<"duo chi yu! ";
			
			if(w==27) cout<<"wan mei!\n";
			else if(w>27) cout<<"shao chi rou!\n";
			else cout<<"duo chi rou!\n";
		}
		else
		{
			if(h==129) cout<<"wan mei! ";
			else if(h>129) cout<<"ni li hai! ";
			else cout<<"duo chi yu! ";
			
			if(w==25) cout<<"wan mei!\n";
			else if(w>25) cout<<"shao chi rou!\n";
			else cout<<"duo chi rou!\n";
		}
	}
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

