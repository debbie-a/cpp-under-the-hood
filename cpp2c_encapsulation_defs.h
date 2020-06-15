#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__
#include <stdbool.h> 
#define NUM_BOXES 3



//// Box ////////////

typedef struct Box
{	
	double length;
    	double width;
    	double height;
}Box;

//// Box Defs ////////////


/*Box(double dim );*/
void _ZN3BoxC1Ed(Box *const, double);

/*Box(double l, double w, double h);*/
void _ZN3BoxC1Eddd(Box *const, double l, double w, double h);

/*~Box();*/
void _ZN3BoxD1Ev(const Box *const);

/*Box& operator*=(double mult);*/
Box* _ZN3BoxmLEd(Box *const, double mult);

/*void print() const;*/
void _ZNK3Box5printEv(const Box *const);



//// Shelf ////////////

typedef struct Shelf
{
	Box boxes[NUM_BOXES];
}Shelf;

//// Shelf Defs ////////////

/*Shelf ctor*/
void _ZN3ShelfC1E(Shelf *const);

/*void setBox(int index, const Box& dims);*/
void _ZN5Shelf6setBoxEiRK3Box(Shelf *const, int index, const Box *dims);

/*double getVolume() const;*/
double _ZNK5Shelf9getVolumeEv(const Shelf *const);

/*void print() const;*/
void _ZNK5Shelf5printEv(const Shelf *const);


#endif // __CPP2C_ENCAPSULATION_DEFS_H__

