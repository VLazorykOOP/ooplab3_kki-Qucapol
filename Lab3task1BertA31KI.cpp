#include <iostream>
#include <math.h>

using namespace std;

class rect {

    double a, b;
    unsigned int color;

public:
    rect(): a(1.0), b(2.0), color(0){}
    rect(double ai, double bi): a(ai), b(bi), color(0){}
    rect(int ic): a(1.0), b(2.0){ if (ic>=0)color = ic; else color = 0;}
    rect(double a, double b, int c){
      this->a=a;
      this->b=b;
      if (c>=0)color = c; else color = 0;
      } 

    double getA() const
    {
      return a;
    }
    void setA(double a)
    {
    if (a<0 || a>1.e+100)
    {
      cout<< "Error set a \n";
      return;
    }
    this->a=a;
    }

    double getB() const
    {
      return b;
    }
    void setB(double b)
    {
    if (b<0 || b>1.e+100)
    {
      cout<< "Error set b \n";
      return;
    }
    this->b=b;
    }

    double getColor() const
    {
      return color;
    }
    void setColor(int c)
    {
    if (c<0 || c>10000)
    {
      cout<< "Error set color \n";
      return;
    }
    this->color=c;
    }

    double S(){
      return a*b;
    }
    double P(){
      return (a+b)*2;
    }

    void prinInfo()
    {
      cout<<"\n a = "<<a<<" b = "<<b<<" color = "<<color;
      cout<<" S = "<<S()<<" P = "<<P()<<endl;
    }
  };
int main()
{
  rect obj;
  obj.prinInfo();
  double in_a, in_b;int in_color;
  cout << "Input a, b and color rectangle "; cin>> in_a >> in_b >> in_color;

  rect obj1(in_a), obj2(in_b), obj3(in_color), obj4(in_a, in_b, in_color);
  obj1.prinInfo();
  obj2.prinInfo();
  obj3.prinInfo();
  obj4.prinInfo(); 
  obj.setA(-3);
  obj.prinInfo();
  obj.setA(3);
  obj.prinInfo();
  obj.setA(2.e100);
  obj.prinInfo();
  obj.setB(-5);
  obj.prinInfo(); 
  obj.setB(5);
  obj.prinInfo(); 
  obj.setB(2.e100);
  obj.prinInfo();
  obj.setColor(-10); 
  obj.prinInfo();
  obj.setColor(10);
  obj.prinInfo();
  obj.setColor(10001);
  obj.prinInfo(); 
  cout<<"End testing \n";
  system("PAUSE"); 
  return 0;
}
  