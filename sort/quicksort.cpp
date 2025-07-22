#include <iostream>
using namespace std;

void exchange(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* array, int p, int r)
{
    int pivot = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            exchange(array[i], array[j]);
        }
    }
    exchange(array[i + 1], array[r]);
    return i + 1;
}

void quicksort(int* array, int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quicksort(array, p,q - 1);
        quicksort(array, q + 1, r);
    }
}


int main()
{
    int a[] =  {1, 4, 6, 8, 2, 4, 9};
    quicksort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}