/*
The user enters a number. Make a spiral that begins with 1 and starts from the top left, 
going towards the right, and ends with the square of that number.
*/

#include <bits/stdc++.h>
using namespace std;


int a[100][100];
void func(int n,int dir){
    int i=0,j=0,l=1;
    int low=0,high=n;
    if(dir==1){
        while(low<high){
            while(j<high){
                a[i][j]=l++;j++;
            }j--;i++;
            while(i<high){
                a[i][j]=l++;i++;
            }i--;j--;
            while(j>=low){
                a[i][j]=l++;j--;
            }j++;i--;
            while(i>low){
                a[i][j]=l++;i--;
            }
            low++;high--;
            i=low;
            j=low;
        }
    }
    if(dir==-1){
        while(low<high){
            while(i<high){
                a[i][j]=l++;i++;
            }i--;j++;
            while(j<high){
                a[i][j]=l++;j++;
            }j--;i--;
            while(i>=low){
                a[i][j]=l++;i--;
            }i++;j--;
            while(j>low){
                a[i][j]=l++;j--;
            }
            low++;high--;
            i=low;
            j=low;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }

}


int main(){
    int n,dir;
    cin>>n>>dir;
    func(n,dir);
    return 0;
}
