#include <iostream>

using namespace std;
int fibonacci(int n){
    int x=0,y=1,z;
    for(int i=0;i<n;i++){
        z=x+y;
        x=y;
        y=z;
    }
    return z;
}
int main()
{
    int n;
    cout<<"ingresa numero: ";cin>>n;
    cout<<fibonacci(n);

    return 0;
}
