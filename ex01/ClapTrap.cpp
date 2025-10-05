#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Anon"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructed: " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructed: " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap copy constructed: " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destroyed: " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't attack."
		          << " HP: " << _hitPoints << ", EP: " << _energyPoints << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
	          << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already down." << std::endl;
		return;
	}
	unsigned int dmg = amount;
	if (dmg > _hitPoints)
		dmg = _hitPoints;
	_hitPoints -= dmg;
	std::cout << "ClapTrap " << _name << " takes " << dmg << " damage, HP: "
	          << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " can't repair."
		          << " HP: " << _hitPoints << ", EP: " << _energyPoints << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs for " << amount << ", HP: "
	          << _hitPoints << std::endl;
}

const std::string &ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }
void ClapTrap::setAttackDamage(unsigned int amount) { _attackDamage = amount; }
