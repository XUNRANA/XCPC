#include <bits/stdc++.h>
using namespace std;
int n,m;
int f(int x)
{
    if(x==1) return 12;
    else if(x==2) return 9;
    else if(x==3) return 7;
    else if(x==4) return 5;
    else if(x==5) return 4;
    else if(x<=7) return 3;
    else if(x<=10) return 2;
    else if(x<=15) return 1;
    else if(x<=20) return 0;
}
int c[21];
void solve()
{
    int n,x,y;
    cin>>n;
    while(n--)
    {
        for(int i=1;i<=20;i++)
        {
            cin>>x>>y;
            c[i]+=f(x)+y;
        }
    }
    for(int i=1;i<=20;i++) cout<<i<<" "<<c[i]<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
