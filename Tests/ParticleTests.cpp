#include "log.hpp"
#include "Vector3.hpp"
#include "Particle.hpp"
#include "string.hpp"
#include <vector>


void update_tests(Particle& particle) {


    LOG(to_string(particle)) ;

    particle.update_pos_vel(1);
    
    LOG("update:\n" + to_string(particle) ) ; 
    

}


int main() {

    Particle particle;
    particle.set_position(0,0,0);	
    particle.set_velocity(0,0,0);	
    particle.set_acceleration(1,0,0);	

    update_tests(particle);

    return 0;

}
