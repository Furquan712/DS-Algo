//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        // Push all people onto the stack
        for (int i = 0; i < n; ++i) {
            s.push(i);
        }

        // Eliminate non-celebrities using the stack
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (M[a][b] == 1) {
                // If a knows b, 'a' cannot be a celebrity, but 'b' could be
                s.push(b);
            } else {
                // If a doesn't know b, 'b' cannot be a celebrity, but 'a' could be
                s.push(a);
            }
        }

        // Potential celebrity candidate
        int candidate = s.top();

        // Verify if the candidate is a celebrity
        for (int i = 0; i < n; ++i) {
            if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
                // Candidate knows someone else or someone doesn't know the candidate
                return -1; // No celebrity found
            }
        }

        return candidate;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends