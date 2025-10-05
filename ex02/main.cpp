#include "FragTrap.hpp"

int main() {
	FragTrap f("Fraggy");
	FragTrap g("Gadget");

	f.attack("Gadget");
	g.takeDamage(f.getAttackDamage());

	g.highFivesGuys();

	for (int i = 0; i < 5; ++i)
		f.beRepaired(7);

	FragTrap h = f;
	h.highFivesGuys();
	return 0;
}
