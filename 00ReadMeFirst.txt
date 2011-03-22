                                          --------------------------                                         
                                          CGLib Version 1.0 build 24
                                          --------------------------

                                  The first build with common sources for

                                             Windows, Mac OS X and Linux


                                  by J M Brisson Lopes, brisson@ist.utl.pt
                                  with support from Miguel Wahnon Monteiro


Foreword
--------

This is CGLib v1.0 build 24, the first ever official version with common sources for Windows, Mac OS X and Linux.

This package can be compiled and linked with OpenGL applications on the following operating systems:

     Windows:  Visual Studio 2008 or later

     Mac OS X: XCode and make

     Linux: make (only)

On all systems, CGLib is compiled into a static library in Debug mode.



Files "Makefile.macos" and "Makefile.linux" on directory "cglib.dev" are the makefiles for MacOS X and Linux.
On these systems, copy the pertaining makefile into "Makefile" (do not rename to avoid confusion).
The file "Makefile" as distributed is a copy of "Makefile.macos" ready to be used on MacOS X and may be adapted to other operating systems (e.g., Linux flavours, CygWin, etc.)



Package Contents
----------------

This package contains a top level directory, cglib.dev, with the following:

     - Directory cglib which includes two subdirectories
             - include/cg   - contains the CGLib include files (.h)
             - src          - contains the CGLib source files (.cpp)
     - Directory cglib.vsnet with the Visual Studio solution structure
                          (see "Compiling and Running on Windows" below)
     - Directory cglib.mac with the XCode project structure
                          (see "Compiling and Running on the Mac" below)
     - Directory template, containing the source files of a sample OpenGL program to test CGLib compilation
     - Directory glut, containing the GLUT definitions and include files required under Windows
     - File config.ini, the configuration file required by all applications built with CGLib
     - File Makefile to build CGLib and OpenGL applications on the Mac with make
     - File Makefile.macos to build CGLib and OpenGL applications on the Mac with make
     - File Makefile.linux to build CGLib and OpenGL applications on Linux with make
     - File gpl.txt, with the GNU General Public License
     - File 00ReadMeFirst, this file

Related Packages
----------------

There is another package, the tutorial package, distributed separately, which contains the tutorial examples and
the (template) test program.



Building and Running on Windows
-------------------------------

The relevant directory structure for Windows is as follows

cglib.dev -- template                         <-- test application source files
          |
          |- cglib  -- include/cg  (CGLib .h files)
                    |- src         (CGLib .cpp files)
          |
          |- cglib.vsnet  --  cglib.sln       <-- the Visual Studio CGLib solution file
                          |-  Template        <-- test application project directory
          |               |-  cglib           <-- CGLib project directory
          |               |-  Debug           <-- directory for the library file and applications
          |
          |
          |- glut ----------  include         <-- GLUt include directory
                          |-  lib             <-- GLUt .def and .lib files directory

Note: directory "cglib.dev\cglib.vsnet\Debug" already constains file glut32.dll.

Before first starting Visual Studio, you may change the name of the template directory and of the
Template project and its directory.
To do this:

1 - Rename the "template" directory under the "cglib.dev" directory to the name of your choice
    (e.g., "PROJECT_NAME").
2 - Rename the "template" directory under the "cglib.dev/cglib.vsnet" directory to the name of your choice
    (as above).
3 - Move to that directory and rename file Template.vcproj to the name of your choice
    ( e.g., "PROJECT_NAME.vcproj")
4 - Edit "PROJECT_NAME.vcproj" in a text editor (e.g. Notepad) and replace all occurences of "Template"
    by "PROJECT_NAME" and save the file.
    Actually, there are only 2 occurences of "Template": at line 5 (Name="Template")
    and at line 7 (RootNamespace="Template"). Save the file.
5 - Start Visual Studio, open the cglib solution (file cglib.dev\cglib.vsnet\cglib.sln) and add
    (as an existing project) to the solution workspace the project whose named was changed by you.
6 - Add your source files to the project by adding them to directory "cglib.dev\PROJECT_NAME\src" and making sure
    that the project listas them as project source (and include) files in the workspace.

Now you can build the CGLib library and your OpenGL application. Select "Build Solution" from
"Build" VS menu item and try to run your application.

But before this remember that:

a) You need file glut32.dll in the same location where the application executable file is.
   By default, this is file is distributed in directory "cglib.dev\cglib.vsnet\Debug".

b) File "config.ini" must be in the directory where the application runs (not the one where is resides).
   By default, this directory is the "cglib.dev\cglib.vsnet\Template" directory.

c) If you run your application by double-clicking on it on a File Explorer window, you need to have files
   "glut32.dll" and "config.ini" in the same directory.



Building and Running on Mac OS X
--------------------------------

On the Mac, applications can be built either with XCode or the make utility.

The relevant directory structure for Mac OS X is as follows

cglib.dev -- template                         <-- test application source files
          |
          |- cglib  -- include/cg  (CGLib .h files)
                    |- src         (CGLib .cpp files)
          |
          |- cglib.mac    --  cglib.xcodeproj <-- the XCode project file
                          |-  build           <-- the directory structure used by XCode
          |               |-  config.ini      <-- CGLib configuration file
          |
          |- Makefile (copied from Makefile.macos)

Building Applications with XCode
--------------------------------

The XCode project assumes that applications run from the directory where the XCode project file is.

Your application source and include files must be placed in the "cglib.dev/template" directory and assigned
to the "Template" target.

To build CGLib library and your application, set target "Template" as the current target and click on the 
"Build and Run" icon on XCode toolbar.

Building Applications with make
-------------------------------

As with XCode, your application source and include files must be located in the "cglib.dev/template" directory.

As "make" places the application in the root directory ("cglib.dev"), file "config.ini" must also be in the
same directory.

To build, open a Terminal, change to the "cglib.dev" directory and type "make" (after making sure that file "Makefile" is a copy of file "Makefile.macos").



Building and Running on Linux
--------------------------------

On Linux, applications can be built the make utility.

The relevant directory structure for Linux is as follows

cglib.dev -- template                         <-- test application source files
          |
          |- cglib  -- include/cg  (CGLib .h files)
                    |- src         (CGLib .cpp files)
          |
          |- Makefile (copied from Makefile.linux)


Your application source and include files must be located in the "cglib.dev/template" directory.

As "make" places the application in the root directory ("cglib.dev"), file "config.ini" must also be in the same directory.

To build, open a Terminal, change to the "cglib.dev" directory and type "make" (after making sure that file "Makefile" is a copy of file "Makefile.linux").

IMPORTANT NOTE - make sure that all required libraries are installed. E.g., in the Debian environment, libraries "build-essential" and "freeglut3-dev" should have been priorly installed with the command

sudo apt-get install build-essential freeglut3-dev
