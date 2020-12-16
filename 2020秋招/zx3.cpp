/*
 * 快排第n趟排序结果
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#if 0
vector<vector<string> > groupAnagrams(string* strs, int strsLen) {
    // write code here
    vector<vector<string> > ans;
    unordered_map<string, vector<string> > ss2sl;
    for (int i = 0; i < strsLen; i++) {
        string tmp = strs[i];
        cout << "*****\n";
        cout << tmp << endl;
        sort(tmp.begin(), tmp.end());
        cout << tmp << endl;
        ss2sl[tmp].push_back(strs[i]);
    }
    for (auto &kv : ss2sl) {
        cout << kv.first << endl;
        ans.push_back(kv.second);
    }
    return ans;
}
#endif

void quickSort(int* array, int l, int r, int cur, int cnt) {
    if (l >= r) {
        return;
    }
    if (cur == cnt) {
        return;
    }
    int start = l, end = r, pivot = array[l];
    while (start < end) {
        while (start < end && array[end] >= pivot) {
            end--;
        }
        if (start < end) {
            array[start++] = array[end];
        }
        while (start < end && array[start] <= pivot) {
            start++;
        }
        if (start < end) {
            array[end--] = array[start];
        }
    }
    array[start] = pivot;
    quickSort(array, l, start-1, cur+1, cnt);
    quickSort(array, start+1, r, cur+1, cnt);
}

vector<int> nthResultOfQuickSort(int* array, int arrayLen, int n) {
    // write code here
    quickSort(array, 0, arrayLen-1, 0, n);
    vector<int> ans(array, array+arrayLen);
    return ans;
}

int main() {
    int n;
    cin >> n;
    int array[] = {42,35,63,96,56,11,17,42,88};
    auto ans = nthResultOfQuickSort(array, 9, n);
    cout << "=====\n";
    for (auto &a : ans) {
        cout << a <<  " \n";
    }
    return 0;
}
