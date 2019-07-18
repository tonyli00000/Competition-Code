#include <algorithm>
#include <cstdio>
#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip>  
#include <math.h> 
#define len 5
using namespace std;
int solution[200][10],b=0,a[10],l;
bool p[10];
int op(int sum, int val, int I) {
    if(I==0)return (sum + val);
    if(I==1)return (sum - val);
    if(I==2)return (sum * val);
    
    return 0;
}
void sorting(int in[5],int position){
    int i, j, k = 0;
    for (i = 0; (i < len); i++){
        if ((p[i]) && ((i == 0) || (in[i] != in[i - 1]) || (p[i - 1] == false))){
            a[position] = in[i];
            p[i] = false;
            sorting(in, position + 1);
            p[i] = true;
        }
    }
    if (position == len){
        for (i = 0; i < len; i++){
            solution[l][i] = a[i];
        }
        l++;
      }
}
int main() {
    int j, k=0,a,b=0,c,d,sum,i;
    while (true) {
        int num[10];
        for (i = 0; i < 5; i++)cin>>num[i];
        if (num[0]==0)break;
        for (i = 0; i < len; i++)p[i] = true;
        bool x = false;
        sorting(num, 0);
        while (k<=l)
        {
            for (a = 0; a < 3; a++)
                for (b = 0; b < 3; b++)
                    for (c = 0; c < 3; c++)
                        for (d = 0; d < 3; d++) {
                            sum = solution[k][0];
                            sum = op(sum, solution[k][1], a);
                            sum = op(sum, solution[k][2], b);
                            sum = op(sum, solution[k][3], c);
                            sum = op(sum, solution[k][4], d);
                            if (sum == 23) {
                                x = true;
                                break;
                            }
                        }
            sum = 0;
            k++;
        }
        if (x)
            cout<<("Possible\n");
        else
            cout<<("Impossible\n");
        l = 0;
        k = 0;
    }
    return 0;
}