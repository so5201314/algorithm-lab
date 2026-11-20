#include <stdio.h>

// 删除数组中的零元素，并返回新的有效长度
int CompactIntegers(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            a[count] = a[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int count = CompactIntegers(a, n);
    printf("%d\n", count);

    for (int i = 0; i < count; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
