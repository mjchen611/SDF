// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

#define _USE_MATH_DEFINES

// windows files
#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <fstream>
/*#include <iostream>
#include <sstream>
#include <iomanip>*/

// necessary for drawing
#include "GL\freeglut.h"
#include <cmath>

// manipulacia s datami
#include <vector>
//#include <string.h>
//#include <map>


// assimp include files. These three are usually needed.
#include "assimp/Importer.hpp"	//OO version Header!
#include "assimp/PostProcess.h"
#include "assimp/Scene.h"
#include "assimp/DefaultLogger.hpp"
#include "assimp/LogStream.hpp"