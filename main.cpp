#include "linearList.hpp"
#include "arrayList.hpp"

void checkArray() {
    linearList<int>* x =  new arrayList<int>(10);
    arrayList<double> y(1);

    std::cout << "try to insert a number" << std::endl;
    y.insert(0, 1);
    std::cout << "1 insert to the first" << std::endl;
    y.insert(0, 2);
    std::cout << "Test get function: " << y.get(1) << std::endl;
    std::cout << "Test operator: " << y << std::endl;

    // arrayList<char> z;
    arrayList<double> w(y);
}

int main(int argc, char** argv) {
    checkArray();
}