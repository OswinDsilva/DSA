#include<iostream>

using std::cout;
using std::max;
using std::min;

/*
-
n = 3
***
***
***
-
*/

void Pattern1 (int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<"*";
        cout<<"\n";
    }    
}


/*
-
n = 3
*
**
***
- 
*/

void Pattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<"*";
        cout<<"\n";
    }
}


/*
-
n = 3
1
12
123
-
*/

void Pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<j;
        cout<<"\n";
    }
}


/*
-
n = 3
1
22
333
-
*/

void Pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<i;
        cout<<"\n";
    }
}


/*
-
n = 3
***
**
*
-
*/

void Pattern5(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++)
            cout<<"*";
        cout<<"\n";
    }
}


/*
-
n = 3
123
12
1
-
*/

void Pattern6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++)
            cout<<j;
        cout<<"\n";
    }
}


/*
-
n = 3
  *
 ***
*****
-
*/

void Pattern7(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=2*i-1;j++)
            cout<<"*";
        cout<<"\n";
    }
}


/*
-
n = 3
*****
 ***
  *
-
*/

void Pattern8(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)
            cout<<" ";
        for(int j=1;j<=2*(n-i)+1;j++)
            cout<<"*";
        cout<<"\n";
    }
}


/*
-
n = 3
  *
 ***
*****
*****
 ***
  *
-
*/

void Pattern9(int n){
    for(int i=1;i<=2*n;i++){
        if(i <= n){
            for(int j=1;j<=n-i;j++)
                cout<<" ";
            for(int j=1;j<=2*i-1;j++)
                cout<<"*";
            cout<<"\n";
        }
        else{
            for(int j=1;j<i-n;j++)
                cout<<" ";
            for(int j=1;j<=2*(2*n-i)+1;j++)
                cout<<"*";
            cout<<"\n";
        }
    }
}


/*
-
n = 3
*
**
***
**
*
-
*/

void Pattern10(int n){
    for(int i=1;i<=2*n-1;i++){
        if(i <= n){
            for(int j=1;j<=i;j++)
                cout<<"*";
        }
        else{
            for(int j=1;j<=2*n-i;j++)
                cout<<"*";
        }
        cout<<"\n";
    }
}


/*
-
n = 3
1
01
101
-
*/

void Pattern11(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<(i+j+1)%2;
        cout<<"\n";
    }
}


/*
-
n = 3
1    1
12  21
123321
-
*/

void Pattern12(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<j;
        for(int j=1;j<=2*(n-i);j++)
            cout<<" ";
        for(int j=i;j>0;j--)
            cout<<j;
        cout<<"\n";
    }
}


/*
-
n = 3
1
2 3 
4 5 6
-
*/

void Pattern13(int n){
    int num = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<num++<<" ";
        cout<<"\n";
    }
}


/*
-
n = 3
A
AB
ABC
-
*/

void Pattern14(int n){
    for(int i = 1;i <= n;i++){
        for(char j = 'A'; j - 'A' < i ;j++)
            cout<<j;
        cout<<"\n";
    }
}


/*
-
n = 3
ABC
AB
A
-
*/

void Pattern15(int n){
    for(int i=1;i<=n;i++){
        for(char j = 'A';j - 'A' < n-i+1;j++)
            cout<<j;
        cout<<"\n";
    }
}


/*
-
n = 3
A
BB
CCC
-
*/

void Pattern16(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<(char)(i+'A'-1);
        cout<<"\n";
    }
}


/*
-
n = 3
  A
 ABA
ABCBA
-
*/

void Pattern17(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<(char)('A' + j - 1);
        for(int j=i-1;j > 0;j--)
            cout<<(char)('A' + j - 1);
        cout<<"\n";
    }
}


/*
-
n = 3
-
*/

void Pattern18(int n){
    char ch = 'A' ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout<<(char)(ch+(n-i+j-1));
        cout<<"\n";
    }
}


/*
-
n = 3
******
**  **
*    *
*    *
**  **
******
-
*/

void Pattern19(int n){
    for(int i=1;i<=2*n;i++){
        if(i <= n){
            for(int j=1;j<=n-i+1;j++)
                cout<<"*";
            for(int j=1;j<=2*(i-1);j++)
                cout<<" ";
            for(int j=1;j<=n-i+1;j++)
                cout<<"*";
        }
        else{
            for(int j=1;j<=i-n;j++)
                cout<<"*";
            for(int j=1;j<=2*(2*n-i);j++)
                cout<<" ";
            for(int j=1;j<=i-n;j++)
                cout<<"*";
        }
        cout<<"\n";
    }
}


/*
-
n = 3
*    *
**  **
******
**  **
*    *
-
*/

void Pattern20(int n){
    for(int i=1;i<=2*n-1;i++){
        if(i <= n){
            for(int j=1;j<=i;j++)
                cout<<"*";
            for(int j=1;j<=2*(n-i);j++)
                cout<<" ";
            for(int j=1;j<=i;j++)
                cout<<"*";
        }
        else{
            for(int j=1;j<2*n-i+1;j++)
                cout<<"*";
            for(int j=1;j<=2*(i-n);j++)
                cout<<" ";
            for(int j=1;j<2*n-i+1;j++)
                cout<<"*";
        }
        cout<<"\n";
    }
}


/*
-
n = 3
***
* *
***
-
*/

void Pattern21(int n){
    
    for(int i=1;i<=n;i++){
        char ch = ' ';
        cout<<"*";
        if(i == 1 || i == n)
            ch = '*';
        for(int j=2;j<n;j++)
            cout<<ch;
        cout<<"*\n";
    }
}


/*
-
n = 3        12345   
33333      1 00000
32223      2 01110
32123      3 01210
32223      4 01110
33333      5 00000
-
*/

void Pattern22(int n){
    for(int i=1;i<=2*n-1;i++){ 
        for(int j=1;j<=2*n-1;j++){
            int up = i;
            int down = 2*n-i;
            int left = j;
            int right = 2*n-j;
            cout<<n-min(min(up,down),min(left,right)) + 1;
        }
        cout<<"\n";
    }
}

// To test pattern
int main(){
    //Pattern1(3);
    //Pattern2(3);
    //Pattern3(3);
    //Pattern4(3);
    //Pattern5(3);
    //Pattern6(3);
    //Pattern7(3);
    //Pattern8(3);
    //Pattern9(3);
    //Pattern10(3);
    //Pattern11(3);
    //Pattern12(3);
    //Pattern13(3);
    //Pattern14(3);
    //Pattern15(3);
    //Pattern16(3);
    //Pattern17(3);
    //Pattern18(3);
    //Pattern20(3);
    //Pattern21(3);
    //Pattern22(3);
}