#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Exam
{
protected:
    string name;
    int dd, mm, yy;
    double total_score;
public:
    Exam(string n, int d, int m, int y): name(n), dd(d), mm(m), yy(y) {}
    
    virtual int calcScore() = 0;
    virtual void printInfo() = 0;
    virtual string getExamType() = 0;
};

class TOEFL: public Exam
{
protected:
    int reading, listening, speaking, writing;
public:
    TOEFL(string n, int d, int m, int y): Exam(n,d,m,y)
    {
        cout << "Enter score score for Reading: ";
        cin >> reading;
        cout << "Enter score for Listening: ";
        cin >> listening;
        cout << "Enter score for Speaking: ";
        cin >> speaking;
        cout << "Enter score for Writing: ";
        cin >> writing;
        
        total_score = calcScore();
    }
    
    int calcScore()
    {
        return reading + listening + speaking + writing;
    }
    
    string getExamType()
    {
        return "TOEFL";
    }
    
    void printInfo()
    {
        cout << "Name: " << name << " Exam: " << getExamType() << " Date of exam: " << dd << "/" << mm << "/" << yy << endl;
        cout << "Total score: " << total_score << endl << endl;
    }

};

class IELTS: public Exam
{
protected:
    double r_score, l_score, s_score, w_score;
public:
    IELTS(string n, int d, int m, int y): Exam(n,d,m,y)
    {
        cout << "Enter score for Reading: ";
        cin >> r_score;
        cout << "Enter score for Listening: ";
        cin >> l_score;
        cout << "Enter score for Speaking: ";
        cin >> s_score;
        cout << "Enter score for Writing: ";
        cin >> w_score;
        
        total_score = calcScore();
    }
    
    double convert(double &num)
    {
        if (num == 40)
            return 9.0;
        else if (num == 39)
            return 8.5;
        else if (num == 38)
            return 8.0;
        else if (num >= 36 && num <= 37)
            return 7.5;
        else if (num >= 34 && num <= 35)
            return 7.0;
        else if (num >= 32 && num <= 33)
            return 6.5;
        else if (num >= 30 && num <= 31)
            return 6.0;
        else if (num >= 26 && num <= 29)
            return 5.5;
        else if (num >= 23 && num <= 25)
            return 5.0;
        else if (num >= 19 && num <= 22)
            return 4.5;
        else if (num >= 15 && num <= 18)
            return 4.0;
        else if (num >= 12 && num <= 14)
            return 3.5;
        else if (num >= 8 && num <= 11)
            return 3.0;
        else if (num >= 5 && num <= 7)
            return 2.5;
        else if (num >= 2 && num <= 4)
            return 2.0;
        else if (num == 1)
            return 1.0;
        else if (num == 0)
            return 0.0;
        
        return 0.0;
    }
    
    int calcScore()
    {
        r_score = convert(r_score);
        l_score = convert(l_score);
        s_score = convert(s_score);
        w_score = convert(w_score);
        
        double average = (r_score + l_score + s_score + w_score) / 4.0;
        total_score = round(average);
        
        return total_score;
    }
    
    string getExamType()
    {
        return "IELTS";
    }
    
    void printInfo()
    {
        cout << "Name: " << name << " Exam: " << getExamType() << " Date of exam: " << dd << "/" << mm << "/" << yy << endl;
        cout << "Reading : " << r_score << " Listening: " << l_score << " Speaking: " << s_score << " Writing: " << w_score << endl;
        cout << "Total score: " << total_score << endl << endl;
    }
};

class Yokdil: public Exam
{
protected:
    int correctAnswers;
public:
    Yokdil(string n, int d, int m, int y): Exam(n,d,m,y)
    {
        cout << "Enter number of correct answers: ";
        cin >> correctAnswers;
        
        total_score = calcScore();
    }
    
    int calcScore()
    {
        return total_score = (correctAnswers * 1.25);
    }
    
    string getExamType()
    {
        return "Yokdil";
    }
    
    void printInfo()
    {
        cout << "Name: " << name << " Exam: " << getExamType() << " Date of exam: " << dd << "/" << mm << "/" << yy << endl;
        cout << "Total score: " << total_score << endl << endl;
    }
};

int main()
{
    char action;
    string n;
    int d,m,y;
    Exam *stu[3];
    for(int i=0; i<3; i++)
    {
        cout << "Enter name of student: ";
        cin >> n;
        cout << "Enter date of exam: ";
        cin >> d >> m >> y;
        cout << "Enter T for TOEFL, I for IELTS or Y for Yokdil: ";
        cin >> action;
        if(action == 'T')
        {
            stu[i] = new TOEFL(n,d,m,y);
            stu[i]->printInfo();
        }
        else if(action == 'I')
        {
            stu[i] = new IELTS(n,d,m,y);
            stu[i]->printInfo();
        }
        
        else if(action == 'Y')
        {
            stu[i] = new Yokdil(n,d,m,y);
            stu[i]->printInfo();
        }
    }

    return 0;
}
