#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip>  
#include <math.h> 
using namespace std;
string input;
void conversion(long long b10, long long base2,string input,long long base1){
    long long i,pos=0,b[100],mult=1,j;
    j = b10;
    while (b10 > 0){
        b[pos] = (b10%base2);
        pos++;
        mult = mult*base2;
        b10 = b10 / base2;
    }
    if (j == 0){
        cout << input << " base " << base1 << " = ";
        cout << 0;
        cout << " base " << base2 << "\n";
    }
    else {
        cout << input << " base " << base1 << " = ";
        for (i = pos - 1; i >= 0; i--){
            if (b[i] > 9)cout << char(b[i] - 10 + 'A');
                else cout << b[i];
            }
        cout << " base " << base2 << "\n";
    }
}
int main()
{
    long long value, base1, base2,digits,b10,len,i,x;
    bool legal=true;
    while((cin>>base1)&&(cin>>base2)&&(getline(cin,input))){
        len = input.length();
        for (i = 0; i <= len; i++)if (input[i] == ' '){
            input.erase(i, 1);
            i = 0;
            len--;
        }
        if (input[0] == ' '){
            input.erase(0, 1);
            len--;
        }
        x = 1;
        b10 = 0;
        legal = true;
        for (i = len - 1; i >= 0; i--){
            if (('0' <= input[i])&&(input[i] <= '9')){
                b10 = b10 + (input[i]-'0') * x;
                if ((input[i]-'0') >= base1)legal = false;
            }
            else{
                b10 = b10 + (input[i] - 'A' + 10)*x;
                if ((input[i]-'A'+10) >= base1)legal = false;
            }
            x = x*base1;
        }
        if (legal==true)conversion(b10, base2,input,base1);
        else cout << input << " is an illegal base " << base1 << " number\n";
    }
	return 0;
}

