#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"


const char* message = DEF_MSG;

//// Box ////////////


void _ZN3BoxC1Ed(Box *const this, double dim) 
{  
	this->length = dim;
	this->width = dim;
	this->height = dim; 
   	_ZNK3Box5printEv(this);
}

void _ZN3BoxC1Eddd(Box *const this, double l, double w, double h) 
{
	this->length = l;
   	this->width = w;
   	this->height = h;
    	_ZNK3Box5printEv(this); 
}

void _ZN3BoxD1Ev(const Box *const this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

Box *_ZN3BoxmLEd(Box *const this, double mult)
{
    	this->width *= mult;
    	this->height *= mult;
    	this->length *= mult;

    	return this;
}

void _ZNK3Box5printEv(const Box *const this)
{
    	printf("Box: %f x %f x %f\n", this->length, this->width, this->height); 
}

bool _ZeqRK3BoxS1_(const Box *lhs, const Box *rhs)
{
	return lhs->width == rhs->width && lhs->height == rhs->height && lhs->length == rhs->length;
}
Box _ZmldRK3Box(const Box *const box, double mult)
{
    	Box ret;
	ret = *box;
    	_ZN3BoxmLEd(&ret, mult);
    	return ret;
}

Box _ZmlRK3Boxd(double mult, const Box *const box)
{
    return _ZmldRK3Box(box, mult);
}


//// Shelf ////////////

void _ZN3ShelfC1E(Shelf *const this)
{
	Box box;
	for(int i = 0; i < NUM_BOXES; i++)
	{
		_ZN3BoxC1Ed(&box, 1);
		_ZN5Shelf6setBoxEiRK3Box(this, i, &box);
	}

}

void _ZN5Shelf6setBoxEiRK3Box(Shelf *const this, int index, const Box *dims)
{
    this->boxes[index] = *dims;
}

double _ZNK5Shelf9getVolumeEv(const Shelf *const this)
{
    double vol = 0;
    for(size_t i = 0; i < NUM_BOXES; ++i)
        vol += this->boxes[i].length * this->boxes[i].width * this->boxes[i].height;

    return vol;
}

void _ZNK5Shelf5printEv(const Shelf *const this)
{
    printf("%s %f\n", message, _ZNK5Shelf9getVolumeEv(this));
}

Box _ZN5Shelf6getBoxEiRK2Box(const Shelf *const this, int index)
{
    return this->boxes[index];
}


