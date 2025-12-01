#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
string eq, s; //方程字符串和颜色字符串 
vector<string> res; //用来存结果 
int nums[15] {0}; //用来存被P标记过的数字出现次数 
int fg[15][15] {0}; //fg[i][j], 表示i位置上是否可以出现j，可以值为0，不可以则为1 
int Gfg[15], Bfg[15];//Gfg[i]表示i位置上数字是否被G标记，Bfg[i]表示i位置上数字是否被B标记，标记为1否则为0 
void dfs(int now, string ans) //dfs遍历每一种可能，now表示当前位置，ans表示方程 
{
	if(Gfg[now]) //当该位置被G给标记时 
	{
		dfs(now+1, ans+eq[now]); //方程该位置上直接放上给定方程位置上的数
		return; 
	}
	if(now==eq.size()) //当该方程此处遍历完成时 
	{
		for(int i=0; i<=9; i++) //如果存在P标记的数没有用完，该方程不合格，直接返回 
			if(nums[i])
				return; 
		int a = (ans[0]-'0')*10+ans[1]-'0', b = (ans[3]-'0')*10+ans[4], c = (ans[6]-'0')*10+ans[7]; //计算方程式结果 
		if(a+b!=c) return; //方程式结果不匹配，返回 
		res.push_back(ans); //存入该方程答案 
		return;
	}
	for(int i=0; i<=9; i++) //遍历0~9的 
	{
		if(fg[now][i]  || Bfg[i] && !nums[i]) continue; //当该位置不能出现这个数，或者该数被B标记时，跳过 
		else
		{
			if(nums[i]) //如果该数是被P标记 
			{
				nums[i] --;
				dfs(now+1, ans+char(i+'0'));
				nums[i] ++;
			}
			else dfs(now+1, ans+char(i+'0'));
		}
	}
}
void solve()
{
	cin >> eq >> s;
	for(int i=0; i<eq.size(); i++)
	{
		if(s[i]=='P')
			nums[eq[i]-'0'] ++, fg[i][eq[i]-'0'] = 1;
		else if(s[i]=='B')
			fg[i][eq[i]-'0'] = 1, Bfg[eq[i]-'0'] = 1;
		else if(s[i]=='G')
			Gfg[i] = 1;
	}
	dfs(0, "");
	cout << res.size();
	puts("");
	for(int i=0; i<res.size(); i++)
		cout << res[i] << "\n"; 
}

signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
