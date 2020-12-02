#pragma once
#include<iostream> 
#include<string>
#include<ctime>

class FragTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const & fragtrap);
    ~FragTrap();
    void rangedAttack(std::string const & target);
    void meleeAttack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const & target);
    int getHitsPoints() ;
private:
    unsigned int hit_points_;
    unsigned int MAX_HIT_POINT_;
    unsigned int energy_points_;
    unsigned int MAX_ENERGY_POINTS_ ;
    unsigned int level_;
    std::string name_;
    unsigned int melee_attack_damage_;
    unsigned int ranged_attack_damage_;
    unsigned int armor_damage_reduction_;

    void _actionKillbot(std::string const & target);
    void _actionRepulsive(std::string const & target);
    void _actionCombustion(std::string const & target);
    void _actionHammer(std::string const & target);
    void _actionHypersion(std::string const & target);
};