//
//  main.cpp
//  linear.cpp
//
//  Created by Chet MacArthur on 2/7/19.
//  Copyright © 2019 Chet MacArthur. All rights reserved.
//


#include <iostream>
#include <cassert>
using namespace std;
bool somePredicate(double x)
{
    return x < -9;
}

// Return true if the somePredicate function returns true for at
// least one of the array elements, false otherwise.
bool anyTrue(const double a[], int n)
{
    
    if( n<= 0)
        return false;
    if(somePredicate(a[0]))
        return true;
    return anyTrue(a+1, n-1);
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns true.  If there is no such
// element, return -1.
int firstTrue(const double a[], int n)
{
    
    if( n <= 0)
        return -1;
    if(somePredicate(a[0]) || n ==1)
        return 0;
    else{
        int first= 1+ firstTrue(a+1, n-1);
        return first;
    }
    
    
}

// Return the number of elements in the array for which the
// somePredicate function returns true.
int countTrue(const double a[], int n)
{
    if(n<= 0)
        return 0;
    
    if(somePredicate(a[0])){
        int somePred = 1+countTrue(a+1, n-1);
        return somePred;
    }
    else{
        int notPred = countTrue(a+1, n-1);
        return notPred;
    }
}

// Return the subscript of the smallest element in the array (i.e.,
// return the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the function is told to examine no
// elements, return -1.
int positionOfMin(const double a[], int n)
{
    if(n <= 0)
        return -1;
    if(n==1)
        return 0;
    int r = 1+positionOfMin(a+1, n-1);
    if(a[0] <= a[r] )
        return 0;
    else
        return r;
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a2 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a2 is
//    50 30 20
// or
//    10 20 20
bool includes(const double a1[], int n1, const double a2[], int n2)
{
    if(n2 <1 && n1>=0)
        return true;
    if(n1 <1 && n2 > 0)
        return false;

    if(a1[0] == a2[0])
        return includes(a1+1 , n1-1, a2+1, n2-1);
    else
        return includes(a1+1, n1-1, a2, n2);
}




int main(){
//
//    const double a[8] = {2,1,5,0,3,6,-1,8};
//    assert(anyTrue(a , 8));
//    //assert(countTrue(a,8) == 3);
//    assert(firstTrue(a, 8) == 5);
//    assert(positionOfMin(a, 8)==6);
//    const double a1[8] = {5,5,5,5,5,5,5,1};
//    assert(!anyTrue(a1 , 8));
//    assert(positionOfMin(a1, 8)==7);
//    assert(countTrue(a1,8) == 0);
//    const double a3[8] = {0,5,5,5,5,5,5,1};
//    assert(positionOfMin(a3, 8)==0);
//    const double a2[7] = {10,50,40,20,50,40,30};
//    const double b[3] = {50,20,30};
//    const double b1[3] = {50,40,40};
//    const double b2[3] = {50,30,20};
//    const double b3[3] = {10,20,20};
//    const double b4[3] = {10,50,40};
//    assert(includes(a2,7, b,3));
//    assert(includes(a2,7, b1,3));
//    assert(!includes(a2,7, b2,3));
//    assert(!includes(a2,7, b3,3));
//    assert(includes(a2,7, b4,3));
//    assert(positionOfMin(a2, 7)==0);
//
//    cout << "all tests passed" << endl;
    
    double a[10] = { 5, -5, -10, 6, -10, -6, -10, -10, -7, 7 };
    double x[10] = { 2, 7, 4, 8, -10, 0, -10, -10, 9, 6 };
    double y[10] = { 8, 10, 0, 9, 4, 5, -10, 2, 12, 6 };
    double b[4] = { 10, 0, 4, 2 };
    double c[8] = { 1, 9, 7, 3, 9, 7, 5 };
    double d[12] = { 1, 3, 7, 1, 7, 5, 3, 1, 7, 9, 7, 5 };
    double f[16] = { 4, 7, 0, 15, 2, 4, 5, 14, 10, 1, 0, 6, 12, 14, 4, 8 };
    double g[16] = { 15, 14, 14, 12, 10, 8, 7, 6, 5, 4, 4, 4, 2, 1, 0, 0 };
    int n = 19;
    switch (n)
    {
        default: {
            assert(false);
        } break; case  1: {
            assert(anyTrue(a, 10));
        } break; case  2: {
            assert(anyTrue(a, 8));
        } break; case  3: {
            assert(anyTrue(a+2, 8));
        } break; case  4: {
            assert(!anyTrue(a+8, 2)  &&  anyTrue(a+6, 2));
        } break; case  5: {
            assert(!anyTrue(a, 1));
        } break; case  6: {
            assert(anyTrue(a+2, 1));
        } break; case  7: {
            assert(!anyTrue(a, 0)  &&  !anyTrue(a+2, 0));
        } break; case  8: {
            assert(countTrue(a, 10) == 4);
        } break; case  9: {
            assert(countTrue(a, 8) == 4);
        } break; case 10: {
            assert(countTrue(a+2, 8) == 4);
        } break; case 11: {
            assert(countTrue(a+8, 2) == 0  &&  countTrue(a+6, 2) == 2);
        } break; case 12: {
            assert(countTrue(a, 1) == 0);
        } break; case 13: {
            assert(countTrue(a+2, 1) == 1);
        } break; case 14: {
            assert(countTrue(a, 0) == 0  &&  countTrue(a+2, 0) == 0);
        } break; case 15: {
            assert(firstTrue(a, 10) == 2);
        } break; case 16: {
            assert(firstTrue(a, 8) == 2);
        } break; case 17: {
            assert(firstTrue(a+2, 8) == 0);
        } break; case 18: {
            assert(firstTrue(a+8, 2) == -1  &&  firstTrue(a+6, 2) == 0);
        } break; case 19: {
            assert(firstTrue(a, 1) == -1);
        } break; case 20: {
            assert(firstTrue(a+2, 1) == 0);
        } break; case 21: {
            assert(firstTrue(a, 0) == -1  &&  firstTrue(a+2, 0) == -1);
        } break; case 22: {
            assert(positionOfMin(x, 6) == 4);
        } break; case 23: {
            assert(positionOfMin(x, 5) == 4);
        } break; case 24: {
            assert(positionOfMin(x+7, 3) == 0);
        } break; case 25: {
            assert(positionOfMin(x+8, 2) == 1);
        } break; case 26: {
            assert(positionOfMin(x+2, 2) == 0);
        } break; case 27: {
            assert(positionOfMin(x, 1) == 0);
        } break; case 28: {
            assert(positionOfMin(x+4, 1) == 0);
        } break; case 29: {
            assert(positionOfMin(x, 10) == 4);
        } break; case 30: {
            assert(positionOfMin(x, 0) == -1  &&  positionOfMin(x+2, 0) == -1);
        } break; case 31: {
            assert(includes(y, 10, b, 4));
        } break; case 32: {
            assert(includes(y+1, 9, b, 4));
        } break; case 33: {
            assert(!includes(y+2, 8, b, 4));
        } break; case 34: {
            assert(!includes(y+1, 6, b, 4));
        } break; case 35: {
            assert(includes(y+1, 7, b, 4));
        } break; case 36: {
            assert(includes(y, 10, b+2, 1));
        } break; case 37: {
            assert(includes(y+1, 9, b, 1));
        } break; case 38: {
            assert(!includes(y+2, 8, b, 1));
        } break; case 39: {
            assert(includes(y, 10, b, 0));
        } break; case 40: {
            assert(includes(y, 0, b, 0));
        } break; case 41: {
            assert(includes(y+1, 2, b, 2));
        } break; case 42: {
            assert(!includes(y+2, 2, b+1, 2));
        } break; case 43: {
            assert(!includes(y+2, 2, b+1, 3));
        } break; case 44: {
            assert(!includes(y+1, 1, b, 2));
        } break; case 45: {
            assert(!includes(y+1, 0, b, 1));
        } break; case 46: {
            assert(includes(c, 7, d+3, 3));
        } break; case 47: {
            assert(!includes(c, 7, d+6, 3));
        } break; case 48: {
            assert(includes(c, 7, d+9, 3));
        }
}
}
