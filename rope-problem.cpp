#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int farthestHill(int n, vector<int>& heights, int ropes, int ladders) {
    priority_queue<int> maxHeap;  

    for (int i = 0; i < n - 1; i++) {
        int diff = heights[i + 1] - heights[i];

        if (diff > 0) {
            maxHeap.push(diff);  
            
            if (ropes >= diff) {
                ropes -= diff;  
            } else if (ladders > 0) {
                if (!maxHeap.empty()) {
                    ropes += maxHeap.top(); 
                    maxHeap.pop();
                }
                ladders--;  
                ropes -= diff;  
                if (ropes < 0) return i; 
            } else {
                return i; 
            }
        }
    }
    return n - 1;  
}

int main() {
    ifstream file("input4.txt");
    if (!file) {
        cout << "Could not open file." << endl;
        return 1;
    }

    int problemCount = 0;
    int n, ropes, ladders;

    while (file >> n) {  
        vector<int> heights(n);
        for (int i = 0; i < n; i++) file >> heights[i]; 

        file >> ropes >> ladders; 

        int result = farthestHill(n, heights, ropes, ladders);
        cout << "Problem " << ++problemCount << ": Farthest reachable hill = " << result << endl;
    }

    file.close();
    return 0;
}
