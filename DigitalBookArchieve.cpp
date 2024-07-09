#include <iostream>
using namespace std;

class DigitalBookArchieve
{
private:
    string name;
    string type;
    int digitalBookCount=20;
public:
    DigitalBookArchieve()
    {
        cout << "Enter the name of the Digital Book Archieve:" << endl;
        cin >> name;
        cout << "Enter the type of the digital book: " << endl;
        cin >> type;
    }
    DigitalBookArchieve(string nm, string typ): name(nm), type(typ) {}
    
    void getName();
    void addBook();
    void readBook();
    void print();
};

void DigitalBookArchieve::getName(){
        cout << "Digital Book Archieve name set to " << name << endl;
        cout << "Digital Book type is: " << type << endl;
}

void DigitalBookArchieve::addBook()
{
    ++digitalBookCount;
}

void DigitalBookArchieve::readBook()
{
    --digitalBookCount;
}

void DigitalBookArchieve::print()
{
    cout << "The number of remaining digital book is " << digitalBookCount << endl;
}

int main()
{
    DigitalBookArchieve d;
    d.getName();
    
    char ans;
    
    do{
        cout << "Do you want to add or read a digital book (a/r), or enter (C) for exit the system:";
        cin >> ans;
        if((ans == 'a') || (ans == 'A'))
            d.addBook();
        else if ((ans == 'r') || (ans == 'R'))
            d.readBook();
        else
            d.print();
    }while((ans == 'a') || (ans == 'A') || (ans == 'r') || (ans == 'r'));
    
}
