#ifndef _TERM_H_
#define _TERM_H_
#include <string>
#include <cmath>
#include <exception>
using namespace std;



class Term {

private:
    double _coefficient;
    int _exponent;

public:
    Term(){
        _coefficient =0;
        _exponent=0;
    }
    Term(double coefficient , int exponent) {
        _coefficient=coefficient;
        _exponent=exponent;
    }

    double getCoefficient() const{
        return _coefficient;
    }
    int getExponent() const{
        return _exponent;
    }
    
    double evaluate(double content){
        content = pow(content,_exponent)*_coefficient;
        return content;
    }

    Term& operator=(const Term& term){
        _coefficient=term._coefficient;
        _exponent=term._exponent;
        return *this;
    }

    Term operator+(const Term& term){
        Term temp;
            if( _exponent!=term._exponent){
                 throw string("ERROR");
            }
        temp._coefficient=_coefficient+term._coefficient;
        temp._exponent=_exponent+term._exponent;
        return temp;
    }

    Term operator*(Term& term){
        Term temp;
        temp._coefficient=_coefficient*term._coefficient;
        temp._exponent=_exponent*term._exponent;
        return temp;
    }

    bool operator==(Term& term){
        if (this->_coefficient==term._coefficient&&this->_exponent==term._exponent){
            return true;
        }else{
            return false;
        }
    }

};

#endif