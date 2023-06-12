/*******************************************************************
*
*  DESCRIPTION: Atomic Model count
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __count_H
#define __count_H

#include "atomic.h"  
   // class Atomic

class count : public Atomic
{
public:
	count( const string &name = "count" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &done;
	Port &out;
	Time prepTime;
	int pid;
//	packs p;
	int storetankEmpty;
	int CT;
};	// class count

// ** inline ** // 
inline string count::className() const
{
	return "count" ;
}

#endif   //__count_H
