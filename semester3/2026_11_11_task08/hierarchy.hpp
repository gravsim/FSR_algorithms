#include <iostream>


class Weapon {
protected:
    int ammo;
    int max_ammo;
    double reload_time;
    double cd_time;
public:
    Weapon(int ammo, int max_ammo, double reload_time, double cd_time);
    virtual ~Weapon() = default;
    virtual void shoot();
    void reload();
};


class AK_47: public Weapon {
public:
    AK_47(int ammo, int max_ammo, double reload_time, double cd_time): Weapon(ammo, max_ammo, reload_time, cd_time) {}

};



class AK_47_grenade: public AK_47 {
protected:
    int grenade_launcher_ammo;
    int grenade_launcher_max_ammo;
public:
    AK_47_grenade(int ammo,
        int max_ammo,
        double reload_time,
        double cd_time,
        int grenade_launcher_ammo,
        int grenade_launcher_max_ammo): AK_47(ammo, max_ammo, reload_time, cd_time) {
    }
    void shoot_grenade_launcher();
};


class Gravity_gun: Weapon {
protected:

public:
    Gravity_gun(int ammo,
        int max_ammo,
        double reload_time,
        double cd_time): Weapon(ammo, max_ammo, reload_time, cd_time) {}
    void drag_in();
};
