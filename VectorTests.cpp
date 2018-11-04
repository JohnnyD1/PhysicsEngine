#include "Vector3.h"
#include <vector>
#include <iostream>

void normalize_test(Vector3& vec) {
    
    vec.normalize();  
}
void magnitude_test(Vector3& vec) {

}

void squared_magnitude_test(Vector3& vec) {

}

void print_before(std::vector<double> vec) {
    std::cout << "BEFORE TEST: " << vec[0] << " " << vec[1] << " " << vec[2] << std::endl;

}

void print_after(std::vector<double> vec) {
    
    std::cout << "AFTER TEST: " << vec[0] << " " << vec[1] << " " << vec[2] << std::endl;
}

int main() {

    Vector3 vec(1,2,3);
    
    vec.get_vec_values();

   print_before(vec.get_vec_values());

    normalize_test(vec);

    print_after(vec.get_vec_values());



}
