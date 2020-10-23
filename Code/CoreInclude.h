#pragma once
#ifndef CORE_H
#define CORE_H

#include <cmath>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <typeinfo>


#include "InputMgr.h"
#include "Math.h"
#include "Time.h"
#include "GFXMgr.h"
#include "UpdateMgr.h"
#include "DrawMgr.h"
#include "LTexture.h"
#include "Animation.h"
#include "Game.h"
#include "ComponentSystem/IComponent.h"
#include "ComponentSystem/Transform.h"
#include "ComponentSystem/CMovement.h"
#include "Physics/PhysicsMgr.h"
#include "Physics/Rigidbody.h"
#include "Physics/Rect.h"
#include "Physics/Shape.h"
#include "GameObject.h"

#endif // !