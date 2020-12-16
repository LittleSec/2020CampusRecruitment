#include <iostream>
#include <vector>

using namespace std;

vector<int> seqsum(int N, int L) {
    vector<int> res;
    for (int i = L; i <= 100; i++) {
        int mod = N % i;
        int div = N / i;
        if ((i & 0x1) == 0) {
            if (mod == 0) {
                continue;
            }
            else {
                int right = div + (i / 2);
                int left = div - (i / 2) + 1;
                if ((right+left)*(i/2) == N) {
                    while (left <= right) {
                        res.push_back(left);
                        left++;
                    }
                    return res;
                }
            }
        }
        else { // i & 0x1 == 1
            if (mod != 0) {
                continue;
            }
            else {
                int right = div + (i / 2);
                int left = div - (i / 2);
                if ((right+left)*(i/2)+div == N) {
                    while (left <= right) {
                        res.push_back(left);
                        left++;
                    }
                    return res;
                }
            }
        }
    }
    return res;
}

void display_vec(vector<int>& vec) {
    if (vec.empty()) {
        cout << "No";
    }
    else {
        for (int v : vec) {
            cout << v << " ";
        }
    }
    cout << endl;
}


int main() {
    int N, L;
    cin >> N >> L;
    vector<int> res = seqsum(N, L);
    display_vec(res);
    return 0;
}