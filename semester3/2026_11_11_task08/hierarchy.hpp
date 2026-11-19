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
    ~AK_47() = default;
    void reload();
    void shoot() override;
};



class AK_47_grenade: public AK_47 {
protected:
    int grenade_ammo;
    int grenade_max_ammo;
public:
    AK_47_grenade(int ammo,
        int max_ammo,
        double reload_time,
        double cd_time,
        int grenade_ammo,
        int grenade_max_ammo): AK_47(ammo, max_ammo, reload_time, cd_time) {
    }
    ~AK_47_grenade() = default;
    void launch_grenade();
    void reload_grenade_launcher(int ammo_addition);
    void shoot() override;
};


class Gravity_gun: public Weapon {
protected:
    int battery;
    int max_battery;
    char* dragged_object;
public:
    Gravity_gun(int battery, int max_battery): Weapon() {}
    ~Gravity_gun() = default;
    int get_battery() const;
    int get_max_battery() const;
    char* get_dragged_object();
    void charge(int battery_addition);
    void drag_in(char* object);
    void shoot() override;
};


class Charged_gravity_gun: public Gravity_gun {
public:
    Charged_gravity_gun(int battery, int max_battery): Gravity_gun(battery, max_battery) {};
    Charged_gravity_gun(Gravity_gun& gravity_gun): Gravity_gun(4 * gravity_gun.get_max_battery(), 4 * gravity_gun.get_max_battery()) {};
    ~Charged_gravity_gun() = default;
    void shoot() override;
};
