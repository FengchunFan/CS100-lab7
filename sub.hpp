#ifndef SUB_HPP
#define SUB_HPP

#include "base.hpp"

class SUB : public Base{
	private:
		Base* val1 = nullptr;
		Base* val2 = nullptr;
	public:
		SUB(Base* val1, Base* val2):Base(){
			this -> val1 = val1;
			this -> val2 = val2;	
		}
		
		virtual double evaluate(){
			return((val1->evaluate()) - (val2->evaluate()));
		}

		virtual std::string stringify() {
	   		 return ("(" + val1->stringify() + "-" + val2->stringify() + ")"); 
		}
};

#endif
