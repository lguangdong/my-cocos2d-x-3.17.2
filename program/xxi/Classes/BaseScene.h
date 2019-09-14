#ifndef BASESECENE_H
#define BASESCENE_H

#include "cocos2d.h"
class BaseScene: public cocos2d::Scene{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual bool init();
	CREATE_FUNC(BaseScene);
};
#endif
