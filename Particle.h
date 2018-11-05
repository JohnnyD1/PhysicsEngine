#include "Vector3.h"
#include "log.h"
#include <cmath>

class Particle {

protected:
    // stores position of the particle in 3d space
    Vector3 position;
    // stores the velocity of the particle in 3d space
    Vector3 velocity;
    // stores the acceleration of the particle in 3d space
    Vector3 acceleration;
    // this is basically a less accurate representation of drag
    // essentially removes energy from the particle
    // controls how much velocity is left in particle after updating it
    // value of 0 means then particle will have no velocity, if 1 then particle will not lose any velocity
    double damping;
    // it is easier in simulations to already know the inverse mas (quicker to calculate acceleration)
    double inverse_mass;
public:
    Particle() {
	damping = .999
	mass = 1;
	universe_mass = 1;
    }
    
    double mass;
    
    void set_mass(const double m) { 
	mass = m; 
	if (m > 0) set_inverse_mass(m);
    }

    void set_inverse_mass(const double m) {
	m == 0 ? LOG("Mass cannot be 0.") ? inverse_mass = 1.0 / m;
    }
    void set_damping(const double d) {
	if (d > 1 || d < 0) {
	    LOG("damping has to be between 0 and 1.");
	    return;
	}
	damping = d;
    }
    // position and velocity update
    void update_pos_vel(double time_step) {
	if (time_step <= 0.0) {
	    LOG("time step needs to be greater than 0.");
	    return;
	}

	/* need to update current position - p' = p + p_dot * time
	 * we ignore acceleration here because we are taking such a small time step
	 * so that acceleration because so small, that it doesn't make much of a difference.
	 * However, if the acceleration is extremely high, then it might need to be included
	 */
	position.add_scaled_vec(velocity, time_step);
	/*
	 * update velocity - p_dot' = p_dot * damping^time + p_dot_dot * time
	 */
	// don't want to modify current acceleration, just need it to apply to velocity
	Vector3 resulting_acc = acceleration;
	/*
	 * p_dot += p_dot_dot * time
	 */
	velocity.add_scaled_vec(resulting_acc, time_step);
	
	// adding drag
	velocity *= pow(damping, time_step);
	
	
    }

};














