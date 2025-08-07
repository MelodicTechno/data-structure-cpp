#include <iostream>

using namespace std;

void insertSort(int* array, int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        if (array[i] < array[i - 1])
        {
            array[0] = array[i];
            for (j = i - 1; array[0] < array[j]; --j)
            {
                array[j + 1] = array[j];   
            }
            array[j + 1] = array[0];
        }
    }
}

int main()
{
    int a[] = {-99, 38, 65, 97, 76, 13, 27, 49};
    insertSort(a, 7);
    for (int i = 1; i < 8; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}