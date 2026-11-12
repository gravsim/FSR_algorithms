#include <iostream>
#include "hierarchy.hpp"


AK_47::AK_47(int ammo, int max_ammo, double reload_time, double cd_time) {
    this->ammo = ammo;
    this->max_ammo = max_ammo;
    this->reload_time = reload_time;
    this->cd_time = cd_time;
}


void AK_47::reload(int ammo_addition) {
    if (ammo + ammo_addition > max_ammo) {
        ammo = max_ammo;
    } else {
        ammo += ammo_addition;
    }
}


void AK_47::shoot() {
    if (ammo > 0) {
        ammo -= 1;
        std::cout << "Ratatata!!!";
    } else {
        std::cout << "No ammo!\n";
    }
}


AK_47_grenade::AK_47_grenade(int ammo,
        int max_ammo,
        double reload_time,
        double cd_time,
        int grenade_launcher_ammo,
        int grenade_launcher_max_ammo): AK_47(ammo, max_ammo, reload_time, cd_time)  {
            this->grenade_launcher_ammo = grenade_launcher_ammo;
            this->grenade_launcher_max_ammo = grenade_launcher_max_ammo;

}


int main() {
    double n;

    std::cout << "Program finished.";
    return 0;
}
