// DIR_TYPE "metalib" indicates we are building a shared library that
// consists mostly of references to other shared libraries.  Under
// Windows, this directly produces a DLL (as opposed to the regular
// src libraries, which don't produce anything but a pile of OBJ files
// under Windows).

#define DIR_TYPE metalib
#define BUILDING_DLL BUILDING_PANDAFX

#define COMPONENT_LIBS \
    distort effects

#begin metalib_target
  #define TARGET pandafx
  #define SOURCES pandafx.cxx  
#end metalib_target
