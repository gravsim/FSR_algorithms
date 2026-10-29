#include <iostream>
#include "vec2.cpp"
#include "body.hpp"
#include <cmath>

Body::Body() {
    mass = 0;
    position = Vec2();
    velocity = Vec2();
}


Body::Body(double new_mass, const Vec2& new_position, const Vec2& new_velocity) {
    mass = new_mass;
    position = new_position;
    velocity = new_velocity;
}


void Body::set_mass(double new_mass) {
    mass = new_mass;
}


void Body::set_position(Vec2 &new_velocity) {
    velocity = new_velocity;
}


void Body::set_velocity(Vec2 &new_velocity) {
    velocity = new_velocity;
}


double Body::get_mass() {
    return mass;
}


Vec2 Body::get_position() {
    return position;
}


Vec2 Body::get_velocity() {
    return velocity;
}


void Body::add_position(const Vec2& addition_position) {
    position += addition_position;
}


void Body::add_velocity(const Vec2& addition_velocity) {
    velocity += addition_velocity;
}


Vec2 get_distance(Body body1, Body body2) {
    return body1.get_position() - body2.get_position();
}


inline Vec2 get_force(double G, Body body1, Body body2) {
    Vec2 distance = get_distance(body1, body2);
    return distance.normalized() * G * body1.get_mass() * body2.get_mass() / pow(distance, 2);
}
