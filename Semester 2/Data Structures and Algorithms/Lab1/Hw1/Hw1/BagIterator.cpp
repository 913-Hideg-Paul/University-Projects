#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->current = 0;
}
//Theta(1)


void BagIterator::first() {
	this->current = 0;
}
//Theta(1)


void BagIterator::next() {
	if (this->current == this->bag.total)
		throw exception();
	else
	{
		this->current++;
	}
}
//Theta(1)


bool BagIterator::valid() const {
	if (this->current < this->bag.total)
	{
		return true;
	}
	return false;
}
//Theta(1)


TElem BagIterator::getCurrent() const
{
	if (this->current == this->bag.total) 
	{
		throw exception();
	}
	else
	{
		int k = this->current;
		int j = this->bag.positions[k];
		return this->bag.elements[j];
	}
	return NULL_TELEM;
}
//Theta(1)
