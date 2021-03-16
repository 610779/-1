#include <stdio.h>
#include <stdlib.h>
void printall(int a[], unsigned int b)
{
    printf("{");
    for (int i = 0; i < b; i++)
    {
        printf("%d", a[i]);
        if (i < b - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void selectionsort(int *data, unsigned int lenofdata, int show)
{
    for (int j = 0; j < lenofdata; j++)
    {
        int smallest = 10000000;
        int positionofsmallest = 0;
        for (int i = 0; i < lenofdata - j; i++)
        {
            if (data[i + j] < smallest)
            {
                smallest = data[i + j];
                positionofsmallest = (i + j);
            }
        }
        swap(&data[j], &data[positionofsmallest]);
        if (show)
        {
            printall(data, lenofdata);
        }
    }
}
void insertionsort(int *data, unsigned int lenofdata, int show)
{
    for (int j = 0; j != lenofdata; j++)
    {
        int key, j;
        //(如果第i向小於i-1 交換 如果)
        for (int i = 0; i < lenofdata; i++)
        {
            j = i - 1;
            key = data[i];
            while (j >= 0 && data[j] > key)
            {
                swap(&data[i], &data[j]);
                if (show)
                    printall(data, lenofdata);
            }
        }
    }
}
void bubblesort(int *data, unsigned int lenofdata, int show)
{
    for (int j = 0; j <= lenofdata; j++)
    {
        for (int i = 0; i <= lenofdata - j; i++)
        {
            while (data[i] > data[i + 1] && i + 1 < lenofdata)
            {
                swap(&data[i], &data[i + 1]);
                if (show)
                    printall(data, lenofdata);
            }
        }
    }
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int end = 1;
    while (end == 1)
    {
        //int data[]={0,1,2,3,4,5,6,7,8,9,10};
        int data[] = {10, 9, 5, 1, 2, 6, 8, 7, 4, 3, 0};
        size_t lenofdata = sizeof(data) / sizeof(data[1]);
        int whichsort = 0, showprocess = 0;
        printf("Original array\n");
        printall(data, lenofdata);
        printf("input \n1 : use selectionsort \n2 : use bubblesort \n3 : use insertionsort\n ");
        scanf("%d", &whichsort);
        printf("\nIf you want to see the procces, input 1 . Else input 0 : ");
        scanf("%d", &showprocess);
        printf("\n");
        //insertionsort(data, lenofdata, 1);
        if (whichsort == 1)
        {
            selectionsort(data, lenofdata, showprocess);
        }
        else if (whichsort == 2)
        {
            bubblesort(data, lenofdata, showprocess);
        }
        else if (whichsort == 3)
        {
            insertionsort(data, lenofdata, showprocess);
        }
        // qsort(data,lenofdata,sizeof(data[0]),compare);
        printall(data, lenofdata);
        printf("Input 0 to end the program. Input 1 to restart the program :");
        scanf("%d", &end);
    }
    return 0;
}