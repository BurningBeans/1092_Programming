#include <iostream>
using namespace std;
class Martian
{
    private:
    static int count;
    public:
    Martian()
    {
        count++;
    }
    ~Martian()
    {
        count--;
    }
    void attack() //
    {
        if(count >= 3)
            cout << "I'm attacking!\n";
        else
            cout << "I'm running for my life.\n";
    }
};
int Martian::count = 0;
int main()
{
    Martian a;
    Martian b;

    a.attack(); // Sorry, I am running for my life.

    {
        Martian *p = new Martian();
        a.attack(); // I am attacking!!!
        p->attack(); // I am attacking!!!
        delete p;
    }

    a.attack(); // Sorry, I am running for my life.

    Martian c;

    b.attack(); // I am attacking!!!
}