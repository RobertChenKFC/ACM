#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 100;
const int MAX = 10005;

int main() {
    int pack[SIZE + 1] = {};
    int val[MAX], vol[MAX];

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> vol[i] >> val[i];

    for(int i = 0; i < n; i++) {
        for(int j = SIZE; j >= vol[i]; j--) {
            if(pack[j - vol[i]] + val[i] > pack[j])
                pack[j] = pack[j - vol[i]] + val[i];
        }
    }

    cout << pack[SIZE] << endl;
}
