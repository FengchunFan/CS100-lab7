#include "factory.hpp"

int main(int argv, char** argc){

Factory* factory = new Factory();
Base* calculate = factory -> parse(argc, argv);
cout << calculate -> stringify() << endl << calculate -> evaluate() << endl;

return 0;
}
