#include <bits/stdc++.h>
using namespace std;
#define int long long
string pi = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
//vector<pair<string,char>
// a-b  都是从小到大 最低位在 0 sub 返回是 abs值
// 初始 a > b 末尾都补 $10^2$ 个 0
string sub(string a, string b) 
{
    string ans;
    if (a.size() < b.size())
        swap(a, b);
    else if (a.size() == b.size()) {
        int len = a.size();
        for (int i = len - 1; i >= 0; i--) {
            if (a[i] > b[i]) {
                break;
            } else if (a[i] == b[i]);
            else {
                swap(a, b);
                break;
            }
        }
    }
    int lenb = b.size();
    for (int i = 0; i < lenb; i++) 
	{
        int A = a[i] - '0';
        int B = b[i] - '0';
        if (A - B < 0) {
            a[i + 1] -= 1;
            // 要注意不能直接 + 因为可能爆char 直接被这个东西卡过
            // -1 不会
            ans.push_back((char) (A - B + 10 + '0'));
        } else
            ans.push_back((char) (A - B + '0'));
    }
    int lena = a.size();
    // 最后一位要判断一下是否还存在
    for (int i = lenb; i < lena; i++) {
        if (a[i] < '0') {
            a[i + 1] -= 1;
            ans.push_back((char) (a[i] + 10));
        } else
            ans.push_back(a[i]);
    }
    while (--lena) {
        if (ans[lena] == '0')
            ans.pop_back();
        else
            break;
    }

    return ans;
}

int cmp(string a, string b) // a>b:1 a<b:0 a==b :2
{
    if (a.size() < b.size())
        return 0;
    else if (a.size() == b.size()) {
        int len = a.size();

        for (int i = len - 1; i >= 0; i--) {
            if (a[i] > b[i])
                return 1;
            else if (a[i] == b[i]);
            else
                return 0;
        }
        return 2;
    }
    return 1;
}

void solve() 
{
    for (int i = 0; i < 60; i++)
        pi.pop_back();
    // reverse 使得数位低的在数组低的
    reverse(pi.begin(), pi.end());


    // 处理数据 要 ×10^{40} 或者先除法，然后余数慢慢加入
    int n;
    cin >> n;
    string mi = "00000000000000000000000000000000000000000000000000000000000000000001";
    int ansa = 0, ansb = 0;

    for (int i = 1; i <= n; i++) {
        int p, q;
        cin >> p >> q;
        string a; //

        a = to_string(p / q);
        int res = p % q;
        for (int j = 0; j < 40; j++) {
            res = res * 10;
            a.push_back((char) (res / q + '0'));
            res %= q;
        }
        //cout<<a.size()<<endl;


        reverse(a.begin(), a.end());
        string c = sub(a, pi);
        //cout<<c.size()<<endl;
        int now = cmp(mi, c);
        if (now == 2 && ansa > p) {
            ansa = p;
            ansb = q;
            mi = c;
        } else if (now == 1) {
            ansa = p;
            ansb = q;
            mi = c;
        }
    }
    cout << ansa << ' ' << ansb << endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
