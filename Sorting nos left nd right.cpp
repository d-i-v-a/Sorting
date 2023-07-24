#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    int* arr = new int[n];
    cout << "Enter the elements of the array: ";
    for(int k=0; k<n; k++)
    {
        cin>>arr[k];
    }
    
    int i=0, j=n - 1;

    while (i < j)
    {
        if ((arr[i]%2!=0)&&(arr[j]%2!=0))
        {
            i++;
            j--;
        }
        else if ((arr[i]%2==0)&&(arr[j]%2!=0))
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else if ((arr[i]%2!=0)&&(arr[j]%2==0))
        {
            i++;
            j--;
        }
        
    }

    cout << "Array: ";
    for (int k=0; k<n; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
