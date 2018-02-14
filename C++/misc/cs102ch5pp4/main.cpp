#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

bool cmp(int a, int b, int& ct)
{
    ct++;
    return a > b;
}

int sort_partition(int arr[], int s, int f, int& pct)
{
    int left , right, fence;
    fence = arr[s];
    left = s+1;
    right = f;
    while( right > left )
    {
        while (cmp( arr[right], fence, pct)&& right >= left) right--;
        while(cmp(fence, arr[left], pct) && left < right) left++;
        if(right > left  )
        {
            swap(arr[left], arr[right]);
            right--;
        }
    }
    if (right > s && cmp(fence, arr[right] ,  pct))
    {
        arr[s] = arr[right];
        arr[right] = fence;
    }
    return right;
}

void quicksort (int arr[], int start, int finish, int& qct)
{
    int mid;
    if (finish <= start)
        return;
    mid = sort_partition(arr, start, finish, qct);
    quicksort(arr, start, mid - 1, qct);
    quicksort(arr, mid + 1, finish, qct);
    return;
}

void counter(int arr[])
{
    int uniquedigit[50], numunique[50], number;
    cout << "N" << "       Count" << endl;
    for (int i = 0; i < 49; i++)
    {
        number = 0;
        for (int j = 1; j < 50; j++)
            if (arr[i] == arr[j])
            {
                number++;
                uniquedigit[i] = arr[i];
                numunique[i] = number;
            }
    }
    for (int i = 0; i < 50; i++)
    {
        cout << uniquedigit[i] << "  " << numunique[i] << endl;
    }
}

int main()
{
    srand(time(0));
    int randvalues[50], count;
        for (int i = 0; i < 50; i++)
            randvalues[i] = rand() % 51;
    count = 0;
    quicksort(randvalues, 0, 49, count);
    counter(randvalues);
    return 0;
}
