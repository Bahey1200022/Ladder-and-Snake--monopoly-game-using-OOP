#pragma once
#include "action.h"
class OpenGridAction :public Action
{
	string FileName;
public:
	OpenGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~OpenGridAction(void);
};

