#include <assert.h>
#include "Matrix.h"

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);

	//test for extra op
	Matrix n(3, 3);
	for (int i = 0; i < n.nrLines(); i++) {
		for (int j = 0; j < n.nrColumns(); j++) {
			if (i > j) {
				n.modify(i, j, 5);
			}
			if (i < j) {
				n.modify(i, j, 1);
			}
			if (i == j) {
				n.modify(i, j, 10);
			}
		}
	}
	n.transpose();
	for (int i = 0; i < n.nrLines(); i++) {
		for (int j = 0; j < n.nrColumns(); j++) {
			if (i > j) {
				assert(n.element(i, j) == 1);
			}
			if (i < j) {
				assert(n.element(i, j) == 5);
			}
			if (i == j) {
				assert(n.element(i, j) == 10);
			}
		}
	}
}