#include<bits/stdc++.h>
using namespace std;

int dp[101][1001];

int knapsackRecursion(int val[], int wt[], int w, int n) {
    if (n==0 || w==0) {
        return 0;
    }

    if (wt[n-1] <= w) {
        //include
        int ans1 = val[n-1] + knapsackRecursion(val, wt, w-wt[n-1], n-1); 
        //exclude
        int ans2 = knapsackRecursion(val, wt, w, n-1);
        return max(ans1, ans2); 
    }
    else {
        // exclude
        return knapsackRecursion(val, wt, w, n-1);
    }
}

int knapsackDP(int val[], int wt[], int w, int n) {
    
    if (n==0 || w==0) {
        return 0;
    }

    if (dp[n][w] != -1){
        return dp[n][w];
    }

    if (wt[n-1] <= w) {
        //include
        int ans1 = val[n-1] + knapsackDP(val, wt, w-wt[n-1], n-1); 
        //exclude
        int ans2 = knapsackDP(val, wt, w, n-1);
        return dp[n][w] = max(ans1, ans2); 
    }
    else {
        // exclude
        return dp[n][w] = knapsackDP(val, wt, w, n-1);
    }
}

int knapsackTabulation(int val[], int wt[], int w, int n) {
    int dp1[n+1][w+1];

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=w; j++) {
            if ( i==0 || j==0 ) {
                dp1[i][j] = 0;
            }
            else if (wt[i-1] <= j) {
                dp1[i][j] = max(val[i-1] + dp1[i-1][j-wt[i-1]], dp1[i-1][j]  );
            }
            else {
                dp1[i][j] = dp1[i-1][j]; 
            }
        }
    }
    return dp1[n][w] ;
}

int main() {

    int n, W;
    cout<<"Enter the total number of Items : ";
    cin>>n;
    int wt[n];
    int val[n];
    for (int i=0; i<n; i++) {
        cout<<"Enter the Value and Weight fot Item "<<(i+1)<<" : ";
        cin>> val[i]>> wt[i];
    }
    cout<<"Enter the maximum weight capacity of the knapsack : ";
    cin>>W;

    int ans = knapsackRecursion(val, wt, W, n);
    cout<<"\nMaximum Value achievable in the knapsack : "<<ans<<endl<<endl;

    //int dp[n+1][W+1];
    memset(dp, -1, sizeof(dp));

    int ans1 = knapsackDP(val, wt, W, n);
    cout<<"\nMaximum Value achievable in the knapsack : "<<ans1<<endl<<endl;

    int max_value = knapsackTabulation(val, wt, W, n);
    cout << "\nMaximum Value achievable in the knapsack (Tabulation): " << max_value << endl;
    return 0;
}

/*
Enter the total number of Items : 5
Enter the Value and Weight fot Item 1 : 15
2
Enter the Value and Weight fot Item 2 : 14
5
Enter the Value and Weight fot Item 3 : 10
1
Enter the Value and Weight fot Item 4 : 45
3
Enter the Value and Weight fot Item 5 : 30
4
Enter the maximum weight capacity of the knapsack : 7

Maximum Value achievable in the knapsack : 75


Maximum Value achievable in the knapsack : 75


Maximum Value achievable in the knapsack (Tabulation): 75

*/
