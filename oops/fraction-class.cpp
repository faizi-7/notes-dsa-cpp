#include<iostream>
using namespace std;

class Fraction {
    private:
        int numerator, denominator;
    public:
        Fraction(int numerator, int denominator){
            this->numerator= numerator;
            this->denominator= denominator;
        }
        
        void print(){
            cout<<this->numerator<<"/"<<this->denominator<<endl;
        }

        void add(Fraction const &f2){
            int lcm= this->denominator * f2.denominator;
            int x= lcm/this->denominator;
            int y= lcm/f2.denominator;
            int num= x*this->numerator + y*f2.numerator;
            numerator= num;
            denominator= lcm;
            simplify();
        }
    
        void multiply(Fraction const &f2){
            this->numerator= f2.numerator * this->numerator;
            this->denominator= f2.denominator * this->denominator;
            simplify();
        }

        void simplify(){
            for(int i = numerator * denominator; i > 1; i--)
            {
                if((numerator % i) == 0 && (denominator % i) == 0)
                {
                    numerator = numerator / i;
                    denominator = denominator / i;
                }
            }
        }
};

