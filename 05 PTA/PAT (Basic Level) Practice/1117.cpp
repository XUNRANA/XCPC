#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    return x*x*x;
}
int fx(int x)
{
    if(!x) return 0;
    int r=1;
    while(x)
    {
        r*=f(x%10);
        x/=10;
    }

    int s=0;
    while(r)
    {
        s+=r%10;
        r/=10;
    }
    return s;
}

void solve()
{
    int n1,n2;
    cin>>n1>>n2;
    
    if(n2<10)
    {
        cout<<"1\n";
        for(int i=n1;i<=n2;i++) cout<<i<<" \n"[i==n2];
        return ;
    }
    vector<int>a;
    for(int i=n1;i<=n2;i++) a.push_back(i);
    
    
    while(1)
    {
        vector<int>na;
        for(auto i:a)
        {
            int x=fx(i);
            na.push_back(x);
        }
        a=na;
        int f=0;
        for(auto i:na)
        {
            if(i>=10) f=1;
        }
        if(!f) break;
    }


    vector<int>vt(10,0);
    int mx=0;
    for(auto i:a) 
    {
        vt[i]++;
        mx=max(mx,vt[i]);
    }

    vector<int>ans;
    for(int i=0;i<10;i++) 
    if(mx==vt[i]) ans.push_back(i);
    

    cout<<mx<<"\n";
    int ff=0;
    for(auto i:ans)
    {
        if(ff) cout<<" ";
        cout<<i;
        ff=1;
    }
    cout<<"\n";
    
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
