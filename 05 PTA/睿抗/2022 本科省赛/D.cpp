#include <iostream>
#include <bitset>
using namespace std;
const int N = 15;
int cnt[N];//第i个队伍的人数 
int s[N];//第i个队伍的特殊值 
bitset<6> ans;
int tj[N];//第i个条件是否满足或者具体值
string vrank;
string ansrank = "11111111111111111";
void turn(bitset<6>v, int vtj[]) { //改变为最优解
	ans = v;
	for (int i = 0;i < 8;i++) { //这个方案是一个最优解 
		tj[i] = vtj[i];
	}
	ansrank = vrank;
	return;
}
void judge(bitset<6> v) 
{
	int vtj[8] = { 0,0,0,0,0,0,0,0 };
	int sp[2] = { 0,0 };
	int c[2] = { 0,0 };//0 /1 队伍人数
	vrank = "";
	string vv = v.to_string();
	for (int i = 0;i < vv.size();i++) {
		int id = vv[i] - '0';
		sp[id] |= s[i + 1];
		c[id] += cnt[i + 1];
		if (id == 0)vrank += (i + 1 + '0');
	}
	vtj[2] = (sp[0] >= 4) && (sp[1] >= 4);
	vtj[3] = (sp[0] == 3 || sp[0] == 7) && (sp[1] == 3 || sp[1] == 7);
	vtj[4] = (sp[0] & 1) && (sp[1] & 1);
	vtj[5] = -1 * abs(c[0] - c[1]);
	vtj[6] = (c[0] >= c[1]);
	for (int i = 2;i <= 6;i++) {
		if (tj[i] == vtj[i])continue;
		if (vtj[i] > tj[i])turn(v, vtj);
		else return;
	}
	if (vrank < ansrank) { //比较0队的字典序
		turn(v, vtj);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n = 6;
	for (int i = 1;i <= n;i++)cin >> cnt[i];
	for (int i = 1;i <= n;i++) {
		char x, y, z;
		cin >> x >> y >> z;
		s[i] += z - '0';
		s[i] += (y - '0') * 2;
		s[i] += (x - '0') * 4;
	}
	for (int i = 1;i < 63;i++) {
		bitset<6> v(i);
		judge(v);
	}
	if (!tj[2])
    {  //当第2个条件不满足时，不行。
		cout << "GG\n";
		return 0;
	}
	string posans = ans.to_string();//用于定位
	int ok = 0;
	for (int i = 0;i < posans.size();i++) {
		if (posans[i] == '0' && cnt[i + 1] > 0) {
			if (ok)cout << " ";
			ok = 1;
			cout << i + 1;
		}
	}
	cout << "\n";
	ok = 0;
	for (int i = 0;i < posans.size();i++) {
		if (posans[i] == '1'&&cnt[i+1]>0) {
			if (ok)cout << " ";
			ok = 1;
			cout << i + 1;
		}
	}
	return 0;
}