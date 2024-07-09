#include <iostream>
using namespace std;

class Film
{
    string name;
    string type;
    double film_registration_fee;
public:
    int i;
    Film(string n, string t): name(n), type(t) {}
    void add()
    {
        cout << "Enter the name of the film to be added:" << name << endl;
        cout << "The film name:" << name << " is added." << endl;
        cout << "Enter the type:" << type << endl;
        cout << "The type of film:" << type << endl;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    void setFee(double fee)
    {
        film_registration_fee = fee;
    }
    double getFee()
    {
        return film_registration_fee;
    }
    friend double calculateMonthlyFee(Film f);
};

double calculateMonthlyFee(Film f)
{
    if(f.getType() == "Animation")
        f.setFee(11.0);
    else if(f.getType() == "Action")
        f.setFee(17.0);
    else
        f.setFee(15.0);
        
    return f.getFee() * 30;
}
int main()
{
    Film film[2] = {Film("Withcer","Animation"), Film("Leon", "Action")};
    char action;
    int num;
    
    do{
        cout << "Do you want to add or watch a film (a/w)," << endl;
        cout << "or enter (C) for exit the system:";
        cin >> action;
        if(action == 'a')
        {
            for(int i=0; i<2; ++i)
            {
                film[i].add();
            }
        }
        else if(action == 'w')
        {
            cout << "Enter the number of films:" << endl;
            cin >> num;
            cout << "Enter " << num << " film names:" << endl;
            cout << "Enter the name of the movie: " << film[num-1].getName() << endl;
            cout << "Enter the type of the movie: " << film[num-1].getType() << endl;
            cout << "You've watched film, and type of the movie of the film is " << film[num-1].getType() << endl;
            cout << "Film Archive Fee Details:" << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Monthly rent fee: " << calculateMonthlyFee(film[num-1]) << "TL "<< endl;
            cout << "--------------------------------------------------------------------" << endl;
            
        }
        else if(action == 'c')
            cout << "Exit the system." << endl;
        }while(action == 'a' || action == 'w' || action == 'c');
        
    
    return 0;
}

