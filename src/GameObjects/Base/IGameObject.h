#ifndef _IGameObject_
#define _IGameObject_

#include "LoaderParams.h"

class IGameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	IGameObject(const LoaderParams* pParams) {}
	virtual ~IGameObject() {}
};

#endif