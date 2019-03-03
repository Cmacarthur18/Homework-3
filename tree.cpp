//
//  main.cpp
//  tree.cpp
//
//  Created by Chet MacArthur on 2/10/19.
//  Copyright © 2019 Chet MacArthur. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cassert>

// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then for this value of a2     the function must return
//    10 20 40            1
//    10 40 30            2
//    20 10 40            0
//    50 40 30            3
int countIncludes(const double a1[], int n1, const double a2[], int n2)
{
    if(n2 <= 0 && n1 >= 0)
        return 1;
    if(n1 <= 0 && n2 >0 )
        return 0;
    
    if( a1[0]== a2[0]){
        int first = countIncludes(a1+1, n1-1, a2+1, n2-1); // goes through the first time with out ever callinf the second
        int second = countIncludes(a1+1, n1-1, a2, n2);
        return first + second;
    }
    
    return countIncludes(a1+1, n1-1, a2, n2);
    
}

// Exchange two doubles
void exchange(double& x, double& y)
{
    double t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is > divider come before all the other elements,
// and all the elements whose value is < divider come after all
// the other elements.  Upon return, firstNotGreater is set to the
// index of the first element in the rearranged array that is
// <= divider, or n if there is no such element, and firstLess is
// set to the index of the first element that is < divider, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotGreater, a[i] > divider
//   * for firstNotGreater <= i < firstLess, a[i] == divider
//   * for firstLess <= i < n, a[i] < divider
// All the elements > divider end up in no particular order.
// All the elements < divider end up in no particular order.
void divide(double a[], int n, double divider,
            int& firstNotGreater, int& firstLess)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotGreater <= firstUnknown and firstUnknown <= firstLess
    //  Every element earlier than position firstNotGreater is > divider
    //  Every element from position firstNotGreater to firstUnknown-1 is
    //    == divider
    //  Every element from firstUnknown to firstLess-1 is not known yet
    //  Every element at position firstLess or later is < divider
    
    firstNotGreater = 0;
    firstLess = n;
    int firstUnknown = 0;
    while (firstUnknown < firstLess)
    {
        if (a[firstUnknown] < divider)
        {
            firstLess--;
            exchange(a[firstUnknown], a[firstLess]);
        }
        else
        {
            if (a[firstUnknown] > divider)
            {
                exchange(a[firstNotGreater], a[firstUnknown]);
                firstNotGreater++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
// If n <= 1, do nothing.
void order(double a[], int n)
{
   if(n <= 1)
       return; // do noithing
    int firstNot;
    int firstLess;
    divide(a, n , a[n/2], firstNot, firstLess);
    order(a + firstLess, n - firstLess);
    order(a , firstNot);
}

int main(){

    const double a2[7] = {10,50,40,20,50,40,30};
    const double b[3] = {10,20,40};
    const double b1[3] = {10,40,30};
    const double b2[3] = {20,10,40};
    const double b3[3] = {50,40,30};
    assert(countIncludes(a2,7, b,3) == 1);
    assert(countIncludes(a2,7, b1,3) == 2);
    assert(countIncludes(a2,7, b2,3) == 0);
    assert(countIncludes(a2,7, b3,3)== 3);
    double a3[7] = {10,50,40,20,50,40,30};
    order(a3, 7);
    assert(a3[6] == 10);
    assert(a3[5] == 20);
    assert(a3[4] == 30);
    assert(a3[3] == 40);
    assert(a3[2] == 40);
    assert(a3[1] == 50);
    assert(a3[0] == 50);


    cout << "all tests passed" << endl;

}
