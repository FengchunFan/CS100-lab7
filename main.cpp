#include "factory.hpp"

int main(int argv, char** argc){

Factory* factory = new Factory();
Base* calculate = factory -> parse(argc, argv);

delete factory;
//delete calculate;
cout << calculate -> stringify() << endl << calculate -> evaluate() << endl;

delete calculate;

return 0;
}
