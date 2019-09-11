#include <iostream>

using namespace std;

/*int main()
{
    int n,x=0,y=1,z=1;
    cout<<"ingrese numero: ";cin>>n;
    for(int i=0;i<n;i++){
        z=x+y;
        cout<<z<<" ";
        x=y;
        y=z;
    }

    return 0;
}
*/
int main(){
    int num,res,s=0,pot=1;
    cout<<"ingresa numero binario: ";cin>>num;
    while(num>0){
        res=num%10;
        num/=10;
        if(res==1){
                s+=pot;

        }
        pot*=2;
    }
    cout<<s;

}
