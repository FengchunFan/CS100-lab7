#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    public:
        Div(Base* lhs, Base* rhs) : Base() {
            leftVal = lhs;
            rightVal = rhs;
        }
        virtual double evaluate() {
	    if(rightVal->evaluate() != 0) {
                return (leftVal->evaluate()) / (rightVal->evaluate());
	    }
	    else {
		return -1;
	    }
        }
        virtual std::string stringify() {
            return ("(" + leftVal->stringify() + "/" + rightVal->stringify() + ")");
        }

    private:
        Base* leftVal = nullptr;
        Base* rightVal = nullptr;

};

#endif //__DIV_HPP__
