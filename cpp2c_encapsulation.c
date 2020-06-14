#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"


static Box largeBox;

void thisFunc()
{
	printf("\n--- thisFunc() ---\n\n"); 
    	static Box box99;
	static bool is_fist_call = 1;
	if(is_fist_call == 1)
	{
		is_fist_call = 0;
		_ZN3BoxC1Eddd(&box99, 99, 99, 99);
	}
    	_ZN3BoxmLEd(&box99, 10);
}

void thatFunc()
{
    	printf("\n--- thatFunc() ---\n\n"); 
    	static Box box88;
	static bool is_fist_call = 1;
	if(is_fist_call == 1)
	{
		is_fist_call = 0;
		_ZN3BoxC1Eddd(&box88, 88, 88, 88);
	}
	_ZN3BoxmLEd(&box88, 10);
}

void doBoxes()
{
	printf("\n--- Start doBoxes() ---\n\n");

    	Box b1;
	_ZN3BoxC1Ed(&b1, 3);
    	Box b2;
	_ZN3BoxC1Eddd(&b2, 4, 5, 6);
    
    	printf("b1 volume: %f\n", b1.length * b1.width * b1.height);
    	printf("b2 volume: %f\n", b2.length * b2.width * b2.height);

    	_ZN3BoxmLEd(&b1, 1.5);
    	_ZN3BoxmLEd(&b2, 0.5);

    	printf("b1 volume: %f\n", b1.length * b1.width * b1.height);
	printf("b2 volume: %f\n", b2.length * b2.width * b2.height);

	Box b3 = b2;
	Box b4 = _ZmlRK3Boxd(3, &b2);
	printf("b3 %s b4\n", _ZeqRK3BoxS1_(&b3, &b4)? "equals" : "does not equal");

	_ZN3BoxmLEd(&b3, 1.5);
	_ZN3BoxmLEd(&b4, 0.5);
	printf("Now, b3 %s b4\n",  _ZeqRK3BoxS1_(&b3, &b4) ? "equals" : "does not equal");

	printf("\n--- End doBoxes() ---\n\n");
	_ZN3BoxD1Ev(&b4);
	_ZN3BoxD1Ev(&b3);
	_ZN3BoxD1Ev(&b2);
	_ZN3BoxD1Ev(&b1);

}


void doShelves()
{
	printf("\n--- start doShelves() ---\n\n");

    	Box aBox;
	_ZN3BoxC1Ed(&aBox, 5);

    	Shelf aShelf;
	_ZN3ShelfC1E(&aShelf);
    	_ZNK5Shelf5printEv(&aShelf);
    	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &largeBox);
    	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    	_ZNK5Shelf5printEv(&aShelf);
    	message = "This is the total volume on the shelf:";
    	_ZNK5Shelf5printEv(&aShelf);
    	message = "Shelf's volume:";
   	_ZNK5Shelf5printEv(&aShelf);

	Box b1;
	_ZN3BoxC1Eddd(&b1, 2, 4, 6);
	_ZN3BoxD1Ev(&b1);
    	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &b1);

	Box b2;
	_ZN3BoxC1Ed(&b2, 2);
    	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &b2);
	_ZN3BoxD1Ev(&b2);
    	_ZNK5Shelf5printEv(&aShelf);

    	printf("\n--- end doShelves() ---\n\n");
	for(int i = NUM_BOXES-1; i >= 0 ; i--)
	{
		_ZN3BoxD1Ev(&aShelf.boxes[i]);
	}
	_ZN3BoxD1Ev(&aBox);
}

int main()
{
	_ZN3BoxC1Eddd(&largeBox, 10, 20,30);

   	printf("\n--- Start main() ---\n\n");

   	doBoxes();

   	thisFunc();
    	thisFunc();
    	thisFunc();
    	thatFunc();
    	thatFunc();

	doShelves();
        
    	printf("\n--- End main() ---\n\n");
	_ZN3BoxD1Ev(&largeBox);
    	return 0;
}

