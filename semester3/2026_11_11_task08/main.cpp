#include <iostream>
#include "hierarchy.hpp"


int main() {
    AK_47* ak_47 = new AK_47(15, 100);
    AK_47_grenade* ak_47_grenade = new AK_47_grenade(10, 100, 1, 2);
    Gravity_gun* gravity_gun = new Gravity_gun(1, 100);
    Charged_gravity_gun* charged_gravity_gun = new Charged_gravity_gun(1, 400);

    ak_47->shoot();
    ak_47_grenade->shoot();
    gravity_gun->shoot();
    charged_gravity_gun->shoot();

    std::cout << "\n";

    ak_47->reload();

    std::cout << ak_47_grenade->get_ammo() << "\n";
    ak_47_grenade->reload();
    std::cout << ak_47_grenade->get_ammo() << "\n";
    gravity_gun->reload();
    

    std::cout << charged_gravity_gun->get_battery() << "\n";
    charged_gravity_gun->reload();
    std::cout << charged_gravity_gun->get_battery() << "\n";

    std::cout << "\n";

    gravity_gun->drag_in();
    charged_gravity_gun->drag_in();
    gravity_gun->drop();
    charged_gravity_gun->drop();

    std::cout << "\n";

    ak_47_grenade->launch_grenade();

    return 0;
}
