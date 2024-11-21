#include <iostream>
#include <vector>

using namespace std;

// if v = 1 2 3, then prints (1,2,3)
void print(const vector<int>& v) {
    if (v.size() != 0) {
        cout << "(" << v[0];
        for (int i = 0; i < v.size(); ++i) {
            cout << "," << v[i];
        }
        cout << ")" << endl;
    }
}

void permutations(int pos, vector<int>& v, vector<bool>& used) {
    int n = v.size();

    if (pos == n) {
        print(v);
    }
    else {
        for (int j = 0; j < n; ++j) {
            if(!used[j]) {
                used[j] = true;
                v[pos] = j + 1;
                permutations(pos + 1, v, used);
                used[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> used(n, false);

    permutations(0, v, used);
    
    return 0;
}