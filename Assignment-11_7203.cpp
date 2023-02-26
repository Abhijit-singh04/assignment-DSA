#include <bits/stdc++.h>
using namespace std;

int sum(int frequency[], int i, int j)
{
    int sum = 0;
    for (int x = i; x <= j; x++)
        sum += frequency[x];
    return sum;
}

int optimalCost(int frequency[], int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return frequency[i];

    int frequencySum = sum(frequency, i, j);

    int min = INT_MAX;

    for (int r = i; r <= j; ++r)
    {
        int cost = optimalCost(frequency, i, r - 1) + optimalCost(frequency, r + 1, j);
        if (cost < min)
            min = cost;
    }

    return min + frequencySum;
}

int optimalSearchTree(int keys[], int frequency[], int n)
{
    return optimalCost(frequency, 0, n - 1);
}

int main()
{
    int n;
    int *key;
    int *probability;
    bool flag =true;
    while(flag){
    cout<<"--------MENU----------\n";
    cout<<"1.Enter the keys\n";
    cout<<"2.Enter the probability for keys\n";
    cout<<"3.Getting the optimal cost of binary tree\n";
    cout<<"4.Exit\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:{
            cout<<"Enter the number of keys\n";
            cin>>n;
            key = new int[n];
            cout<<"Enter the keys\n";
            for(int i=0;i<n;i++){
                cin>>key[i];
            }
            break;
        }
        case 2:{
            probability = new int[n];
            for(int i=0;i<n;i++){
                cin>>probability[i];
            }
            break;
        }
        case 3:{
            cout << "Cost of Optimal BST is " << optimalSearchTree(key, probability, n);
            cout<<"\n";
            break;
        }
        case 4:{
            flag = false;
            cout<<"Thank you\n";
            break;
        }
        default :{
            cout<<"Enter the correct input\n";
            break;
        }
    }
    }
    return 0;
}