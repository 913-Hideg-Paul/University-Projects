#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	this->capElems = 1;
	this->capPos = 1;
	this->elements = new TElem[capElems];
	this->positions = new TElem[capPos];
	this->nrElems = 0;
	this->nrPos = 0;
	this->total = 0;
}
//Theta(1)


void Bag::add(TElem elem) {
	int index = 0;
	bool isInBag = false;
	int indexDuplicate = -1000;
	TElem elemPositions;

	if (this->nrElems == this->capElems)
	{
		this->capElems++;
		TElem* newElements = new TElem[this->capElems];

		if (this->elements != NULL)
		{
			for (int i = 0; i < this->nrElems; i++)
			{
				newElements[i] = this->elements[i];
			}
			delete[] this->elements;
		}
		this->elements = newElements;
	}
	if (this->nrPos == this->capPos)
	{
		this->capPos++;
		TElem* newPositions = new TElem[this->capPos];
		if (this->positions != NULL)
		{
			for (int i = 0; i < this->nrPos; i++)
			{
				newPositions[i] = this->positions[i];
			}
		}
		if (this->positions != NULL) {
			delete[] this->positions;
		}
		this->positions = newPositions;
	}

	if (this->nrElems == 0)
	{
		this->elements[0] = elem;
		this->positions[0] = 0;
		this->nrElems++;
		this->nrPos++;
		this->total++;
	}
	else
	{
		index = 0;
		while (index < this->nrElems)
			// we check if the element is unique or is already in the elements container
		{
			bool found = false;
			if (this->elements[index] == elem && found != true)
			{
				isInBag = true;
				indexDuplicate = index;
				found = true;
			}
			index++;
		}

		if (indexDuplicate != -1000) 
		{
			elemPositions = indexDuplicate;
		}
		else
		{
			elemPositions = this->nrElems;
		}
		if (elemPositions == this->nrElems)
		{
			//if the element is unique, we add it to the elements list,
			//as well as the positions list

			this->elements[this->nrElems] = elem;
			this->positions[this->nrPos] = elemPositions;
			this->nrElems++;
			this->nrPos++;
			this->total++;
		}
		else
		{
			//else, we only add it to the positions list,
			//because the elem is already in the elements list

			this->positions[this->nrPos] = elemPositions;
			this->nrPos++;
			this->total++;
		}
	}
}
//Best Case: Theta(1), Worst Case: Theta(nrElems) => Total Complexity = O(nrElems)


bool Bag::remove(TElem elem) {
	int index = 0;
	bool found = false;
	int indexElem = 10000;
	int nrOccurrences = 0;
	while (found != true && index < this->nrElems)
	{
		if (this->elements[index] == elem)
		{
			found = true;
			indexElem = index;
			break;
		}
		index++;
	}
	if (found == false)
	{
		return false;
	}
	else
	{
		int indexPos = 10000;
		bool firstFoundCheck = false;
		for (int i = 0; i < this->nrPos; i++)
		{
			if (indexElem == this->positions[i])
			{
				if (firstFoundCheck == false)
				{
					indexPos = i;
					nrOccurrences++;
					firstFoundCheck = true;
				}
				else
				{
					nrOccurrences++;
				}
			}
		}
		if (elem == -1)
		{
			int c = 0;
		}
		if (nrOccurrences == 1)
		{
			if (this->total == 1)
			{
				this->total = 0;
				this->nrElems = 0;
				this->nrPos = 0;
				return true;
			}
			else
			{
				this->elements[indexElem] = this->elements[this->nrElems - 1];
				nrElems--;
				this->positions[indexPos] = this->positions[this->nrPos - 1];
				nrPos--;
				total--;
				for (int i = 0; i < this->nrPos; i++)
				{
					if (this->positions[i] == this->nrElems)
					{
						this->positions[i] == indexElem;
					}
				}
				return true;
			}
		}
		else
		{
			this->positions[indexPos] = this->positions[this->nrPos - 1];
			nrPos--;
			total--;
			return true;
		}
	}

		/*if (this->total == 1 && nrOccurrences(elem) == 1)
		{
			this->total = 0;
			this->nrElems = 0;
			this->nrPos = 0;
		}
		else {
			while (found != true && index < this->nrElems)
			{
				if (this->elements[index] == elem)
				{
					found = true;
					indexOfFound = index;
					break;
				}
				index++;
			}
			if (found == false)
			{
				return false;
			}
			else
			{
				if (nrOccurrences(elem) == 1)
				{
					this->elements[indexOfFound] = this->elements[this->nrElems - 1];
					bool foundPos = false;
					int k = this->nrPos;
					int j = 0;
					while (k == this->nrPos)
					{
						if (this->positions[j] == indexOfFound)
						{
							this->positions[j] = this->positions[this->nrPos - 1];
							k--;
							break;
						}
						j++;
					}
					this->nrElems--;
					this->nrPos--;
					this->total--;
					return true;
				}
				else
				{
					index = 0;
					found = false;
					for (int index = 0; index < this->nrPos; index++)
					{
						if (indexOfFound == this->positions[index])
						{
							found = true;
							this->positions[index] = this->positions[this->nrPos-1];
							this->nrPos--;
							this->total--;
							break;
						}
					}
					return true;
				}
			}
		}*/
}
//Best Case: Theta(nrElems + nrPos), Worst Case: 


bool Bag::search(TElem elem) const {
	int index = 0;
	bool found = false;
	while (found != true && index < this->nrElems)
	{
		if (this->elements[index] == elem)
		{
			found = true;
			return true;
		}
		index++;
	}
	return false; 
}
// Best case: Theta(1), Worst case: Theta(nrElems) = > Total Complexity = O(nrElems)

int Bag::nrOccurrences(TElem elem) const {
	int index = 0;
	bool found = false;
	int indexOfFound = 10;
	int nrOccurrences = 0;
	while(found != true && index < this->nrElems)
	{
		if (this->elements[index] == elem)
		{
			found = true;
			indexOfFound = index;
		}
		index++;
	}
	if (found == false)
	{
		return nrOccurrences;
	}
	else
	{
		for (int i = 0; i < this->nrPos; i++)
		{
			if (indexOfFound == this->positions[i])
			{
				nrOccurrences++;
			}
		}
		return nrOccurrences;
	}
}
//Best Case: Theta(1), Worst Case: Theta(nrElems + nrPos) => Total Complexity = O(nrElems + nrPos)


int Bag::size() const {
	return this->total;
}
//Theta(1)


bool Bag::isEmpty() const {
	if (this->nrElems == 0)
		return true;
	return false;
}
//Theta(1)


BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] this->elements;
	delete[] this->positions;
}
//Theta(1)
