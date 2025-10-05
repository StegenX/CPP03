#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Diamond_clap_name"), ScavTrap("Diamond"), FragTrap("Diamond"), _name("Diamond") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap default constructed: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap constructed: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other._name + "_clap_name"), ScavTrap(other), FragTrap(other), _name(other._name) {
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap copy constructed: " << _name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destroyed: " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name
	          << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
