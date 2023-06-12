/*******************************************************************
*
*  DESCRIPTION: Atomic Model count
*
*  AUTHOR: 
*******************************************************************/

/** include files **/
#include "count.h"      // class count
#include "message.h"    // class ExternalMessage, InternalMessage
//#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: count
* Description: 
********************************************************************/
count::count( const string &name )
: Atomic( name )
,in( addInputPort( "in" ) )
,done( addInputPort( "done" ) )
,out( addOutputPort( "out" ) )

{
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &count::initFunction()
{	storetankEmpty=1;
	prepTime="00:00:10:00";
	CT=0;
		//p.erase( );
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &count::externalFunction( const ExternalMessage &msg )
{
	pid=static_cast<int>(msg.value());
	if( msg.port() == in )
	{
		CT=CT+1;//elements.push(msg.value());//p.push( ) ;
		if( CT>=1 && storetankEmpty==1)
			holdIn( active, prepTime );
	}

	if( msg.port() == done )
	{ if(CT!=0)
	{sendOutput(msg.time(),out,pid);
	storetankEmpty=0;
	CT=CT-1;}
	 //if( CT)//!p.empty() )
	//		holdIn( active, prepTime );
	}

	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &count::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &count::outputFunction( const InternalMessage &msg )
{	if(state()==active)
	{sendOutput( msg.time(), out, pid ) ;
	 storetankEmpty=0;
	 CT=CT-1;
	}
	return *this ;
}
