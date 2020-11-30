#include <iostream>

using namespace std;

typedef struct pairs
{
    int max;
    int min;
} pairs;


pairs minmax(int arr[], int n)
{
    pairs mm;
    mm.max = arr[0];
    mm.min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mm.max)
            mm.max = arr[i];
        else if (arr[i] < mm.min)
            mm.min = arr[i];
    }
    return mm;
}

int max_(int arr[], int n)
{
    int max_ = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_) max_ = arr[i];
    return max_;
}

int min_(int arr[], int n)
{
    int min_ = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min_) min_ = arr[i];
    return min_;
}

void min_max(int arr[], int n)
{
    int min_ = arr[0];
    int max_ = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_)
            max_ = arr[i];
        else
            if (arr[i] < min_)
                min_ = arr[i];
    }

    cout << max_ << " " << min_ << endl;
}


//recursive
int rec_max(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    if (arr[n] > arr[n-1])
        swap(arr[n], arr[n-1]);
    return rec_max(arr, --n);
}


//tournament method or divide and conquer

pairs tour_mm(int arr[] ,int start, int ends)
{
    pairs mm;
    if (start == ends)
    {
        mm.max = arr[start];
        mm.min = arr[ends];
        return mm;
    }

    if (start == ends - 1)
    {
        if (arr[start] > arr[ends])
        {
            mm.max = arr[start];
            mm.min = arr[ends];
        }
        else
        {
            mm.max= arr[ends];
            mm.min = arr[start];
        }

        return mm;
    }

    int mid = (start + ends) / 2;
    pairs mml = tour_mm(arr, start, mid);
    pairs mmr = tour_mm(arr, mid + 1, ends);

    if (mml.max > mmr.max)
        mm.max = mml.max;
    else
        mm.max = mmr.max;


    if (mml.min < mmr.min)
        mm.min = mml.min;
    else
        mm.min = mmr.min;
    return mm;
}

int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    //cout << max_(arr, n) << endl;
    //cout << min_(arr, n) <<endl;
    //min_max(arr, n);
    //cout << rec_max(arr, --n);
    pairs mm = tour_mm(arr, 0, n - 1);
    cout << mm.max << " " << mm.min << endl;
}
