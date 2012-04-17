#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void swap(char& a, char& b)
{
 char temp = a;
 a = b;
 b = temp;
}


void partition(char s[], int left, int right, int pivot_index)
{
    int pivot = s[pivot_index];

    swap(s[left], s[pivot_index]);

   int low = left + 1 ;
   int high = right - 1;

    //Move from right until we hit something less thant the piovt; goes to the leftside
    //Move from left until we hit something greater than the pivot; goes to right side
    //while left pointer hasn't meet right pointer
    while(low < high)
    {
        if(s[high] > pivot) high--;//right > pivot, moving toward middle
        else if(s[low] < pivot) low++;//left < pivot, moving toward middle
        else//if both left and right cannot move, swap meanning both sides violate the pivot
        {
            swap(s[low], s[high]);
        }
    }

    swap(s[left],s[low]);
}

char* qSort(char s[], int left, int right)
{
    if(s == NULL)
    {
        return s; 
    }

    //for quick implmentation, i just pick the middle index as pivot
    if (left < right)
    {
        int pivot_index = (left + right)/2;
        partition(s, left, right , pivot_index);
        qSort(s, pivot_index+1,right);
        qSort(s, left, pivot_index-1);
    }
}

void main()
{
    char s[] = "abcde";
    cout<< s << endl;

    qSort(s, 0 , strlen(s) -1);

    cout << s << endl;

    cin.get();
}
