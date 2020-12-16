#include <iostream>
#include <vector>

using namespace std;

unsigned long s(unsigned long x) {
  int ret = 0;
  while (x > 0) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

// unsigned long val(unsigned long x) {
//   unsigned long max = s(x), tmp;
//   if (x < 10) {
//     return max;
//   }
//   for (unsigned long i = 9; i < x; i += 10) {
//     tmp = s(i) + s(x - i);
//     if (tmp > max) {
//       max = tmp;
//     }
//   }
//   return max;
// }

unsigned long max9[] = {9ul,          99ul,          999ul,
                        9999ul,       99999ul,       999999ul,
                        9999999ul,    99999999ul,    999999999ul,
                        9999999999ul, 99999999999ul, 999999999999ul};

unsigned long val(unsigned long x) {
  if (x < 10) {
    return s(x);
  }
  int idx9 = 0;
  for (int i = 0; i < sizeof(max9) / sizeof(unsigned long); i++) {
    if (x < max9[i]) {
      idx9 = i;
      break;
    }
  }
  return 9 * idx9 + s(x - max9[idx9 - 1]);
}

int main() {
  int T;
  unsigned long n;
  cin >> T;
  // vector<unsigned long> arr(T);
  for (int i = 0; i < T; i++) {
    cin >> n;
    // arr[i] = n;
    cout << val(n) << endl;
  }
  // for (int i = 0; i < T; i++) {
  //   cout << val(arr[i]) << endl;
  // }
  return 0;
}
