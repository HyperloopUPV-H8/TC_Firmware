#include <iostream>

class Coche{
    private:
        int num_ruedas;
    protected:
        int kms_autonomia;
        float velocidad;
        std::string marca;
        std::string color;
        static int numero_coches_creados;
    public:
        int static get_numero_coches_creados() {
            return numero_coches_creados;
        }
        Coche() = default;
        Coche(const Coche& coche) = delete;
        Coche(int kms_autonomia,std::string marca,std::string color): num_ruedas(4), velocidad(0.0)
        {
            numero_coches_creados++;
            this->kms_autonomia = kms_autonomia;
            this->marca = marca;
            this->color = color;
        } 
        virtual float get_vel(){
            return velocidad;
        }
        void set_marca(std::string marca){
            this->marca = marca;
        }
        void set_velocidad(float vel){
            velocidad = vel;
        }
        std::string get_marca(){
            return marca;
        }
       
        int get_ruedas(){
            return num_ruedas;
        }
        ~Coche(){
            std::cout << "Coche roto "<< std::endl;
        }
        friend std::ostream& operator<<(std::ostream& os, const Coche& coche){
            os << "Marca : "<< coche.marca << " Color: " << coche.color << " Kms autonomia: " << coche.kms_autonomia << std::endl;
            return os;
        }
    };
class Bateria{
    public:
        float peso;
        float potencia;
        Bateria(float peso,float potencia): peso(peso), potencia(potencia){}
    };
class CocheElectrico: public Coche,protected Bateria{
    public:
    CocheElectrico(int kms_autonomia,std::string marca,std::string color,float peso, float potencia): 
        Coche(kms_autonomia,marca,color), Bateria(peso,potencia){}
    float get_peso(){
        return peso;
    }
    float get_potencia(){
        return potencia;
    }
    float get_vel() override{
        return velocidad + potencia/100; 
    }
};
int Coche::numero_coches_creados = 0;
void print(int value){
    std::cout << "print un int: " << value << std::endl;
}
void print(float value){
    std::cout << "print un float:  " << value << std::endl;
}
void print(std::string value){
    std::cout << "Print un string " << value << std::endl; 
}

int main(){
    int array[5] = {1,2,3,4,5};
    for(auto x : array){
        std::cout << x << " ";    
    }
    Coche coche;
    //auto tesla = CocheElectrico(500,"tesla Y","rojo",2000.0,550);
    return 0;
}
