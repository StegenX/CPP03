#include "ScavTrap.hpp"

int main() {
	ScavTrap s("Sentinel");
	ScavTrap t("Tower");

	s.attack("Tower");
	t.takeDamage(s.getAttackDamage());

	t.guardGate();
	t.attack("Sentinel");
	s.takeDamage(t.getAttackDamage());

	for (int i = 0; i < 3; ++i)
		s.beRepaired(10);

	ScavTrap u = s;
	u.guardGate();
	return 0;
}
