#pragma once
#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void addState(StateRef newState, bool isReplacing = true);
	void removeState();

	void processStateChanges();

	StateRef& getActiveState();

private:
	std::stack<StateRef> _states;
	StateRef _newState;

	bool _isLoading;
	bool _isRemoving; //  можно обернуть в enum
	bool _isAdding;
	bool _isReplacing;		
};

