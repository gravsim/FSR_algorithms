#include "body.cpp"
#include <fstream>


void update_positions(int N, double timestep, Body* bodies) {
    for (int i = 0; i < N; i++) {
        bodies[i].add_position(bodies[i].get_velocity() * timestep);
    }
}


void update_velocities(int N, double timestep, double G, Body* bodies) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            Vec2 force = get_force(G, bodies[i], bodies[j]);
            bodies[i].add_velocity(force / bodies[i].get_mass() * timestep);
            bodies[j].add_velocity(-force / bodies[j].get_mass() * timestep);
        }
    }
}


void print_bodies(int N, Body* bodies) {
    for (int i = 0; i < N; i++) {
        std::cout << bodies[i] << "\n";
    }
}


void write_bodies(int N, Body* bodies, std::ofstream& outfile) {
    for (int i = 0; i < N; i++) {
        outfile << bodies[i] << "\n";
    }
}


int main() {
    double G = 1;
    int N = 3;
    double end_time = 5000000;
    double write_period = 1000;
    double timestep = 10;
    int steps = (int)end_time / timestep;
    Body* bodies = new Body[N];
    bodies[0] = Body(6.67e-11,
        Vec2(-0.9892620043, 0),
        Vec2(0, 1.565553475261424e-05));
    bodies[1] = Body(6.67e-11,
            Vec2(2.2096177241, 0),
            Vec2(0, 1.5601177764741146e-06));
    bodies[2] = Body(6.67e-11,
            Vec2(-1.2203557197, 0),
            Vec2(0, -1.721565252990506e-05));

    std::ofstream outfile("results.txt", std::ios_base::app);
    for (double time = 0; time < end_time; time += timestep) {
        update_velocities(N, timestep, G, bodies);
        update_positions(N, timestep, bodies);
        if (time % write_period == 0) {
            write_bodies(N, bodies, outfile);
        }

    }
    print_bodies(N, bodies);
    outfile.close();
    delete[] bodies;
}
