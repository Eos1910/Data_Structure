#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cmath>
using namespace std;

//Initialise array with random data
void generateRandom(int a[], int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = rand() % SIZE; // generate value in range from 0 to SIZE-1 inclusive
    }
}

//Sort an array
void doSortedList(int a[], int SIZE)
{
    sort(a, a + SIZE); //sort array a using the range from a's first element address to a+SIZE address(last element)
}

//Implement binary search and Count at every midpoint visit
int findByBinSearch(int key, int a[], int SIZE)
{
    int low = 0;
    int high = SIZE - 1;
    int mid;
    int counter = 0;

    while (low <= high)
    {
        counter++;
        mid = (low + high) / 2;

        if (a[mid] < key)
            low = mid + 1;
        else if (a[mid] > key)
            high = mid - 1;
        else
            break;
    }
    if (a[mid] != key)
        return -1;
    else
        return counter;
}

//Implement sequential search and Count at every array-index visit
int findBySeqSearch(int key, int a[], int SIZE)
{
    int n = SIZE;
    int i;
    int counter = 0;
    for (i = 0; i < SIZE; i++)
    {
        counter++;
        if (a[i] == key)
        {
            break;
        }
        else if (i == n - 1)
        {
            return -1;
        }
    }
    return i + 1;
}

int main()
{
    srand(time(0));
    //long long int is used to store large values of SIZE
    long long int SIZE = 10;
    cout << "\nSize\t\tComplexity-Sequential\tComplexity-Binary\t\t(best/avg/worst)\n\t\t\t\t\t\t\t\tSeq. Cost\tBinary Cost\n\n";
    //Loop again to get different sizes.
    for (int i = 0; i < 8; i++)
    {
        int* a = new int[SIZE];
        generateRandom(a, SIZE);

        doSortedList(a, SIZE);
        int searchNum = rand() % SIZE;

        int sequence = findBySeqSearch(searchNum, a, SIZE);
        int binary = findByBinSearch(searchNum, a, SIZE);
        string scost, bcost;

        //Calculate sequence cost
        if (sequence == 1)
            scost = "best     ";
        else if (sequence == SIZE)
            scost = "worst    ";
        else if (sequence > 1 && sequence < SIZE)
            scost = "average  ";
        else
            scost = "not found";

        //Calculate binary cost
        if (binary == 1)
            bcost = "best     ";
        else if (binary == floor(log2(SIZE)) || binary == floor(log2(SIZE) + 1))
            bcost = "worst    ";
        else if (binary > 1 && binary < floor(log2(SIZE)))
            bcost = "average  ";
        else
            bcost = "not found";

        //Print out the values
        cout << SIZE << "\t\t\t" << sequence << "\t\t\t" << binary << "\t\t" << scost << "\t\t" << bcost << endl;
        SIZE = SIZE * 10;

        // Free dynamically allocated memory
        delete[] a;
    }
    return 0;
}
