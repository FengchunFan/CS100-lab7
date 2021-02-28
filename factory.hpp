#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

#include <string>
//#include <cctype>
#include <queue>
using namespace std;

class Factory{
	private:
		//used for calculating results, stored all the necessary value
		queue<Base*> operands;
		queue<string> operators;
		queue<Base*> output;

	public:
		Factory(){};

		Base* parse(char** input, int length){
		if(length == 1){
		string str = static_cast<string>(input);
		if(isdigit(str.at(0))){
			Op* val = new Op(std::stoi(input[0]));
			return val;
		} else {
			cout << "invalid!" << endl;
			return nullptr;
		}
	} else if (length % 2 == 0){
			cout << "invalid!" << endl;
			return nullptr;
	} else {
		for(int i = 0; i < length; ++i){
		char* c = input[i];
		//need to declare if c is operand or operator
		if(c=="0" or c=="1" or c=="2" or c=="3" or c=="4" or c=="5" or c=="6" or c=="7" or c=="8" or c=="9"){
			double val = std::stod(c);
			Base* temp = new Op(val);
			operands.push(temp);
		} else if (c=="+" or c=="-" or c=="*" or c=="/" or c=="**"){
			string temp = c;
			operators.push(temp);
		}
	}//classified whether stuff in the input is operands or operators, and store value into queue
		Base* val1 = operands.front();
		operands.pop();
		Base* val2 = operands.front();
		operands.pop();

		calculate(val1,val2); // output will be stored into the start of output
		Base* answer = output.front();
		return answer;
		}
	};	

		void calulate(Base* val1, Base* val2){
			
	};
};

#endif //_FACTORY_HPP_