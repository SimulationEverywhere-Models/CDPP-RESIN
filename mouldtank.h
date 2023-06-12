/*******************************************************************
*
*  DESCRIPTION: class mouldtank
*
*  AUTHOR: Peng Xie
*
*  EMAIL: xie_peng@hotmail.com
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __mouldtank_H
#define __mouldtank_H

/** include files **/
#include "atomic.h"  // class Atomic
//#include "package.h"
/** declarations **/
class mouldtank: public Atomic
{
public:
	mouldtank( const string &name = "mouldtank" ) ;	 // Default constructor

	~mouldtank();					// Destructor

	virtual string className() const
		{return "mouldtank";}

protected:
	Model &initFunction();
	
	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in, &start_in;
	Port &out,&mouldtankTemp_out;
	Value WARM,ISOLATOR;
	Time mouldtankHeatingtime,
		 mouldtankMouldingtime,
		 mouldtankWarmkeepingtime;
	int pid;
};	// class mouldtank


#endif   //__mouldtank_H 
