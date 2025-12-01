#include <bits/stdc++.h>
using namespace std;
#define int long long

int fx(int x)
{
    vector<int>a;
    a.push_back(x%10);
    x/=10;
    a.push_back(x%10);
    x/=10;
    a.push_back(x%10);
    x/=10;
    a.push_back(x%10);
    vector<int>b=a;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
   
    int c=0,aa=0,bb=0;
    for(int i=0;i<4;i++) c+=pow(10,i)*(a[i]-b[i]);
    for(auto i:b) bb=bb*10+i;
    for(auto i:a) aa=aa*10+i;
    printf("%04d - %04d = %04d\n",bb,aa,c);
    return c;
}
void solve()
{
    int n;
    cin>>n;
    int t=fx(n);
    if(t!=n&&t!=0) 
    {
        n=t;
        while(1)
        {
            n=fx(n);
            if(n==6174) break;
        }
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

