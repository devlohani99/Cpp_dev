#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> arr, int n, int m, int mid) {
    int paintercount = 1;
    int wallcount = 0;
    for (int i = 0; i < n; i++) {
        if (wallcount + arr[i] <= mid) {
            wallcount += arr[i];
        } else {
            paintercount++;
            if (paintercount > m || arr[i] > mid) {
                return false;
            }
            wallcount = arr[i];
        }
        if (paintercount > m) {
            return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int s = 0;
    int sum = 0;
    int n = boards.size(); // Get size of vector boards
    for (int i = 0; i < n; i++) {
        sum += boards[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (check(boards, n, k, mid)) { // Pass boards, n, k, and mid as parameters to check function
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

