#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int f[200010],ans;
void init()
{
	f[0]=1;
	f[1]=2;
	f[2]=3;
	for(int i=3;i<=200000;i++) f[i]=(f[i-1]+f[i-2])%P;
}
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	vector<string>p{{"mygo","m_ygo","my_go","myg_o","m_y_go","m_yg_o","my_g_o","m_y_g_o"}};
	for(int i=1;i<=n;i++)
	{
		for(auto j:p)
		if(i+j.size()-1<=n)
        {
            int fx=0;
            for(int k=0;k<j.size();k++) 
            if(j[k]!=s[k+i])
            {
                if(j[k]=='_') continue;
                fx=1;
                break;
            }
            if(!fx) ans=(ans+f[i-1]*f[n-(i+j.size()-1)]%P)%P;
        }
	}
	cout<<ans<<"\n";
//  mygo	
//	m_ygo
//	my_go
//	myg_o

//  m_y_go
//  m_yg_o
//  my_g_o
//  m_y_g_o
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
