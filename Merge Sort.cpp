#include <iostream>
using namespace std;

int main()
{
    int A[5] = {2, 5, 13, 18, 23};
    int B[7] = {3, 8, 17, 28, 29, 30, 32};
    int m = 5, n = 7;
    int k = 0;
    int C[12];

    int i = 0, j = 0;
    while ((i < m) && (j < n))
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    if (i == m)
    {
        for (int l = j; l < n; l++)
        {
            C[k] = B[l];
            k++;
        }
    }
    else if (j == n)
    {
        for (int p = i; p < m; p++)
        {
            C[k] = A[p];
            k++;
        }
    }
    cout << "Array: ";
    for (int x = 0; x < m + n; x++)
    {
        cout << C[x] << " ";
    }
    cout << endl;
    return 0;
}

