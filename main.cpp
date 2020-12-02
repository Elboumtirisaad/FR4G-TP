#include<iostream>
#include "FragTrap.hpp"

int main() {

    std::cout << ">>>>>>>>>> Game Begin >>>>>>>>>>>>>" << std::endl;

    FragTrap ft1("GFRG");
    while (ft1.getHitsPoints() > 0)
    {
        ft1.beRepaired(10);
        ft1.takeDamage(25);
        ft1.rangedAttack("Alien");
        ft1.meleeAttack("Monstre");
        std::cout << std::endl;
		std::cout << "Hit Points: " << ft1.getHitsPoints() << std::endl;        
    }
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    FragTrap ft2("GI-JO");
    while (ft2.getHitsPoints() > 0)
    {
        ft2.beRepaired(5);
        ft2.takeDamage(15);
        ft2.rangedAttack("Monstre");
        ft2.meleeAttack("Alien");
        ft2.vaulthunter_dot_exe("Monstre");
        std::cout << std::endl;
		std::cout << "Hit Points: " << ft2.getHitsPoints() << std::endl;        
    }



    return 0;
}