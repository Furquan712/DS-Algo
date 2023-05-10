//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int maxFruits = 0;
    int left = 0;  // Left pointer of the sliding window
    unordered_map<int, int> fruitCount;  // Map to store the count of each fruit type

    for (int right = 0; right < fruits.size(); right++) {
        fruitCount[fruits[right]]++;  // Increment the count of the current fruit

        // Shrink the window if there are more than 2 types of fruits
        while (fruitCount.size() > 2) {
            fruitCount[fruits[left]]--;  // Decrement the count of the leftmost fruit
            if (fruitCount[fruits[left]] == 0) {
                fruitCount.erase(fruits[left]);  // Remove the leftmost fruit if its count becomes 0
            }
            left++;
        }

        // Update the maximum number of fruits
        maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends