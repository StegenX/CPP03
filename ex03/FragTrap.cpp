#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragAnon") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructed: " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructed: " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructed: " << _name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destroyed: " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::attack(const std::string &target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "FragTrap " << _name << " can't attack."
		          << " HP: " << _hitPoints << ", EP: " << _energyPoints << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " blasts " << target
	          << " for " << _attackDamage << " damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << ": High fives, guys?" << std::endl;
}
