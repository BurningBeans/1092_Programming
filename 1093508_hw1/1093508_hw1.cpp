#include <iostream>
using namespace std;
class Dessert
{
public:
    Dessert();
    int getWeight();
    virtual void eat();
private:
    int weight;
};
Dessert::Dessert()
{
    weight = 80;
}
int Dessert::getWeight()
{
    return weight;
}
void Dessert::eat()
{
    weight-=20;
}
//Pancake
class Pancake : public Dessert
{
public:
    virtual void eat();
};
void Pancake::eat()
{
    cout << "Adding syrup..." << endl;
    Dessert::eat();
}
//Suncake
class Suncake : public Dessert
{
public:
    virtual void eat();
};
void Suncake::eat()
{
    cout << "Adding water..." << endl;
    Dessert::eat();
}

int main()
{
    Dessert *d;
    int choice;
    while ( cin >> choice )
    {
        switch ( choice )
        {
            case 1:
                d = new Dessert();
                break;
            case 2:
                d = new Pancake();
                break;
            case 3:
                d = new Suncake();
                break;
            default:
                exit( 1 );
    }

    cout << "The initial weight is " << d->getWeight() << '\n';
    d->eat();
    cout << "The weight has become " << d->getWeight() << "\n\n";
    delete d;
    }
}