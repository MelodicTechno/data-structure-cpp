#include <iostream>

using namespace std;

void shell(int* a, int n)
{
    int dk, i, j;
    for (dk = n / 2; dk >= 1; dk = dk / 2)
    {
        for (int i = dk + 1; i < n; i++)
        {
            if (a[i] < a[i - dk])
            {
                a[0] = a[i];
                for (j = i - dk; j > 0 && a[0] < a[j]; j -= dk)
                {
                    a[j + dk] = a[j];
                }
                a[j + dk] = a[0];
            }
        }
    }
}

int main()
{
    int a[] = {-99, 38, 65, 97, 76, 13, 27, 49};
    shell(a, 8);
    for (int i = 1; i < 8; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}