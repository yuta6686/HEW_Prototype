#pragma once

#include "StageObject_001.h"
#include "StageObject_002.h"
#include "StageObject_003.h"
//class StageObject_001;
class StageObectFactory
{
public:
	StageObject_001* Create_001(void){
		return new StageObject_001();
	}

	StageObject_002* Create_002(void) {
		return new StageObject_002();
	}

	StageObject_003* Create_003(void) {
		return new StageObject_003();
	}
};

