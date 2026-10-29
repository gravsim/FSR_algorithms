#include "body.cpp"



void update_positions(int N, double timestep, Body* bodies) {
    for (int i = 0; i < N; i++) {
        bodies[i].add_position(bodies[i].get_velocity() * timestep);
    }
}


int main() {
    double G = 1;
    int N = 3;
    double timestep = 0.001;
    Body* bodies = new Body[N];
    bodies[0] = Body(1,
        Vec2(-0.9892620043, 0),
        Vec2(0, 1.565553475261424e-05));
    bodies[1] = Body(1,
            Vec2(2.2096177241, 0),
            Vec2(0, 1.5601177764741146e-06));
    bodies[2] = Body(1,
            Vec2(-1.2203557197, 0),
            Vec2(0, -1.721565252990506e-05));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            Vec2 force = get_force(G, bodies[i], bodies[j]);
            bodies[i].add_velocity(force / bodies[i].get_mass());
            bodies[j].add_velocity(-force / bodies[j].get_mass());
        }
    }
    update_positions(N, timestep, bodies);

}