#include <bits/stdc++.h>
using namespace std;
int n,x,k,a[100010];
void solve()
{
    cin>>n>>x>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    priority_queue<int,vector<int>,less<int>>q;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s+=a[i];
        q.push(a[i]);
        while(s>=x&&k)
        {
            s-=q.top();
            q.pop();
            k--;
        }
        if(s>=x&&!k) 
        {
            cout<<i-1<<"\n";
            return ;
        }
    }
    cout<<n<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
