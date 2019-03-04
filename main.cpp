#include <iostream>

using namespace std;
void wczytanie(int *n,int tab[],int *s);
int liniowe(int n,int tab[],int s);
int bisekcyjne(int n,int tab[],int s);//zak³adam ,¿e dane s¹ uporz¹dkowane
int bisekcyjne2(int l,int p,int tab[],int s);
int main()
{
    int n,s,tab[100],w,c;
    wczytanie(&n,tab,&s);
    cout<<"wybierz metode wyszukiwania: "<<endl;
    cout<<"1. Wyszukiwanie liniowe"<<endl;
    cout<<"2. Wyszukiwania bisekcyjnego - nierekurencyjna implementacja"<<endl;
    cout<<"3. Wyszukiwania bisekcyjnego - rekurencyjna implementacja"<<endl;
    cin>>w;
    switch (w)
        {
            case 1:
                {
                    c=liniowe(n,tab,s);
                    if(c==-1) cout<<"nie ma takiego elementu"<<endl;
                    else cout<<"szukany element znajduje sie na "<<c+1<<" pozycji"<<endl;
                    break;
                }
            case 2:
                {

                    c=bisekcyjne(n,tab,s);
                    if(c==-1) cout<<"nie ma takiego elementu"<<endl;
                    else cout<<"szukany element znajduje sie na "<<c+1<<" pozycji"<<endl;
                    break;
                }
            case 3:
                {
                    c=bisekcyjne2(0,n-1,tab,s);
                    if(c==-1) cout<<"nie ma takiego elementu"<<endl;
                    else cout<<"szukany element znajduje sie na "<<c+1<<" pozycji"<<endl;
                    break;
                }
        }
    return 0;
}
void wczytanie(int *n,int tab[], int *s)
{
    cout<<"ile bd danych? "<<endl;
    cin>>*n;
    for(int i=0;i<*n;i++)
    {
        cout<<"podaj "<<i+1<<" liczbe: "<<endl;
        cin>>tab[i];
    }
    cout<<"jakiego elementu szukamy?"<<endl;
    cin>>*s;

}
int liniowe(int n,int tab[],int s)
{
    int index,i=0;
    for(;i<n && tab[i]!=s;i++);
    if(tab[i]==s) return i;
    else return -1;


}
int bisekcyjne(int n,int tab[],int s)
{
    int p=n-1,l=0,sr;
    while(l<=p)
    {
        sr=(l+p)/2;
        if(tab[sr]==s) return sr;
        if(tab[sr]>s) p=sr-1;
            else l=sr+1;
    }
    return -1;
}
int bisekcyjne2(int l,int p,int tab[],int s)
{
    int sr;
    sr=(l+p)/2;
    if(l<=p)
    {
        if(tab[sr]==s) return sr;
        if(tab[sr]>s) bisekcyjne2(l,sr-1,tab,s);
            else bisekcyjne2(sr+1,p,tab,s);
    }
        else return -1;

}
