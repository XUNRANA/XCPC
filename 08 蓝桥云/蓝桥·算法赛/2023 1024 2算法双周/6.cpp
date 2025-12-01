#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int dp[10][205];//dp[k][i]表示前i位所有数字之和的余数是k的个数 
string s;
int fx(int i,int is_l,int is_n,int op,int u)
{
	int n=s.size();// 获取字符串s的长度
	if(i==s.size()-1)// 如果当前已经处理到字符串的最后一位
	{
		if(is_n==0) return 0;// 如果is_n为0，表示当前还没有遇到非零的数字，返回0
		if(is_l&&op>s[i]-'0') return 0;// 如果当前位受到限制且op大于当前位的数字，则返回0
		return u%op==0;// 返回当前数字之和u是否能被op整除的判断结果
	}
	if(!is_l&&dp[u][i]>=0) return dp[u][i];// 如果不受限且dp数组中已有计算结果，则直接返回
	int res=0;
	int up=is_l? s[i]:'9';// 确定当前位的上界，如果受限则为s[i]，否则为'9'
	for(char c='0';c<=up;c++)// 遍历当前位可能的每个数字
	{
		// 递归调用fx函数，计算下一位的结果
		res+=fx(i+1,is_l&&c==up,is_n||c!='0',op,(u+c-'0')%op);
		res%=P;
	}
	if(!is_l&&is_n) dp[u][i]=res;// 如果不受限且已遇到非零数字，将计算结果存入dp数组
	return res;// 返回当前计算结果
}
int cau(string t)
{
	s=t;
	int res=0;
	for(int op=1;op<=9;op++)//枚举最后一位 
	{
		memset(dp,-1,sizeof(dp));
		res+=fx(0,1,0,op,0);
		res%=P;
	}
	return res;
}
void solve()
{
	string l,r;
	cin>>l>>r;
	int ans=cau(r);
	ans-=cau(l);
	int s=0;
	for(auto i:l) s+=i-'0';
	s-=l.back()-'0';
	if(l.back()!='0'&&s%(l.back()-'0')==0) ans++;
	ans=(ans%P+P)%P; 
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
