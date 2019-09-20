#include <iostream>

using namespace std;

int num_rev(int n){
    int s=0,r=0;
    while(n!=0){
        r=n%10;
        n=n/10;
        s=s*10;
        s=s+r;
    }
    return s;
}

int main()
{
    int n;
    cout<<"Ingrese numero: ";cin>>n;
    cout<< num_rev(n);
    return 0;
}
