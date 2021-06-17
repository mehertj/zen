#pragma once

#include <iostream>
#include <vector>

#include "MyConfig.h"

class MyFlover : public Zen::Vap2d::Sprite {
public:
	MyFlover()
	{
		auto t = Textures::Get()->getTexture("res/tile001.png");
		this->setTexture(t);
	}
};
