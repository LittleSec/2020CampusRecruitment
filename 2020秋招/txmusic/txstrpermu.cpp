#include <iostream>
#include <string>

using namespace std;

void permutstr(string s, int i) {
  if (i == s.length()) {
    cout << s << endl;
  }
  for (int j = i; j < s.length(); j++) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
    permutstr(s, i + 1);
  }
}

int main() {
  string s;
  cin >> s;
  permutstr(s, 0);
}
