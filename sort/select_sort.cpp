#include <iostream>
#include <vector>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectSort(std::vector<int>& a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[min], a[i]);
        }
    }
}

int main()
{
    std::vector<int> a = {38, 65, 97, 76, 13, 27, 49};
    selectSort(a);
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}