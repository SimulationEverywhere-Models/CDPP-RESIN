/*******************************************************************
*
*  DESCRIPTION: Atomic Model computer
*  AUTHOR: Peng Xie
*******************************************************************/

/** include files **/
#include "computer.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: computer
* Description: constructor
********************************************************************/
computer::computer( const string &name )
: Atomic( name )
,in( addInputPort( "in" ) )
,mixtankTemp_in(addInputPort("mixtankTemp_in"))
,mixtankEmpty_in(addInputPort("mixtankEmpty_in"))
,mouldtankTemp_in(addInputPort("mouldtankTemp_in"))
,mouldtankEmpty_in(addInputPort("mouldtankEMpty_in"))
,storetankEmpty_in(addInputPort("storetankEmpty_in"))
,out(addInputPort("out"))
,mixtankControl_out(addOutputPort("mixtankControl_out"))
,storetankControl_out( addOutputPort( "storetankControl_out" ) )

{}
/*******************************************************************
* Function Name: initFunction
* Description: initialization
********************************************************************/
Model &computer::initFunction(){
	mixtankEmpty=1;
	mouldtankEmpty=1;
	mixtankKeepwarm=0;
	mouldtankKeepwarm=0;
	sendTime="00:00:30:000";
	sendTime1="00:00:10:000";
	return *this;
}

/*******************************************************************
* Function Name: externalFunction
* Description: the computer receives one job
********************************************************************/
Model &computer::externalFunction( const ExternalMessage &msg )
{  
	pid = static_cast< int >( msg.value() ) ;
	if(msg.port()==in)
	{  holdIn(starting,sendTime);
		
	}
	if(msg.port()==mixtankTemp_in)
		{	mixtankKeepwarm=1;
		    holdIn(mtk_controlling,sendTime1);
		}
	if(msg.port()==storetankEmpty_in)
		{   mixtankEmpty=0;
		//	holdIn(mtk_controlling,sendTime);
		}
	if(msg.port()==mixtankEmpty_in)
		{	
			mixtankEmpty=1;
			mouldtankEmpty=0;
		//	holdIn(moutk_controlling,sendTime);
		}
	if(msg.port()==mouldtankTemp_in)
		{  
			mouldtankKeepwarm=1;
			holdIn(moutk_controlling,sendTime);
		}

	if(msg.port()==mouldtankEmpty_in)
		{   
			mouldtankEmpty=1;
			if(mixtankEmpty==0)
			holdIn(moutk_controlling,sendTime);
		}
	  

//	holdIn( active, time);//Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &computer::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &computer::outputFunction( const InternalMessage &msg )
{
	if (state()==starting) 
		sendOutput(msg.time(),out,pid);
	if (state()==mtk_controlling)
	{
		if (mixtankEmpty && mixtankKeepwarm)
			this->sendOutput(msg.time(), storetankControl_out, pid);
	}

	if(state()==moutk_controlling)
	{
		if(mouldtankEmpty && mouldtankKeepwarm)
			this->sendOutput(msg.time(),mixtankControl_out,pid);
	}
		
		
	return *this;
}

computer::~computer()
{}