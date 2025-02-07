/** \file ordering.hpp */
#include <limits>
#pragma once

/** \class Ordering 
*	\brief Very simple class to allow game object to have an order.
* 
*/

class Orderable
{
public:
	uint32_t order{ std::numeric_limits<uint32_t>::max()};
};