#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL get(LL x){
    LL ans = 0, cnt =0;
    while(x && cnt < 4){
        ans += x % 9;
        x /= 9;
        cnt++;
    }
    return ans + x;
}
void solve() {
    LL s0, s1, n, ans = 1000000000;
    cin >> n;
    for (s0 = 0; s0 < n && s0 <= 100000; s0++){
        s1 = s0 + n;
        ans = min(ans, get(s1) + get(s0));
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
