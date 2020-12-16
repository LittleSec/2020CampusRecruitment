/*
 * input: [a,b,c,a,b,e,f,a,b,c]
 * output: [a1,b1,c1,a2,b2,e,f,a3,b3,c2]
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> &vec) {
    if (vec.empty()) {
        return {};
    }
    map<string, int> c2cnt;
    for (string& c : vec) {
        c2cnt[c]++;
    }
    vector<string> ans(vec.size());
    for (int i = vec.size()-1; i >= 0; i--) {
        string &c = vec[i];
        if (c2cnt[c] == -1) {
            ans[i] = c + "1";
            c2cnt[c] = 0;
        } else if (c2cnt[c] == 1) {
            ans[i] = c;
            c2cnt[c] = 0;
        } else {
            ans[i] = c + to_string(c2cnt[c]);
            c2cnt[c]--;
            if (c2cnt[c] == 1) {
                c2cnt[c] = -1;
            }
        }
    }
    return ans;
}

int main() {
    //int a;
    //cin >> a;
    vector<string> vec = {"a", "b", "c", "a", "b", "e", "f", "a", "b", "c"};
    vector<string> ans = solution(vec);
    for (auto s : ans) {
        cout << s << endl;
    }
    return 0;
}