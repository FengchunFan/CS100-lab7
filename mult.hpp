#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    public:
	Mult(Base* lhs, Base* rhs) : Base() { 
	    leftVal = lhs;
	    rightVal = rhs;
	}
	virtual double evaluate() {
	    return (leftVal->evaluate()) * (rightVal->evaluate()); 
	}
	virtual std::string stringify() {
	    return ("(" + leftVal->stringify() + "*" + rightVal->stringify() + ")"); 
	}

    private:
	Base* leftVal = nullptr;
	Base* rightVal = nullptr;

};

#endif // __MULT_HPP__
