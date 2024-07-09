#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class RightTriangle
{
    double a, b, c, alpha, beta;
public:
    RightTriangle(double s1, double s2, double s3): a(s1), b(s2), c(s3)
    {
        alpha = asin(a/c) * 180.0 * M_PI;
        beta = asin(b/c) * 180.0 * M_PI;
    }
    
    double getSide1(){return a;}
    double getSide2(){return b;}
    double getSide3(){return c;}
    double getAlpha(){return alpha;}
    double getBeta(){return beta;}
    
    void setSide1(double side1){a = side1;}
    void setSide2(double side2){b = side2;}
    void setSide3(double side3){c = side3;}
    void setAlpha(double angle){alpha = angle;}
    void setBeta(double angle){beta = angle;}
    
    friend ostream& operator << (ostream& out, const RightTriangle& tr)
    {
        out << "Triangle with a=" << tr.a << " b=" << tr.b << " c=" << tr.c;
        
        return out;
    }
};

class TrExc
{
    double a,b,c;
public:
    TrExc(double s1, double s2, double s3): a(s1), b(s2), c(s3) {}
    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }
};

int main()
{
    ifstream inp("sides.txt");
    double a1,b1,c1;
    
    while(inp.eof())
    {
        try
        {
            inp >> a1 >> b1 >> c1;
            if(a1 < 0 || b1 < 0 || c1 < 0)
            {
                throw TrExc(a1, b1, c1);
            }
            
            if(a1 * a1 + b1 * b1 != c1 * c1)
            {
                throw runtime_error("Triangle is not a right triangle.");
            }
            
            RightTriangle tri(a1, b1, c1);
            cout << tri << endl;
        }
        
        catch(const TrExc& ex)
        {
            int num;
            if(ex.getSideA() < 0)
            {
                num = ex.getSideA();
                cout << "Negative side " << num << " is corrected to " << -num << endl;
            }
            if(ex.getSideB() < 0)
            {
                num = ex.getSideB();
                cout << "Negative side " << num << " is corrected to " << -num << endl;
            }
            if(ex.getSideC() < 0)
            {
                num = ex.getSideC();
                cout << "Negative side " << num << " is corrected to " << -num << endl;
            }
        }
    }
    
    inp.close();
    
    return 0;
}
