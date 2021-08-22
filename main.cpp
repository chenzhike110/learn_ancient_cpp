#include "arrayList.hpp"
#include "chainList.hpp"

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

void checkChain() {
    chain<int>*x = new chain<int>(10);
    chain<double> y(1);
    std::cout << "chain size: " << y.size() << std::endl;
    y.insert(0, 1);
    std::cout << "current chain: " << y << std::endl;
    std::cout << "test operator over" << std::endl;
    y.insert(1, 2);
    std::cout << "current chain: " << y << std::endl;
    y.erase(0);
    std::cout << "current chain: " << y << std::endl;
}

int main(int argc, char** argv) {
    // checkArray();
    checkChain();
    return 0;
}