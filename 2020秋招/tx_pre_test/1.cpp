#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, val;
  cin >> n >> k;
  vector<int> l(n - 1);
  for (int i = 0, j = 0; i < n; i++) {
    cin >> val;
    if (i + 1 != k) {
      l[j++] = val;
    }
  }
  for (auto a : l) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
