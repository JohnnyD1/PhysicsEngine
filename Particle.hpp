#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vector3.hpp"
#include "log.hpp"
#include <cmath>
//#include "string.hpp"

class Particle {

protected:
    // stores position of the particle in 3d space
    Vector3 position;
    // stores the velocity of the particle in 3d space
    Vector3 velocity;
    // stores the acceleration of the particle in 3d space
    Vector3 acceleration;
    Vector3 current_force;
    // this is basically a less accurate representation of drag
    // essentially removes energy from the particle
    // controls how much velocity is left in particle after updating it
    // value of 0 means then particle will have no velocity, if 1 then particle will not lose any velocity
    double damping;
    double mass;
    // it is easier in simulations to already know the inverse mas (quicker to calculate acceleration)
    double inverse_mass;
public:

    Particle() {
	damping = .999;
	mass = 1;
	inverse_mass = 1;

    }
    void set_position(const double x, const double y, const double z) { 
	
	position.x = x;
	position.y = y;
	position.z = z;

    }
    void set_position(const Vector3 &pos) {

	position = pos;
    }
    Vector3 get_position() const { return position; }

    void set_velocity(const double x, const double y, const double z) {
	velocity.x = x;
	velocity.y = y;
	velocity.z = z;
    }

    void set_velocity(const Vector3 &vel) { velocity = vel; }

    Vector3 get_velocity() const { return velocity; }

    void set_acceleration(const double x, const double y, const double z) {
	acceleration.x = x;
	acceleration.y = y;
	acceleration.z = z;
    }

    void set_acceleration(const Vector3 &acc) {
	acceleration = acc;
    }

    Vector3 get_acceleration() const { return acceleration; }

    void set_mass(const double m) { 
	mass = m; 
	if (m > 0) set_inverse_mass(m);
    }

    double get_mass() const { return mass; }
    
    void set_inverse_mass(const double m) {
	if (m == 0) LOG("Mass cannot be 0.");
	else inverse_mass = 1.0 / m;
    }
    void set_damping(const double d) {
	if (d > 1 || d < 0) {
	    LOG("damping has to be between 0 and 1.");
	    return;
	}
	damping = d;
    }

    double get_damping() const { return damping;}

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
#endif











