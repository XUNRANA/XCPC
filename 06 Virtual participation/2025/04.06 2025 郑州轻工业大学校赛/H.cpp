#include <bits/stdc++.h>
using namespace std;

int is(int y)
{
    return (y%4==0&&y%100!=0)||(y%400==0);
}
int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
map<int,int>mp;
void init()
{
    int cnt=1;
    int limit=20250406;
    for(int i=2000;i<=2025;i++)
    {
        for(int j=1;j<=12;j++)
        {
            for(int k=1;k<=m[j];k++)
            {
                if(i*10000+j*100+k<=limit) mp[i*10000+j*100+k]=cnt++;
            }
            if(j==2&&is(i))
            {
                if(i*10000+j*100+29<=limit) mp[i*10000+j*100+29]=cnt++;
            }
        }
    }
    // for(auto [i,j]:mp) cout<<i<<" "<<j<<"\n";
}
int fx(int x)
{
    int s=0;
    s+=x%100;
    x/=100;
    s+=x%100*60;
    x/=100;
    s+=x*60*60;
    return s;
}
void solve()
{
    string s1,s11,s2,s22;
    cin>>s1>>s2;
    for(auto i:s1) if(isdigit(i)) s11+=i;
    for(auto i:s2) if(isdigit(i)) s22+=i;
    int d1=stoi(s11.substr(0,8));
    int d2=stoi(s22.substr(0,8));
    int m1=stoi(s11.substr(8));
    int m2=stoi(s22.substr(8));
    // cout<<d1<<" "<<d2<<" "<<mp[d1]<<" "<<mp[d2]<<"\n";
    int d=(mp[d2]-mp[d1])*24*60*60+fx(m2)-fx(m1);
    // cout<<d<<" "<<8*60*60<<"\n";
    if(d>=8*60*60) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() 
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
