#include <iostream>
#include <vector>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

#if 0
int binsearch(vector<int> &arr, int tgr) {
  if (arr.empty()) {
    return -1;
  }
  int l = 0, r = arr.size() - 1, m;
  while (l <= r) {
    m = (l + r) / 2;
    if (tgr < arr[m]) {
      r = m - 1;
    } else if (tgr > arr[m]) {
      l = m + 1;
    } else {
      return m;
    }
  }

  cout << "not found" << endl;
  return -1;
}
#endif

int binsearchleft(vector<int> &arr, int tgr) {
  if (arr.empty()) {
    return -1;
  }
  int l = 0, r = arr.size() - 1, m;
  while (l < r) {
    m = (l + r) / 2;
    if (tgr > arr[m]) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  if (arr[r] == tgr) {
    return r;
  }

  cout << "not found" << endl;
  return -1;
}

int main() {
  // struct node n1 = {1, nullptr, nullptr};
  // struct node n2 = {2, nullptr, nullptr};
  // struct node n3 = {3, nullptr, nullptr};
  // struct node n4 = {4, nullptr, nullptr};
  // struct node n5 = {5, nullptr, nullptr};
  // struct node n6 = {6, nullptr, nullptr};
  // struct node n7 = {7, nullptr, nullptr};
  // struct node n8 = {8, nullptr, nullptr};
  int n = 2, tmp, tgr;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    arr[i] = tmp;
  }
  cin >> tgr;
  cout << binsearchleft(arr, tgr) << endl;

  // while (1) {
  //   cin >> tgr;
  //   cout << binsearch(arr, tgr) << endl;
  // }

  return 0;
}
