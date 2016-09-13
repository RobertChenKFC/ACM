#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX = 1000005;

int main() {

    int n;
    int *arr = new int[MAX];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        if(i != 0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;

    delete[] arr;
}

