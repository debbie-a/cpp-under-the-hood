#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

extern const char* message;

static Box largeBox;
static Box box99;
static Box box88;

static void init_largeBox()
{
	 _ZN3BoxC1Eddd(&largeBox, 10, 20,30);
}
static void destroy_staticBox()
{
	_ZN3BoxD1Ev(&box88);
	_ZN3BoxD1Ev(&box99);
	_ZN3BoxD1Ev(&largeBox);
}

void thisFunc()
{
	printf("\n--- thisFunc() ---\n\n"); 
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
	Box b4 = b2;
	_ZN3BoxmLEd(&b4, 2);
	printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length? "equals" : "does not equal");

	_ZN3BoxmLEd(&b3, 1.5);
	_ZN3BoxmLEd(&b4, 0.5);
	printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length? "equals" : "does not equal");

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

void __attribute__((constructor)) init_largeBox();
void __attribute__((destructor)) destroy_staticBox();

int main()
{
   	printf("\n--- Start main() ---\n\n");

   	doBoxes();

   	thisFunc();
    	thisFunc();
    	thisFunc();
    	thatFunc();
    	thatFunc();

	doShelves();
        
    	printf("\n--- End main() ---\n\n");

    	return 0;
}

