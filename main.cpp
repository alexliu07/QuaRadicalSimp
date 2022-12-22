//
// Created by liuyu on 2022/12/22.
//

#include <iostream>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int simp(int n) {
    int result = 1;
    if (isPrime(n)) {
        return result;
    }
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
    } else if (ans == 1) {
        cout << "sqrt(" << n << ")";
    } else {
        cout << ans << " sqrt(" << (n / ans / ans) << ")";
    }
    return 0;
}
