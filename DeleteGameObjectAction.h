#pragma once

#include "Action.h"

class DeleteGameObjectAction :	public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition PostionToDelete; // The postion of the cell whose game object will be deleted
	// Note: This parameter should be read in ReadActionParameters()

public:
	// A Constructor
	DeleteGameObjectAction(ApplicationManager* pApp); 
	// Reads DeleteGameObjectAction action parameter (PostitionToDelete)
	virtual void ReadActionParameters(); 
	// Deletes any gameobject if there's one in the chosen cell 
	virtual void Execute(); 

	// Virtual Destructor
	virtual ~DeleteGameObjectAction(); 
};