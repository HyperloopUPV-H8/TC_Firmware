#include <iostream>
#include <vector>
template<typename T,typename U>
class pair{
        T first;
        U second;
    public:
        pair(T f, U s): first(f),second(s){}
        void display(){
            std::cout << "First: " << first << " Second: "<< second << std::endl;
        }
};

int main(){
    pair<int,float> p(5,4.0); //indicación explicita
    pair m(5,"hola"); // Class template argument Deduction a partir de C++17
    p.display();
    m.display();
    return 0;
}