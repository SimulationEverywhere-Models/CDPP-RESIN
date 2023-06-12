/*******************************************************************
*
*  DESCRIPTION: class computer
*
*  AUTHOR: Peng Xie
*
*  EMAIL: xie_peng@hotmail.com
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __computer_H
#define __computer_H

/** include files **/
#include "atomic.h"  // class Atomic

/** declarations **/
class computer: public Atomic
{
public:
	computer( const string &name = "computer" ) ;	 // Default constructor

	~computer();					// Destructor

	virtual string className() const
		{return "computer";}

protected:
	Model &initFunction();
	
	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in,
		       &mixtankTemp_in,
			   &mixtankEmpty_in,
	           &mouldtankTemp_in,
			   &mouldtankEmpty_in,
			   &storetankEmpty_in;
	      Port &out,
			  &mixtankControl_out,
			  &storetankControl_out;
	int pid;
	int	mixtankEmpty,mouldtankEmpty,
    	mixtankKeepwarm,mouldtankKeepwarm;
	Time sendTime;
	Time sendTime1;
	Value START,LOAD,CAST;
};	// class computer


#endif   //__computer_H 
