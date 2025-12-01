#include <iostream>
using namespace std;
int N, D, Z, I, jin, now, fu, fl;
string s, zero(200, '0');
int main() {
    cin >> N >> D;
    while (N--) {
        I = jin = fu = fl = 0;
        cin >> Z >> s;
        if (s[0] == '-') {
            fu = 1;
            s.erase(0, 1);
        }
        while (I < s.size() && s[I] != '.') ++I;
        if (I == s.size()) s = s + '.';
        s = s + zero;
        if (Z != 2) {
            if (Z == 1) s[I + D + 1] += 5;
            else {
                if (s[I + D + 1] >= '6') s[I + D]++;
                else if (s[I + D + 1] == '5') {
                    int flag = 0;
                    for (int i = I + D + 2; i < s.size(); i++) {
                        if(s[i] != '0') {
                            s[I + D]++;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0 && s[I + D] & 1) ++s[I + D];
                }
            }
            for (int i = I + D + 1; i >= 0; i--) {
                if (s[i] == '.') continue;
                now = s[i] - '0' + jin;
                s[i] = '0' + now % 10;
                jin = now / 10;
            }
        }
        if (jin) s = '1' + s, I++;
        if (fu) {
            for (int i = 0; i <= I + D; i++) {
                if (s[i] != '0' && s[i] != '.') fl = 1;
            }
        }
        if (fu && fl) cout << '-';
        cout << s.substr(0, I + D + 1) << "\n";
    }
    return 0;
}