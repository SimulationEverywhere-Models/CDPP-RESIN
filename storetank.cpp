/*******************************************************************
*
*  DESCRIPTION: Atomic Model STORETANK 
*  AUTHOR: Peng Xie
*******************************************************************/

/** include files **/

#include "storetank.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: storetank
* Description: constructor
********************************************************************/
storetank::storetank( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, storetankControl_in(addInputPort("storetankControl_in"))
, out( addOutputPort( "out" ) )
//, storetankEmpty_out(addOutputPort("storetankEmpty_out"))
{
  
}
Model &storetank::initFunction()
{ storetankEmpty=1;
	storeTime="00:01:00:000";
	loadingTime="00:00:05:000";
return *this;
}

/*******************************************************************
* Function Name: externalFunction
* Description: the storetank receives one job
********************************************************************/
Model &storetank::externalFunction( const ExternalMessage &msg )
{
	if (msg.port()==in)
	{	storetankEmpty=0;
		//holdIn(storing, storeTime);
	}
	if(msg.port()==storetankControl_in)
	{ if(storetankEmpty==0)
		holdIn(loading, loadingTime) ;
	}
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &storetank::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &storetank::outputFunction( const InternalMessage &msg )
{
	if (state()==loading)
	{storetankEmpty=1;	sendOutput( msg.time(), out, pid);}
	
	return *this;
}

storetank::~storetank()
{
}