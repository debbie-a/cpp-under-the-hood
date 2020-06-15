#include "cpp2c_encapsulation_defs.h"
#include "stdio.h"
extern const char* message;

static Box largeBox;
static Box box99;
static Box box88;


static void init_largeBox()
{
	ctorBoxBDDD(&largeBox, 10, 20,30);
}

static void destroy_staticBox()
{
	dtorBox(&box88);
	dtorBox(&box99);
	dtorBox(&largeBox);
}


void thisFunc()
{
	printf("\n--- thisFunc() ---\n\n"); 
	static bool is_fist_call = 1;
	if(is_fist_call == 1)//זה בגלל שבוקס99 הוא סטאטי זה אומר שלא אמור לאתחל אותו בכל קריאה לפונקציה הוא נשמר מהקריאה הקודמת ולכן לא נרצה שייקרא הקונסטרקטור שלו שוב ושוב בכל קריאה ולכן רק בקריאה הראשונה
	{
		is_fist_call = 0;
		ctorBoxBDDD(&box99, 99, 99, 99);
	}
	opreatorMultBD(&box99,10);
}

void thatFunc()
{
	printf("\n--- thatFunc() ---\n\n"); 
	static bool is_fist_call = 1;
	if(is_fist_call == 1)
	{
		is_fist_call = 0;
		ctorBoxBDDD(&box88, 88,88,88);
	}
	opreatorMultBD(&box88,10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    	Box b1;
	ctorBoxBD(&b1,3);
    	Box b2;
	ctorBoxBDDD(&b2, 4,5,6);

	printf("b1 volume: %d\n", 27);
	printf("b2 volume: %d\n", 120);

	opreatorMultBD(&b1,1.5);
	opreatorMultBD(&b2,0.5);


	printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
	printf("b2 volume: %f\n", b2.width * b2.length * b2.height);


    	Box b3 = b2;
	/*ctorBoxBD(&b3,1);
	b3.width=b2.width;
	b3.length=b2.length;
	b3.height=b2.height;*/ 
	
	Box b4 = b2;
	opreatorMultBD(&b4,3);
	/*ctorBoxBD(&b4,1);
	b4.width=b2.width*3;
	b4.length=b2.length*3;
	b4.height=b2.height*3;*/
    
	
	printf("b3 %s b4\n", (b3.width == b4.width)&& (b3.length == b4.length)&&(b3.height == b4.height) ? "equals" : "does not equal");

	opreatorMultBD(&b3,1.5);
	opreatorMultBD(&b4,0.5);

	printf("Now, b3 %s b4\n", (b3.width == b4.width)&& (b3.length == b4.length)&&(b3.height == b4.height) ? "equals" : "does not equal");

	printf("\n--- End doBoxes() ---\n\n");
	dtorBox(&b4);
	dtorBox(&b3);
	dtorBox(&b2);
	dtorBox(&b1);
}


void doShelves()
{
	printf("\n--- start doShelves() ---\n\n");

	Box aBox;
	ctorBoxBD(&aBox,5);
	Shelf aShelf;
	//TODO call shelf_ctor(&aShelf);

	printS(&aShelf);
	setBoxSIB(&aShelf,1, &largeBox);
	setBoxSIB(&aShelf,0, &aBox);

	printS(&aShelf);
	message="This is the total volume on the shelf:";
	printS(&aShelf);
	message="Shelf's volume:";
	printS(&aShelf);

	Box b5;
	ctorBoxBDDD(&b5, 2,4,6);
	setBoxSIB(&aShelf,1, &b5);
	dtorBox(&b5);

	Box b6;
	ctorBoxBD(&b6,2);
	setBoxSIB(&aShelf,2, &b6);
	dtorBox(&b6);

	printS(&aShelf);
	
	printf("\n--- end doShelves() ---\n\n");

	for(int i = NUM_BOXES-1; i >= 0 ; i--)
	{
		dtorBox(&aShelf.boxes[i]);
	}
	dtorBox(&aBox);
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


