#include <bits/stdc++.h>
using namespace std;
int n,j,k,ans,cnt[26],index[200010];
string s,t;
void solve()
{
	cin>>n>>s;
	t="";
	k=1;
	for(int i=0;i<26;i++) cnt[i]=0;
	for(int i=0;i<s.size();i++) index[i]=0;
	for(auto i:s) cnt[i-'a']++;
	j=25;
	while(cnt[j]==0) j--; 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==j+'a') 
		{
			index[k++]=i;
			t+=s[i];
			cnt[j]--;
			while(cnt[j]==0) j--; 
		}
		else cnt[s[i]-'a']--;
	}
	reverse(t.begin(),t.end());
	ans=0;
	for(int i=t.size()-2;i>=0;i--)
	{
		if(t[i]!=t[i+1]) 
		{
			ans=i+1;
			break;
		}
	}
	t=" "+t;
	for(int i=1;i<k;i++) s[index[i]]=t[i];
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]>s[i+1])
		{
			cout<<"-1\n";
			return ;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1; 
	while(t1--) solve();
}
