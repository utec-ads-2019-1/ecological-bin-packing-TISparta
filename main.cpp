#include <bits/stdc++.h>

using namespace std;

const string ORDER = "BGC";

int main () {
  vector <int> arr(9);
  while (cin >> arr[0]) {
    for (int i = 1; i < 9; i++) cin >> arr[i];
    string ans = "ZZZ";
    int mn = INT_MAX;
    for (int i = 0; i < 3; i++) {
      for (int j = 3; j < 6; j++) {
        for (int k = 6; k < 9; k++) {
          string tmp = "";
          tmp += ORDER[i % 3];
          tmp += ORDER[j % 3];
          tmp += ORDER[k % 3];
          set <char> st;
          for (char ch: tmp) st.insert(ch);
          if (int(st.size()) != 3) continue;
          int cost = accumulate(begin(arr), end(arr), 0) - arr[i] - arr[j] - arr[k];
          if (cost == mn) {
            if (tmp < ans) ans = tmp;
          } else if (cost < mn) {
            ans = tmp;
            mn = cost;
          }
        }
      }
    }
    cout << ans << ' ' << mn << endl;
  }
  return (0);
}
