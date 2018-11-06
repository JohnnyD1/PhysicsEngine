#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <tuple>
#include <vector>
#include "Vector3.hpp"
#include "Particle.hpp"

char to_string(int var) { return var + '0'; }

std::string to_string(double var) { return std::to_string(var); }

char to_string(char var) { return var; }

std::string to_string(float var) { return std::to_string(var); }

std::string to_string(std::string var) { return var; }

std::string to_string(std::vector<int> vars) { 
    std::string out = "";
    std::cout << "what" << std::endl;
    for (auto x : vars) {
	out += (char)(x + '0');
    }
    return out; 
}
std::string to_string(std::vector<double> vars) { 
    std::string out = "";

    for (auto x : vars) {
	out += std::to_string(x) + ' ';
    }
    return out; 
}

std::string to_string(std::vector<float> vars) { 
    std::string out = "";

    for (auto x : vars) {
	out += std::to_string(x) + ' ';
    }
    return out; 
}

std::string to_string(std::vector<char> vars) { 
    std::string out = "";

    for (auto x : vars) {
	out += x + ' ';
    }
    return out; 
}
std::string to_string(Vector3 var) {
    std::string out = "";
    
    
    return std::to_string(var.x) + ' ' + std::to_string(var.y) + ' ' + std::to_string(var.z) + ' ';

}
std::string to_string(std::vector<Vector3> vars) {
    std::string out = "";

    for (auto x : vars) {
	out += to_string(x);	
    }
    return out;
}
std::string to_string(Particle p) {
    std::string out = "";
    out += "position: ";
    out += to_string(p.get_position());
    out += "\n";
    out += "velocity: ";
    out += to_string(p.get_velocity());
    out += "\n";
    out += "acceleration: ";
    out += to_string(p.get_acceleration());

    return out;
}
#endif
