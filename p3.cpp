#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compareItems(Item a, Item b) {
    double a1 = (double) a.value / a.weight;
    double b1 = (double) b.value / b.weight;
    return a1>b1;
}
 
int fractionalKnapsack (int capacity, Item items[], int n) {
    sort (items, items+n, compareItems);

    double finalValue = 0;

    for (int i=0; i<n; i++) {
        if (capacity >= items[i].weight) {
            finalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            double fraction = (double)capacity / items[i].weight;
            finalValue += items[i].value * fraction;
            break;
        }
    }
    return finalValue;
}

int main() 
{
    int n, capacity;
    cout<<"Enter the total number of Items : ";
    cin>>n;

    Item items[n+1];

    for (int i=0; i<n; i++) {
        cout<<"Enter the Value and Weight fot Item "<<(i+1)<<" : ";
        cin>>items[i].value >>items[i].weight;
    }

    cout<<"Enter the maximum weight capacity of the knapsack : ";
    cin>>capacity;

    double ans = fractionalKnapsack(capacity, items, n);
    cout<<"\nMaximum Value achievable in the knapsack : "<<ans<<endl<<endl;
    return 0;

}

/*
Enter the total number of Items : 3
Enter the Value and Weight fot Item 1 : 60
10
Enter the Value and Weight fot Item 2 : 100
20
Enter the Value and Weight fot Item 3 : 120
30
Enter the maximum weight capacity of the knapsack : 50

Maximum Value achievable in the knapsack : 240
*/

