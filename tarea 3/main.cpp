#include <iostream>

using namespace std;
/*void imprimir_digitos(int n){
    cout<<n/10000<<"\t";
    n%=10000;
    cout<<n/1000<<"\t";
    n%=1000;
    cout<<n/100<<"\t";
    n%=100;
    cout<<n/10<<"\t";
    n%=10;
    cout<<n;
}

int main()
{
    int num;
    cout<<"ingrese numero: "<<endl;cin>>num;
    imprimir_digitos(num);


    return 0;
}
*/
/*int contar_digitos(int n,int cont=0){
    while(n>0){
            n/=10;
            cont++;


    }
    return cont;



}
int main(){
    int num;
    cout<<"ingresa numero p:"<<endl;cin>>num;
    cout<<contar_digitos(num);
    return 0;
}
*/
/*bool es_palindrome(int n){
    int a,b,c,d,e;

    a=n%10;
    n=n/10;
    b=n%10;
    n=n/10;
    c=n%10;
    n=n/10;
    d=n%10;
    n=n/10;
    e=n%10;
    if ((a==e) and (b==d)){
        return true;
    }
    else{
        return false;
    }

}
int main(){
    int num;
    cout<<"ingresa numerow"<<endl;cin>>num;
    cout<<es_palindrome(num);


    return 0;
}
*/
/*int fibonacci(int n){
    int x=0,y=1,z=1;
    if((n==0)||(n==1)){
        return z;
    }
    for(int i=0;i<n;i++){
        z=x+y;
        x=y;
        y=z;
    }
    return z;

    }
int main(){
    int num;
    cout<<"ingresa tu numero causita"<<endl;cin>>num;
    cout<<fibonacci(num);
    return 0;
}
*/
/*bool es_numero(char c){
    int n=static_cast<int>(c);
    if((n>=48)&&(n<58)){
       return true;
       }

    return false;


}
int main(){
    char n;
    cout<<"ingresar numero"<<endl;cin>>n;
    cout<<es_numero(n);

}
*/
/*bool es_letra(char c){
    int n=static_cast<int>(c);
    if((n>96 && n<123)||(n>64 && n<91)){
       return true;
       }

    return false;


}
int main(){
    char n;
    cout<<"ingresar letra"<<endl;cin>>n;
    cout<<es_letra(n);

}
*/

char convertirMayuscula (char c){
    int n = static_cast<int>(c);
    n=n-32;
    char b=static_cast<char>(n);
    return b;
}
int main ()
{
    char c;
    cout <<"Ingrese una letra"<<endl;
    cin >>c;
    cout <<"En mayuscula es: "<< convertirMayuscula(c);

}
