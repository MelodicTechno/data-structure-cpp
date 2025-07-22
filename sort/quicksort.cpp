#include <iostream>
#include <ctime>
#include <cstdlib>

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
    srand(static_cast<int>(time(0)));
    const int size = 1000;

    int ra[size];
    for (int i = 0; i < size; ++i)
    {
        ra[i] = rand() % 1000;
    }
    int a[] =  {1, 4, 6, 8, 2, 4, 9};
    quicksort(ra, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << ra[i] << ' ';
    }
    cout << endl;
}