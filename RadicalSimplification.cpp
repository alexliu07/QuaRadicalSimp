//
// Created by liuyu on 2022/12/22.
//

#include <iostream>

using namespace std;

bool isEvenly(int a, int b, int times) {
    for (int i = 0; i < times; i++) {
        if (a % b != 0) {
            return false;
        }
        a /= b;
    }
    return true;
}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int simp(int n, int times) {
    int result = 1;
    if (isPrime(n)) {
        return result;
    }
    for (int i = 2; pow(i, times) <= n; i++) {
        if (isEvenly(n, i, times)) {
            result *= i;
            n = n / pow(i, times);
            result *= simp(n, times);
            break;
        }
    }
    return result;
}

int main() {
    int ans, n, x = 1, times;
    cout << "sqrt:";
    cin >> n;
    cout << "times:";
    cin >> times;
    ans = simp(n, times);
    if (pow(ans, times) == n) {
        cout << ans;
    } else if (ans == 1) {
        cout << "sqrt" << times << "(" << n << ")";
    } else {
        cout << ans << " sqrt" << times << "(" << (n / pow(ans, times)) << ")";
    }
    return 0;
}
