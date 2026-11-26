#include <iostream>


class Weapon {
public:
    virtual ~Weapon() = default;
    void shoot();
    virtual void reload() = 0;
};


class AK_47: public Weapon {
protected:
    int ammo;
    int max_ammo;
public:
    AK_47(int ammo, int max_ammo);
    ~AK_47() override = default;
    void reload() override;
};


class AK_47_grenade: public AK_47 {
protected:
    int grenade_ammo;
    int grenade_max_ammo;
public:
    AK_47_grenade(int ammo,
        int max_ammo,
        int grenade_ammo,
        int grenade_max_ammo);
    ~AK_47_grenade() override = default;
    void launch_grenade();
    void reload_grenade_launcher();
};


class Gravity_gun: public Weapon {
protected:
    int battery;
    int max_battery;
    bool dragged;
public:
    Gravity_gun(int battery, int max_battery);
    ~Gravity_gun() override = default;
    int get_battery() const;
    int get_max_battery() const;

    bool is_dragged() const;
    void drag_in();
    void drop();
    void reload() override;
};


class Charged_gravity_gun: public Gravity_gun {
public:
    Charged_gravity_gun(int battery, int max_battery);
    explicit Charged_gravity_gun(Gravity_gun& gravity_gun);
    ~Charged_gravity_gun() override = default;
    void drag_in();
    void drop();
};
