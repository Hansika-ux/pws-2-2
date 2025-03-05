#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string stoneGame(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1, INT_MIN);  
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            for (int j = 0; j < 3 && i + j < n; j++) {
                sum += arr[i + j];
                dp[i] = max(dp[i], sum - dp[i + j + 1]); 
            }
        }

        if (dp[0] > 0) return "Alice";   
        if (dp[0] < 0) return "Bob";     
        return "Tie";                  
};

int main() {
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the stone values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
    cout << stoneGame(arr);
    return 0;
}
