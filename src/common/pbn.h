#ifndef __PBN_H__
#define __PBN_H__

#include <cmath>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sdlIncludes.h"

//  Define M_PI in the case it's not defined in the math header file
#ifndef M_PI
#  define M_PI  3.14159265358979323846
#endif

#define Print(x)  do { std::cerr << #x " = " << (x) << std::endl; } while(0)

#endif // PBN_H
