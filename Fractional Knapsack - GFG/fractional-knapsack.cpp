//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(Item a, Item b)
    {
        double v1 = (double)a.value / (double)a.weight;
        double v2 = (double)b.value / (double)b.weight;

        return v1 > v2;
    }

    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        int curr = 0;
        double ans = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight + curr <= w)
            {
                curr += arr[i].weight;
                ans += arr[i].value;
            }
            else
            {
                int remain = w - curr;
                ans += ((double)arr[i].value / (double)arr[i].weight) * remain;
                break;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends