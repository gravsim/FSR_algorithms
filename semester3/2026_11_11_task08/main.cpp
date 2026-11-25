#include <iostream>
#include "hierarchy.cpp"


int main() {
    AK_47 ak_47 = AK_47(15, 100);
    AK_47_grenade ak_47_grenade = AK_47_grenade(10, 100, 1, 2);
    Gravity_gun gravity_gun = Gravity_gun(1, 100);
    Charged_gravity_gun charged_gravity_gun = Charged_gravity_gun(1, 100);

    ak_47.shoot();
    ak_47_grenade.shoot();
    gravity_gun.shoot();
    charged_gravity_gun.shoot();

    std::cout << "\n";

    ak_47.reload();
    ak_47_grenade.reload();
    gravity_gun.reload();
    charged_gravity_gun.reload();

    std::cout << "\n";

    gravity_gun.drag_in();
    charged_gravity_gun.drag_in();
    gravity_gun.drop();
    charged_gravity_gun.drop();

    std::cout << "\n";

    ak_47_grenade.launch_grenade();

    return 0;
}
