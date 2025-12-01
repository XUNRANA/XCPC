#include <bits/stdc++.h>
using namespace std;
const int P = 1e9+7, K = 3200;
string s;

#define int long long
typedef pair<int, int> Vec;
#define fi first
#define se second
Vec F0 = {0, 1};

struct Matrix {
    int dat[2][2] = {{0, 0}, {0, 0}};
    Matrix* p1 = nullptr;
    Matrix* p2 = nullptr;

    void init() {
        p1 = new Matrix[K], p2 = new Matrix[K];
        p1[0].dat[0][0] = p1[0].dat[1][1] = 1;
        p1[0].dat[0][1] = p1[0].dat[1][0] = 0;
        for (int i = 1; i < K; i++) p1[i] = p1[i-1] * *this;
        p2[0] = p1[0];
        p2[1] = p1[K-1] * *this;
        for (int i = 2; i < K; i++) p2[i] = p2[1] * p2[i-1];
    }

    Matrix power(int k) {
        return p1[k % K] * p2[k / K];
    }

    Matrix operator*(const Matrix& mat) const {
        Matrix res;
        res.dat[0][0] = (dat[0][0] * mat.dat[0][0] + dat[0][1] * mat.dat[1][0]) % P;
        res.dat[0][1] = (dat[0][0] * mat.dat[0][1] + dat[0][1] * mat.dat[1][1]) % P;
        res.dat[1][0] = (dat[1][0] * mat.dat[0][0] + dat[1][1] * mat.dat[1][0]) % P;
        res.dat[1][1] = (dat[1][0] * mat.dat[0][1] + dat[1][1] * mat.dat[1][1]) % P;
        return res;
    }

    Matrix operator+(const Matrix& mat) const {
        Matrix res;
        res.dat[0][0] = (dat[0][0] + mat.dat[0][0]) % P;
        res.dat[0][1] =(dat[0][1] + mat.dat[0][1]) % P;
        res.dat[1][0] =(dat[1][0] + mat.dat[1][0]) % P;
        res.dat[1][1] =(dat[1][1] + mat.dat[1][1]) % P;
        return res;
    }

    Vec operator*(const Vec& f) {
        return {(dat[0][0] * f.fi + dat[0][1] * f.se) % P, (dat[1][0] * f.fi + dat[1][1] * f.se) % P};
    }
} APE, A;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int n = s.size();

    A.dat[0][0] = A.dat[0][1] = A.dat[1][0] = 1;
    A.dat[1][1] = 0;
    APE.dat[0][0] = 2;
    APE.dat[0][1] = APE.dat[1][0] = APE.dat[1][1] = 1;

    APE.init();
    A.init();

    int m = 0, k = n, res = 0;
    for (int i = 0; i < n; i++) {
        k--;
        if (s[i] == '0') continue;
        res = (res + (APE.power(k) * A.power(m) * F0).fi) % P;
        m++;
    }
    cout << (res + (A.power(m) * F0).fi) % P << endl;
    return 0;
}
