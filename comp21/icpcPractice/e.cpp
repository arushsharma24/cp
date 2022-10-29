#include <bits/stdc++.h>
using namespace std;

int const M = 1e9 + 7;

int solve(vector<int> &A) {
  auto arr = A;
  const long long int M = 1e9 + 7;
  transform(arr.begin(), --arr.end(), ++arr.begin(), ++arr.begin(), [](auto &a, auto &b) {return a ^ b;});
  long long int res = 0;
  int n = (int) arr.size();
  for (auto &ele : arr) {
    res += ele;
    res %= M;
  }

  vector<int> bitset(32, 0);
  for (auto &ele : arr) {
    int i = 0; 
    while (ele) {
      bitset[i] += ele & 1;
      ele >>= 1;
      i++;
    }
  }

  for (int i = 0; i < 32; ++i) {
    long long int inc = bitset[i];
    inc *= (n - bitset[i]) % M;
    inc *= (1 << i) % M;
    res += inc;
    res %= M;
  }


  return res;
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ele : arr) 
      cin >> ele;
    cout << solve(arr) << endl;
  }
  return 0;
}
