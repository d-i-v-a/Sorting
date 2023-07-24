#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int arr[8]={8, 5, 9, 6, 4, 2, 8, 3};
    //display array
    cout << "Array: ";
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 7; i += 2)
    {
        swap(&arr[i], &arr[i + 1]);
    }
    
    //display after swapping
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
