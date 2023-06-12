/*******************************************************************
*
*  DESCRIPTION: class mixtank
*
*  AUTHOR: Peng Xie
*
*  EMAIL: xie_peng@hotmail.com
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __mixtank_H
#define __mixtank_H

/** include files **/
#include "atomic.h"  // class Atomic
//#include "package.h"
/** declarations **/
class mixtank: public Atomic
{
public:
	mixtank( const string &name = "mixtank" ) ;	 // Default constructor

	~mixtank();					// Destructor

	virtual string className() const
		{return "mixtank";}

protected:
	Model &initFunction();
	
	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const   Port &in,
				&start_in,
			    &mixtankControl_in;
			Port &out,
				&mixtankTemp_out,
				&mixtankEmpty_out;
    int pid ;
	Time mixtankHeatingtime,
		   mixtankWarmkeepingtime,
		   mixtankMixingtime,
		   loadingTime;
	int mixtankEmpty;
};	// class storebank


#endif   //__mixtank_H 
