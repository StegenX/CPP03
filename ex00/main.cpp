#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Alpha");
	ClapTrap b("Beta");

	a.setAttackDamage(3);
	b.setAttackDamage(2);

	a.attack("Beta");
	b.takeDamage(a.getAttackDamage());

	b.attack("Alpha");
	a.takeDamage(b.getAttackDamage());

	b.beRepaired(5);
	for (int i = 0; i < 12; ++i)
		a.attack("Training Dummy");

	ClapTrap c = a;
	c.beRepaired(1);
	return 0;
}
