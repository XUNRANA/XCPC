#include <bits/stdc++.h>
using namespace std;
#define int long long
long long f[35][35][35]; 
vector<int> bits;
int K;
long long dfs(int pos, int cnt, int len, bool limit, bool lead)
{
    if(pos<0) return len>0&&(len+cnt-1>K);
    if(!limit&&!lead&&f[pos][cnt][len]!=-1) return f[pos][cnt][len];
    long long res=0;
    int up=limit ? bits[pos]:1;
    for(int i=0;i<=up;i++)
    {
        int n_len=len;
        if(lead)
        {
            if(i==1) n_len=pos+1;
            else n_len=0;
        }
        res+=dfs(pos-1, cnt+(i==1),n_len,limit&&(i==up),lead&&(i==0));
    }
    if(!limit&&!lead) f[pos][cnt][len]=res;
    return res;
}

void solve()
{
    int n;
    cin>>n>>K;
    bits.clear();
    int temp=n;
    while(temp)
    {
        bits.push_back(temp&1);
        temp>>=1;
    }
    memset(f,-1,sizeof(f));
    cout<<dfs(bits.size()-1,0,0,1,1)<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T; 
    while(T--) solve();
}