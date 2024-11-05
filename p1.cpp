#include<iostream>
using namespace std;

int fib_iterative(int n) {
    if (n==0 || n==1) {
        return n;
    }
    int fib0 = 0;
    int fib1 = 1;
    int fibN;

    for (int i=2; i<=n; i++) {
        fibN = fib0 + fib1;
        fib0= fib1;
        fib1 = fibN;
    }
    return fibN;
}

int fib_recursive(int n) {
    if (n==0 || n==1) {
        return n;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
}

int fib_dp(int n) {
    if (n<=1) {
        return n;
    }
    int dp[n+1];

    dp[0]=0;
    dp[1]=1;

    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() 
{
    int n, ch;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Print Fibonacci Series using Iteration\n";
        cout << "2. Print Fibonacci Series using Recursion\n";
        cout << "3. Print Fibonacci Series using DP\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch; 
        switch(ch) {
            case 1:
                cout<<"Enter the number of terms in the Fibonacci series: ";
                cin>>n;
                cout << "Fibonacci series using iteration: ";
                for (int i=0; i<n; i++)
                    cout<<fib_iterative(i)<<"\t";
                break;
            
            case 2:
                cout<<"Enter the number of terms in the Fibonacci series: ";
                cin>>n;
                cout << "Fibonacci series using recursion: ";
                for (int i=0; i<n; i++)
                    cout<<fib_recursive(i)<<"\t";
                break;

            case 3:
                cout<<"Enter the number of terms in the Fibonacci series: ";
                cin>>n;
                cout << "Fibonacci series using DP: ";
                for (int i=0; i<n; i++)
                    cout<<fib_dp(i)<<"\t";
                break;

            case 4:
                cout<<"Exiting the program..."<<endl;
                break;

            default:
                cout<<"Invalid choice! Please select again."<<endl;
                break;
        }
    }
    while (ch!=4);
}


// Fibonacci Series using Iteration and Recursion
// Iteration :
// Time Complexity = O(N)
// Space Complexity : O(1)

// Recursion :
// Time Complexity : O(1.618^N)
// Space Complexity : O(N) due to Auxilliary Stack Space
// Time Complexity is derived using Binet's Formula
// Time Complexity = 1/root(5)*[(1+root(5)/2)^n-(1-root(5)/2)^n]

// DP :
// Time Complexity = O(N)
// Space Complexity : O(1)

