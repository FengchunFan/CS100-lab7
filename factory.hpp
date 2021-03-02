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
#include <cctype>
#include <ctype.h>
#include <queue>
using namespace std;

class Factory{
	private:
		//used for calculating results, stored all the necessary value
		queue<Base*> operands;
		queue<string> operations;
		queue<Base*> output;
	public:
		Factory(){};

		Base* parse(char** input, int length){
		
		for(int i = 1; i < length; ++i){
	
		//need to declare if c is operand or operator
		
		if(isdigit(*input[i])) {
			int val  = atoi(input[i]);
			Base* temp = new Op(val);
			operands.push(temp);
		} else if(*input[i]=='+' or *input[i]=='-' or *input[i]=='*' or *input[i]=='/' or *input[i]=='**'){	;
			if(!isdigit(*input[i+1])){
			return nullptr;
			}else{
			operations.push(input[i]);
			}// the system will return segmentation fault if fail
		}
		}

		output.push(operands.front());
		operands.pop();
	
		while(!operations.empty()){
			Base* val1 = output.front();
			output.pop();
			Base* val2 = operands.front();
			operands.pop();
			Base* answer;

		
				if(operations.front() == "+"){
                        		answer  = new ADD(val1, val2);
                		}
                		else if(operations.front() == "-"){
                        		answer  = new SUB(val1, val2);
                		}
                		else if(operations.front() == "*"){
                        		answer  = new Mult(val1, val2);
                		}
                		else if(operations.front() == "/"){
                        		answer = new Div(val1, val2);
                		} 
                		else if(operations.front() == "**"){
                        		answer = new POW(val1, val2);
                		}
                		output.push(answer);
                		operations.pop();	
			}
			return output.front();
			output.pop();
		};
		//return output.front();	
	};

		/*void calculate(Base* val1, Base* val2){
			if(operators.size()!=0){
				string op = operators.front();
			//as long as there is operations, we perform the calculation with the first operator
			if(op == "+"){
				operators.pop();
				Base* add = new ADD(val1,val2);
			if(operands.size()!=0){//if there is more operations	
				val2 = operands.front();
					operands.pop();
				}
				calculate(add,val2);
				output.push(add);
			}
			if(op == "-"){
                                operators.pop();
                                Base* sub = new SUB(val1,val2);
                         if(operands.size()!=0){//if there is more operations
			             val2 = operands.front();
                                        operands.pop();
                                }
				calculate(sub,val2);
                                output.push(sub);
                        }
			if(op == "*"){
                                operators.pop();
                                Base* mult = new Mult(val1,val2);
                        if(operands.size()!=0){//if there is more operations   
			            val2 = operands.front();
                                        operands.pop();
                                }
				calculate(mult,val2);
                                output.push(mult);
                        }
			if(op == "/"){
                                operators.pop();
                                Base* div = new Div(val1,val2);
                        if(operands.size()!=0){//if there is more operations
				       val2 = operands.front();
                                        operands.pop();
                                }
				calculate(div,val2);
                                output.push(div);
                        }
			if(op == "**"){
                                operators.pop();
                                Base* pow = new POW(val1,val2);
                                if(operands.size()!=0){//if there is more operations
                                        val2 = operands.front();
                                        operands.pop();
                                }
				calculate(pow,val2);
                                output.push(pow);
                        }
		}	
	};*/


#endif //_FACTORY_HPP_
