/*******************************************************************
*
*  DESCRIPTION: Atomic Model mouldtank (use a distributin)
*
*  AUTHOR: Peng Xie
*******************************************************************/

/** include files **/

#include "mouldtank.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
/*******************************************************************
* Function Name: mouldtank
* Description: constructor
********************************************************************/
mouldtank::mouldtank( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
,start_in(addInputPort("start_in"))
, out( addOutputPort( "out" ) )
,mouldtankTemp_out(addOutputPort("mouldtankTemp_out"))
{  
}
/*******************************************************************
* Function Name: initFunction
* Description: 
********************************************************************/
Model &mouldtank::initFunction()
{	
	mouldtankHeatingtime="00:20:00:000";
	mouldtankMouldingtime="00:10:00:000";
//	mouldtankWarmkeepingtime="00:00:40:00";
	return *this;
}

/*******************************************************************
* Function Name: externalFunction
* Description: the mouldtank receives one job
********************************************************************/
Model &mouldtank::externalFunction( const ExternalMessage &msg )
{  
	 pid=static_cast<int>(msg.value());
	if(msg.port()==start_in)
	{
	   holdIn(heating, mouldtankHeatingtime);
	}
	if(msg.port()==in)
		{   holdIn(moulding,mouldtankMouldingtime);
		}


	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &mouldtank::internalFunction( const InternalMessage & )
{
	//if(state()==moulding ) 
	 passivate();
//	else
//	 holdIn(warmkeeping, mouldtankWarmkeepingtime);
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &mouldtank::outputFunction( const InternalMessage &msg )
{
   if (state()==heating)
   sendOutput(msg.time(), mouldtankTemp_out,pid); 
   if (state()==moulding)
   sendOutput( msg.time(), out, pid);
	return *this;
}

mouldtank::~mouldtank()
{
}