#include <iostream>

using namespace std;


void isws(int* a, int n)
{
    int i, j, low, high, mid;
    for (i = 1; i < n; i++)
    {
        a[0] = a[i];
        low = 1; high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (a[mid] > a[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--)
        {
            a[j + 1] = a[j];
        }
        a[high + 1] = a[0];
    }
}

int main()
{
    int a[] = {-99, 38, 65, 97, 76, 13, 27, 49};
    isws(a, 7);
    for (int i = 1; i < 8; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}