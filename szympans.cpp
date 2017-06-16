#include <iostream>//Lukasz Florczak
#include <cstdlib>
#include <ctime>
using namespace std;
struct banan
{
    int poz;
    int czas;
};
void sortuj(banan *x, int n)  //sortuje bananany wzgledem czasu ich waznosci
{
    do{
        n--;
        for(int i = 0 ; i < n ; i++)
        {
            if(x[i].czas > x[i + 1].czas)
                swap(x[i], x[i + 1]);
        }
    }while(n > 1);
}
int main()
{
    srand(time(0));
    int n = rand() % 1000000 + 1;    //liczba banananow
    banan *x = new banan [n]; //tablica z czasami swiezosci banananow
    for(int i = 0; i < n; i++)
    {
        x[i].poz = i + 1;  //przypisuje bananowi jego pozycje
        x[i].czas = rand() % 1000 + 1;   // losuje czas swiezosci kazdego banananana
    }

    sortuj(x, n);   //sortuje bananany wzgledem czasu ich waznosci

    int i = 0, c = 0;
    cout << "Szympans zje banany w kolejnosci: ";
    while(c < n)        //sprawdzam czy kolejne bananany nadaja sie do jedzenia poprzez
    {                   //odejmowanie od ich czasu podstawowego ilosci zjedzonych banananow,
                        //bo 1 bananan = 1 minuta
        if(x[c].czas - i > 0)
        {
            cout << x[c].poz << " ";
            i++;//zwiekszam ilosc zjedzonych banananow
        }
        c++;
    }

    return 0;
}
