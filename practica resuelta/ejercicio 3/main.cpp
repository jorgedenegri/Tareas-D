#include <iostream>

using namespace std;
int power(int base,int exponente){
    if(exponente==0){
        return 1;
    }
    else{
        return base*power(base,exponente-1);
    }
}
int main()
{
    int bas,expo;
    cout<<"ingrese base: ";cin>>bas;
    cout<<"ingrese exponente: ";cin>>expo;
    cout<<power(bas,expo);
    return 0;
}
