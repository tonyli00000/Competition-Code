#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip>  
#include <math.h> 

using namespace std;
int digits, base1, base2, value, sum, i, j, k, x, y, value2;
int counting(int value){
    int sum, digits;
    sum = 1;
    digits = 0;
    while (value / sum != 0){
        sum = sum * 10;
        digits++;
    }
    return digits;
}
//Finding the number of digits in the input
int base10(int value, int digits){
    for (i = 0; i < digits; i++){
        x = x + (value%sum)*y;
        y = y*base1;
        value = value / 10;
    }
    return x;
}
//finding the the base 10 value of the input
void conversion(int base2, int value){
    int a[100],i=0,p,o;
    k = base2;
    j = 1;
    while (k < value){
        k = k*base2;
        j++;
    }
    //finding how many digits are in the requested base
    k = k / base2;
    j = j - 1;
    o = j;
    //j is the number of digits
    while (j>=0){
            p = k;
            i=0;
            while (p <= value){
                p = p*base2;
                i++;
            }
            //Finding the value of the current digit.
            p = p / base2;
            a[j] = i;
            if(i!=0)value = value - p;
            k = k / 2;
        
        j--;
    }
    for (i = o; i >= 0; i--){
        cout << a[i];
        a[i] = 0;
    }
    cout << "\n";
    return;
}
//Converting to the requested base
int main()
{
    while (true){
        cout << "Please enter the base you are converting from.";
        cin >> base1;
        cout << "Please enter the base you are converting to.";
        cin >> base2;
        cout << "Please enter the value you are converting from.";
        cin >> value; 
        digits = counting(value);
        //trying to find the digits in the input
        x = 0;
        sum = 10;
        y = 1;
        if (base1 != 10)x = base10(value, digits);
        else x = value;
        //finding the base 10 value of the input
        if (base2 > base1){
            value = x;
            digits = counting(value);
            conversion(base2, x);
        }
        else conversion(base2, x);
    }
    return 0;
}