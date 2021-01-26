========================================================================
    CONSOLE APPLICATION : SemiGlobalMatching Project Overview
========================================================================

AppWizard has created this SemiGlobalMatching application for you.

This file contains a summary of what you will find in each of the files that
make up your SemiGlobalMatching application.


SemiGlobalMatching.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

SemiGlobalMatching.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

SemiGlobalMatching.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named SemiGlobalMatching.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
Build and Run the program on linux:
mkdir build && cd build
cmake ..
make
./SemiGlobalMatching ../../Data/cone/im2.png ../../Data/cone/im6.png 0 64
#description# argc[1]:left image, argc[2]:right image, argc[3]:min disparity[optional,default:0], argc[4]:max disparity[optional,64]
