#include <bits/stdc++.h>
using namespace std;
string s, s1;
int sum[500005], k = 1, sum2;
char c;
int main() {
    freopen("melody.in", "r", stdin);
    freopen("melody.out", "w", stdout);
    cin >> s;
    if (s.size() <= 1)
        cout << "error";
    else if (s[0] != '|' || s[s.size() - 1] != '|')
        cout << "error";
    else {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '.' && s[i - 1] != '-') {
                cout << "error";
                return 0;
            }
            if (s[i] == '-' && (s[i - 1] == '.' || s[i - 1] == '|')) {
                cout << "error";
                return 0;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                sum[k] += sum2;
                for (int j = 1; j <= sum2; j++) s1 += c;
                c = s[i];
                sum2 = 1;
            } else if (s[i] == '-')
                sum2 *= 2;
            else if (s[i] == '.')
                sum2 *= 1.5;
            else if (s[i] == '|') {
                sum[k] += sum2;
                for (int j = 1; j <= sum2; j++) s1 += c;
                c = '\0';
                sum2 = 0;
                k++;
            }
        }
        bool flag = true;
        for (int i = 2; i <= k - 1; i++) {
            if (sum[i] != sum[i - 1])
                flag = false;
        }
        if (flag)
            cout << sum[1] << endl;
        else
            cout << -1 << endl;
        cout << s1;
    }
    return 0;
}