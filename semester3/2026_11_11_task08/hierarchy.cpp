#include <iostream>
#include "hierarchy.hpp"



void Weapon::shoot() {
    std::cout << "Shot!\n";
}



AK_47::AK_47(int ammo, int max_ammo) {
    this->ammo = ammo;
    this->max_ammo = max_ammo;
}


void AK_47::reload() {
    ammo = max_ammo;
    std::cout << "Weapon reloaded.\n";
}



AK_47_grenade::AK_47_grenade(int ammo,
        int max_ammo,
        int grenade_launcher_ammo,
        int grenade_launcher_max_ammo): AK_47(ammo, max_ammo)  {
            this->grenade_ammo = grenade_launcher_ammo;
            this->grenade_max_ammo = grenade_launcher_max_ammo;
}


void AK_47_grenade::launch_grenade() {
    if (grenade_ammo > 0) {
        grenade_ammo -= 1;
        std::cout << "BOOM!!!\n";
    } else {
        std::cout << "No grenade ammo!\n";
    }
}

void AK_47_grenade::reload_grenade_launcher() {
    grenade_max_ammo = max_ammo;
    std::cout << "Grenade launcher reloaded.\n";
}


Gravity_gun::Gravity_gun(int battery, int max_battery) {
    this->battery = battery;
    this->max_battery = max_battery;
    dragged = false;
}


int Gravity_gun::get_battery() const {
    return battery;
}


int Gravity_gun::get_max_battery() const {
    return max_battery;
}


void Gravity_gun::reload() {
    battery = max_battery;
    std::cout << "Weapon reloaded.\n";
}


bool Gravity_gun::is_dragged() const {
    return dragged;
}


void Gravity_gun::drag_in() {
    this->dragged = true;
    std::cout << "Object dragged.\n";
}


void Gravity_gun::drop() {
    if (dragged) {
        dragged = false;
        std::cout << "Object dropped.\n";
    } else {
        std::cout << "No object.\n";
    }
}


Charged_gravity_gun::Charged_gravity_gun(int battery, int max_battery): Gravity_gun(battery, max_battery)  {
}


Charged_gravity_gun::Charged_gravity_gun(Gravity_gun &gravity_gun):
    Gravity_gun(4 * gravity_gun.get_max_battery(), 4 * gravity_gun.get_max_battery()) {
}


void Charged_gravity_gun::drag_in() {
    this->dragged = true;
    std::cout << "Body dragged.\n";
}


void Charged_gravity_gun::drop() {
    if (dragged) {
        dragged = false;
        std::cout << "Body dropped.\n";
    } else {
        std::cout << "No body.\n";
    }
}

