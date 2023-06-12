/*******************************************************************
*
*  DESCRIPTION: class storetank
*
*  AUTHOR: Peng Xie
*
*  EMAIL: xie_peng@hotmail.com
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __STORETANK_H
#define __STORETANK_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//class Distribution ;

/** declarations **/
class storetank: public Atomic
{
public:
	storetank( const string &name = "storetank" ) ;	 // Default constructor

	~storetank();					// Destructor

	virtual string className() const
		{return "storetank";}

protected:
	Model &initFunction();
	
	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const   Port &in,&storetankControl_in ;
			Port &out;//,&storetankEmpty_out ;
    int pid ;
	int storetankEmpty;
	Time storeTime,
		 loadingTime;
};	// class storebank


#endif   //__STORETANK_H 
