
#include "modeladm.h" 
#include "mainsimu.h"

#include "storetank.h"
#include "mixtank.h"
#include "count.h"
#include "mouldtank.h"
#include "computer.h"



void MainSimulator::registerNewAtomics()
{	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<mixtank>() , "mixtank" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<storetank>() , "storetank" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<count>() , "count" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<computer>() , "computer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<mouldtank>() , "mouldtank" ) ;
}
