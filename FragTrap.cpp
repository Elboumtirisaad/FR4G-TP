#include "FragTrap.hpp"

FragTrap::FragTrap() : name_("FragTrap"), hit_points_(100),
                                        MAX_HIT_POINT_(100), energy_points_(100),
                                        MAX_ENERGY_POINTS_(100), level_(1),
                                        melee_attack_damage_(30), ranged_attack_damage_(20),
                                        armor_damage_reduction_(5) {
                                            std::srand(std::time(NULL));
                                            std::cout << "I am cloaking..." << std::endl;
                                        }

FragTrap::FragTrap(std::string name) : name_(name), hit_points_(100),
                                        MAX_HIT_POINT_(100), energy_points_(100),
                                        MAX_ENERGY_POINTS_(100), level_(1),
                                        melee_attack_damage_(30), ranged_attack_damage_(20),
                                        armor_damage_reduction_(5) {
                                            std::srand(std::time(NULL));
                                            std::cout << "I am cloaking..." << std::endl;
                                        }

// Copy Constructor :

FragTrap::FragTrap(FragTrap const & fragtrap) {
    *this = fragtrap;
    std::srand(time(NULL));
    std::cout << "I am cloaking..." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor Called " << std::endl;
}
// Methods implementations : 
void FragTrap::rangedAttack(std::string const & target) {
    std::cout << "FR4G-TP " << name_ << " attacks " << target 
                << " at range , causing " << ranged_attack_damage_ 
                << " points of damage !" << std::endl;
}
// 
void FragTrap::meleeAttack(std::string const & target) {
    std::cout << "FR4G-TP " << name_ << " attacks " << target 
                << " at melee , causing " << melee_attack_damage_ 
                << " points of damage !" << std::endl;
}
// 
void FragTrap::takeDamage(unsigned int amount) {
    amount -= armor_damage_reduction_;
    if(amount >= hit_points_) {
        hit_points_ = 0;
    }
    else {
        hit_points_ -= amount;
    }
    std::cout << "FR4G-TP " << amount 
                << " points take dammage !" << std::endl;
    std::cout << "FR4G-TP " << hit_points_ 
                << " hit points !" << std::endl;           
}
// 
void FragTrap::beRepaired(unsigned int amount) {
    if(hit_points_ + amount >= MAX_HIT_POINT_) {
        hit_points_ = MAX_HIT_POINT_;
    }
    else {
        hit_points_ += amount;
    }
    std::cout << "FR4G-TP " << amount 
                << " points repaired !" << std::endl;

    std::cout << "FR4G-TP " << hit_points_ 
                << " hit points !" << std::endl;        
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
    int value;

    void (FragTrap::*arrAction[5]) (std::string const & target) = {
        &FragTrap::_actionKillbot, &FragTrap::_actionRepulsive, &FragTrap::_actionCombustion,
        &FragTrap::_actionHammer, &FragTrap::_actionHypersion
    };

    int energy = (int) energy_points_ - 25 ;
    if(energy >= 0) {
        energy_points_ -= 25;
        value = rand() % 5;
        (this->*arrAction[value])(target);
    }
    else {
        std::cout << "Issufistant energy !" << std::endl;
    }
	std::cout << "FR4G-TP Energy "
			<< energy_points_
			<< " points !" << std::endl;

}

void FragTrap::_actionKillbot(std::string const & target) {
    std::cout << "Attack Killbot " << std::endl;
    rangedAttack(target);
}

void FragTrap::_actionRepulsive(std::string const & target) {
    std::cout << "Attack Repulsive " << std::endl;
    meleeAttack(target);
}

void FragTrap::_actionCombustion(std::string const & target) {
    std::cout << "Attack Combustion " << std::endl;
    meleeAttack(target);
}

void FragTrap::_actionHammer(std::string const & target) {
    std::cout << "Attack Hammer " << std::endl;
    meleeAttack(target);
}

void FragTrap::_actionHypersion(std::string const & target) {
    std::cout << "Attack hypersion " << std::endl;
    meleeAttack(target);
}

int FragTrap::getHitsPoints(){
    return hit_points_;
}
