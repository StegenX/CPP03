#include "DiamondTrap.hpp"

int main() {
	DiamondTrap d("Diamondy");
	d.attack("TargetDummy");
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();

	DiamondTrap e = d;
	e.whoAmI();
	return 0;
}
