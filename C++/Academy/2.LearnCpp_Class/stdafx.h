#pragma once

#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

using namespace std;

#define SAFE_DELETE( p )            if( p ) { delete p; p = 0; }
#define SAFE_DELETE_ARRAY( p )      if( p ) { delete[] p; p = 0; }