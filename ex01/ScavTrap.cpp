#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavAnon") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = false;
	std::cout << "ScavTrap default constructed: " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = false;
	std::cout << "ScavTrap constructed: " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	_guarding = other._guarding;
	std::cout << "ScavTrap copy constructed: " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destroyed: " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_guarding = other._guarding;
	}
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " can't attack."
		          << " HP: " << _hitPoints << ", EP: " << _energyPoints << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " slashes " << target
	          << " for " << _attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate() {
	_guarding = !_guarding;
	std::cout << "ScavTrap " << _name
	          << ( _guarding ? " has entered Gate Keeper mode" : " has left Gate Keeper mode" )
	          << std::endl;
}
