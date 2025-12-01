#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
char ch;
void print(int i,int j)
{
    while(i--) cout<<" ";
    while(j--) cout<<ch;
    cout<<"\n";
}
void fy1(int i,int j,int x)
{
    if(i-1+j+2<=x) fy1(i-1,j+2,x);
    print(i,j);
}
void fy2(int i,int j,int x)
{
    print(i,j);
    if(i-1+j+2<=x) fy2(i-1,j+2,x);
}
void fx(int cnt)
{
    if(cnt-1-1>=0) fy1(cnt-1-1,3,2*cnt-1);
    print(cnt-1,1);
    if(cnt-1-1>=0) fy2(cnt-1-1,3,2*cnt-1);
}
vector<int>a;
void solve()
{
    int sum=1;
    int j=3;
    while(sum<=1000) 
    {
        a.push_back(sum);
        sum+=2*j;
        j+=2;
    }
    cin>>n>>ch;
    int cnt=upper_bound(a.begin(),a.end(),n)-a.begin();
    fx(cnt);
    cout<<n-a[cnt-1]<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

