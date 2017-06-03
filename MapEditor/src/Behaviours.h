#pragma once
#include "ofMain.h"

class Behaviours
{
private:
public:
	struct Type
	{
		int r, g, b;
	};

	vector<Type> behaviours;
	
	void addBehaviour(int r, int g, int b);
};