#include <iostream>
#include "hierarchy.hpp"


AK_47::AK_47(int ammo, int max_ammo, double reload_time, double cd_time) {
    this->ammo = ammo;
    this->max_ammo = max_ammo;
    this->reload_time = reload_time;
    this->cd_time = cd_time;
}


void AK_47::reload() {
    ammo = max_ammo;
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


void AK_47_grenade::launch_grenade() {
    
}


Gravity_gun::Gravity_gun(int battery, int max_battery) {
    dragged_object = nullptr;
    this->battery = battery;
    this->max_battery = max_battery;
}


int Gravity_gun::get_battery() const {
    return battery;
}


int Gravity_gun::get_max_battery() const {
    return max_battery;
}


char* Gravity_gun::get_dragged_object() {
    return dragged_object;
}


void Gravity_gun::charge(int battery_addition) {
    if (battery + battery_addition < max_battery) {
        battery = battery + battery_addition;
    } else {
        battery = max_battery;
    }
}


void Gravity_gun::drag_in(char* object) {
    dragged_object = object;
}


void Gravity_gun::shoot() {
    if (dragged_object != nullptr) {
        std::cout << "Object " << dragged_object << " is thrown.";
    }
    std::cout << "There is no object to throw";
}


void Charged_gravity_gun::shoot() {
    if (dragged_object != nullptr) {
        std::cout << "Body " << dragged_object << " is thrown.";
    }
    std::cout << "There is no body to throw";
}
