#include <stdio.h>
#include <iostream>
#include <vector>
#include<limits.h>

using namespace std;

int matrixChainMultiplication(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int > > dp(n, vector<int>(n, 0));
    
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices + 1: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the dimensions array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Minimum number of multiplications: " << matrixChainMultiplication(arr);
    return 0;
}
