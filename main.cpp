//
// Created by liuyu on 2022/12/22.
//

#include <bits/stdc++.h>

using namespace std;

int simp(int n) {
    int result = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if ((n / i) % i == 0) {
                result *= i;
                n = n / i / i;
                result *= simp(n);
                break;
            }
        }
    }
    return result;
}

int main() {
    int ans, n, x = 1;
    cout << "sqrt:";
    cin >> n;
    ans = simp(n);
    if (ans * ans == n) {
        cout << ans;
    } else {
        cout << ans << " sqrt(" << (n / ans / ans) << ")";
    }
    return 0;
}
