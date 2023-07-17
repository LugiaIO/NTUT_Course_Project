#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "term.h"

class Polynomial {
public:
    Polynomial(Term terms[], int degree){
         initialize(terms, degree);
    }

    Polynomial(Polynomial const &p){
        initialize(p._terms, p._degree);
    }

    ~Polynomial(){
        if(_terms != NULL) {
            delete [] _terms;
    }
    }

    Polynomial operator+(const Polynomial &p){
        for(int i=0;i<_degree;i++){
            _terms[i]=_terms[i]+p.getTermByExponent(i);
        }
        return *this;
    }

    Polynomial& operator=(const Polynomial &p){
        if(_terms != NULL) {
      delete [] _terms;
    }
  _degree = p.getDegree();
    _terms = new Term[_degree+1];
            for(int i=0;i<=_degree;i++){
            _terms[i]=p.getTermByExponent(i);
        }
        return *this;
    }

    int getDegree() const{
        return _degree;
    }

    Term getTermByExponent(int exp) const{
        if (exp>_degree){
            throw string("ERROR");
        }
        return _terms[exp];
    }

    double evaluate(double base){
        double sum=0;
         for(int i=0;i<=_degree;i++){
           sum+=pow(base,_terms[i].getExponent())*_terms[i].getCoefficient();
        }
        return sum;
    }

private:
    Term* _terms;
    int _degree;
    void initialize(Term* terms, int degree){
     if(terms!=NULL){   
    _terms = new Term[degree+1];
    for(int i=0;i<=degree;i++){
      _terms[i] = terms[i];
    }
    _degree = degree;
     }else{
          _terms = new Term[degree];
     }
  }


};

#endif