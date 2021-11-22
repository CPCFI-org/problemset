#include <bits/stdc++.h>
using namespace std;
int main() {
  int mod = 1e9+7;
  int n;
  scanf("%d",&n);
  vector<int> res(n+1,0);
  res[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6 && i-j >= 0; j++) {
      (res[i] += res[i-j]) %= mod;
    }
  }
  printf("%d\n",res[n]);
}
