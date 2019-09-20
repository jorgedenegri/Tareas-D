#include <iostream>

using namespace std;

int main()
{
    int cont=0;
    for(int i=0;i<1000000;i++){
        if(i%3==0||i%5==0){
                cont++;

        }
    }
    cout<<cont;

}
