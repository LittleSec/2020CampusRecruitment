/*
 * 给出一个数数组，打印数组内元素 的全排列
 */

#include <iostream>
#include <vector>

using namespace std;

void myswap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void printVec(vector<int> &vec) {
    for (int v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

void dfsPer(vector<int> &vec, int k) {
    if (k == vec.size()) {
        printVec(vec);
        return;
    }
    for (int i = k; i < vec.size(); i++) {
        myswap(vec[k], vec[i]);
        dfsPer(vec, k+1);
        myswap(vec[i], vec[k]);
    }
}

int main() {
    //int a;
    //cin >> a;
    vector<int> arr = {1,2,3};
    dfsPer(arr, 0);
    cout << "Hello World!" << endl;
}
