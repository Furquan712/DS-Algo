//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
   int findPlatform(int arr[], int dep[], int n) {
        // Sort the arrival and departure times in ascending order.
        sort(arr, arr + n);
        sort(dep, dep + n);

        int platforms = 0;
        int maxPlatforms = 0;
        int i = 0; // Pointer for the arrival array
        int j = 0; // Pointer for the departure array

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                // If a train arrives before another departs,
                // we need an extra platform.
                platforms++;
                i++;
            } else {
                // If a train departs before another arrives,
                // we can free up one platform.
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }

        // If there are still trains arriving but no more departures,
        // we need to consider the remaining trains.
        while (i < n) {
            platforms++;
            i++;
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends