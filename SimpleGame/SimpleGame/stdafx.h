#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#pragma comment(lib, "winmm.lib")

enum ObjectType {
	OBJECT_BUILDING,
	OBJECT_CHARACTER,
	OBJECT_BULLET,
	OBJECT_ARROW
};