#include <iostream>

using namespace std;

void reverse_arr_1(int arr[], int n)
{
    int i_max = n / 2 - 1;

    for (int i = 0, j = n - 1; i <= i_max; i++,j--)
        swap(arr[i], arr[j]);
}

//recursive
void reverse_arr3(int arr[], int start, int ends)
{
    if (start => ends) return;

    swap(arr[start], arr[ends]);
    reverse_arr3(arr, ++start, --ends);
}


void reverse_arr2(int arr[], int n)
{
    int start = 0;
    int ends = n - 1;

    while (start < ends)
    {
        int tmp = arr[start];
        arr[start] = arr[ends];
        arr[ends] = tmp;
        start++;
        ends--;
    }
}

int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    reverse_arr3(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
