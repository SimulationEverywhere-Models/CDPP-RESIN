/*******************************************************************
*
*  DESCRIPTION: Atomic Model mixtank 
*
*  AUTHOR: Peng Xie
*******************************************************************/

/** include files **/
#include "mixtank.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: mixtank
* Description: constructor
********************************************************************/
mixtank::mixtank( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, start_in(addInputPort("start_in"))
, mixtankControl_in(addInputPort("mixtankControl_in"))
, out( addOutputPort( "out" ) )
, mixtankTemp_out(addOutputPort("mixtankTemp_out"))
, mixtankEmpty_out(addOutputPort("mixtankEmpty_out"))
{
  
}
Model &mixtank::initFunction()
{ 
	mixtankHeatingtime="00:20:00:000";
//	mixtankWarmkeepingtime="00:00:20:00";
	mixtankMixingtime="00:10:00:000";
	 loadingTime="00:00:10:000";
	 mixtankEmpty=1;
return *this;
}

/*******************************************************************
* Function Name: externalFunction
* Description: the mixtank receives one job
********************************************************************/
Model &mixtank::externalFunction( const ExternalMessage &msg )
{
	pid=static_cast<int>(msg.value());

	if(msg.port()==mixtankControl_in)
		{  
		if(mixtankEmpty==0)
			holdIn(loading,loadingTime) ; 
		}

	if(msg.port()==start_in)
		{
			holdIn(heating, mixtankHeatingtime);
		}
	if(msg.port()==in)
		{   mixtankEmpty=0;
			holdIn(mixing,mixtankMixingtime);
		 }

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &mixtank::internalFunction( const InternalMessage & )
{
	//if(!p.empty() ) //just cancelled mixing state judgement.
	 passivate();
//	else
//	 holdIn(warmkeeping, mixtankWarmkeepingtime);
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &mixtank::outputFunction( const InternalMessage &msg )
{
	
	if (state()==loading)
		{sendOutput(msg.time(),out,pid);mixtankEmpty=1;}	

	if(state()==heating)
		{sendOutput( msg.time(), mixtankTemp_out, pid);
		}
	if(state()==mixing)
		 {sendOutput( msg.time(),mixtankEmpty_out, pid);
		}
	
	return *this;
}

mixtank::~mixtank()
{
}