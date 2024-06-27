#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>


int		main( void ) 
{
	//alias

	Account t;
	t.setTotalAmount(10);
	std::cout << t.getTotalAmount();
}
