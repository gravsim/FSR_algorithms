#include <iostream>


class Weapon {
protected:
    
public:
    Weapon();
    virtual ~Weapon() = default;
    virtual void shoot();
};


class AK_47: public Weapon {
protected:
    int ammo;
    int max_ammo;
    double reload_time;
    double cd_time;
public:
    AK_47(int ammo, int max_ammo, double reload_time, double cd_time);
    void reload(int ammo_addition);
    void shoot() override;
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
    void launch_grenade();
    void reload_grenade_launcher(int ammo_addition);
};


class Gravity_gun: Weapon {
protected:

public:
    Gravity_gun(int ammo,
        int max_ammo,
        double reload_time,
        double cd_time): Weapon() {}
    void drag_in();
};


class Charged_gravity_gun: Gravity_gun {
protected:

public:
    Charged_gravity_gun(int ammo,
        int max_ammo,
        double reload_time,
        double cd_time): Gravity_gun(ammo, max_ammo, reload_time, cd_time) {}
    void drag_in_biomass();
};
