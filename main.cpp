// Recursion

#include <iostream>
using namespace std;

// complexity: factorial of N (N!)
void permutation(int n, bool *num, int amount, int *arr)
{
    if (amount == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            num[i] = true;
            arr[amount] = i;
            amount++;

            permutation(n, num, amount, arr);
            num[i] = false;
            amount--;
        }
    }
}

void printInReverseOrder(int n)
{
    if (n == -1)
        return;
    cout << n << endl;
    printInReverseOrder(n - 1);
}

int main()
{
    int n;
    cin >> n;
    bool *num = new bool[n];
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        num[i] = false;
    }
    permutation(n, num, 0, arr);

    // printInReverseOrder(10);
    delete[] num;
    delete[] arr;
}
