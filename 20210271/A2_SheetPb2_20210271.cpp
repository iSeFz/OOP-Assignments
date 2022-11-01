#include <iostream> 
#include <functional>
#include <cmath>
using namespace std;
class Function{
    virtual double evaluateAt(double value) = 0;
};
class SimpleFunction : public Function {
    private:
        function<double(double)> fun;
    public:
        SimpleFunction(function<double(double)> fun) {
            this->fun = fun;
        }
        double evaluateAt(double value){
            return fun(value);
        }
};
class CompositeFunction : public Function {
    private:
        function<double(double)> fun1;
        function<double(double)> fun2;
    public:
        CompositeFunction(function<double(double)> fun1, function<double(double)> fun2){
            this->fun1 = fun1;
            this->fun2 = fun2;
            
        }
        double evaluateAt(double value){
            return fun1(fun2(value));
        }

};
class DerivativeFunction : public Function {
    private:
        function<double(double)> fun;
        double deltaX;
    public:
        DerivativeFunction(function<double(double)> fun, double deltaX) {
            this->fun = fun;
            this->deltaX = deltaX;
        }
        double evaluateAt(double value){
            double result = ((fun(value + deltaX) - fun(value - deltaX)) / (2 *deltaX));
            return result;
        }
};

double cube(double x){
    return x * x * x;
}
double absolute(double x){
    if(x < 0)
        return -x;
    else
        return x;
}

int main(){
    SimpleFunction ahmed(cube);
    cout << ahmed.evaluateAt(2.5) << endl;
    SimpleFunction abdelfatah([](double x){
        return -x;
    });
    cout << abdelfatah.evaluateAt(-5) << endl;
    CompositeFunction lol(cube, absolute);
    cout << lol.evaluateAt(-7);
    DerivativeFunction lolk(cube, 1);
    cout << lolk.evaluateAt(5);
}