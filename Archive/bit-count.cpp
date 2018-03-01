#include <bits/stdc++.h>
using namespace std;

int bitcount(int x) {
    int cnt = 0;
    for (; x; x = x&(x-1)) ++cnt;
    return cnt;
}
int main() {
    int x;
    cin >> x;
    cout << bitcount(x) << "\n";
    return 0;
}
