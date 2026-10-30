#include "body.cpp"
#include <fstream>
#include <chrono>


void update_positions(int N, double timestep, Body* bodies) {
    for (int i = 0; i < N; i++) {
        bodies[i].add_position(bodies[i].get_velocity() * timestep);
    }
}


void update_velocities(int N, double timestep, double G, Body* bodies) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            Vec2 force = get_force(G, bodies[i], bodies[j]);
            bodies[i].add_velocity(force * bodies[j].get_mass() * timestep);
            bodies[j].add_velocity(-force * bodies[i].get_mass() * timestep);
        }
    }
}


void print_bodies(int N, Body* bodies) {
    for (int i = 0; i < N; i++) {
        std::cout << bodies[i] << "\n";
    }
}


void write_bodies(int N, Body body, std::ofstream& outfile) {
    outfile << body << "\n";
}


int main() {
    double G = 6.67e-11;
    int N = 3;
    double end_time = 500000;
    double write_period = 20;
    double timestep = 0.5;
    int steps = (int)end_time / timestep;
    int write_steps = (int)write_period / timestep;
    Body* bodies = new Body[N];
    bodies[0] = Body(1,
        Vec2(-0.5, 0),
        Vec2(0, 0.0));
    bodies[1] = Body(0.1,
            Vec2(0.5, 0),
            Vec2(0, 0.0));
    bodies[2] = Body(0.01,
            Vec2(0.2637098062, 0.3223452642),
            Vec2(0, 0.0));

    std::ofstream* outfiles = new std::ofstream[N];
    for (int i = 0; i < N; i++) {
        std::string name = "body" + std::to_string(i) + ".txt";
        outfiles[i].open(name, std::ios_base::out);
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int step = 0; step < steps; step ++) {
        update_velocities(N, timestep, G, bodies);
        update_positions(N, timestep, bodies);
        if (step % write_steps == 0) {
            for (int i = 0; i < N; i++) {
                bodies[i].write_position(outfiles[i]);
            }
            std::cout << "Calculation: " << (int)((double)step * 100 / (double)steps) << "%" << "\r" << std::flush;
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << "Time: " << ms_double.count() / 1000 << " sec\n";
    print_bodies(N, bodies);
    for (int i = 0; i < N; i++) {
        outfiles[i].close();
    }
    delete[] bodies;
    delete[] outfiles;
}
