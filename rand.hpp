#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
	Rand() : Base() {   }
	virtual double evaluate() { 
	    val = rand() % 100;
	    return val; 
	}
	virtual std::string stringify() { return std::to_string(val);}

    private:
	double val;
};

#endif //__RAND_HPP__
