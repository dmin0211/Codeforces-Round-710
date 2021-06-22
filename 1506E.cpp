#include <iostream>
#include <vector>
#include <set>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FIO;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, temp;
        cin >> n;
        vector<int> miv, mav, input_arr;
        set<int> s;
        bool tmp[n], visit[n];
        for (int j = 0; j < n; ++j) {
            tmp[j] = false;
            visit[j] = false;
        }
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            input_arr.push_back(temp - 1);
            if (!tmp[temp - 1]) {
                tmp[temp - 1] = true;
                visit[j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!tmp[j])
                s.insert(j);

        }
        for (int j = 0; j < n; ++j) {
            if (visit[j]) mav.push_back(input_arr[j] + 1);
            else {
                auto it = s.upper_bound(input_arr[j]);
                it--;
                mav.push_back((*it) + 1);
                s.erase(it);
            }
        }
        s.clear();
        for (int j = 0; j < n; ++j) {
            if (!tmp[j])
                s.insert(j);
        }
        for (int j = 0; j < n; ++j) {
            if (visit[j]) miv.push_back(input_arr[j] + 1);
            else {
                miv.push_back((*s.begin()) + 1);
                s.erase(s.begin());
            }
        }
        for (int j = 0; j < miv.size(); ++j) {
            cout << miv[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < mav.size(); ++j) {
            cout << mav[j] << " ";
        }
        cout << endl;
    }
}
