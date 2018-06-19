### What is this?
Attempt to get image to show using code from Chapter 12 of Principles and practice Chapter 12. If you get the error "cannot open simple_image.jpg" it probably means your image is not in the same directory as the executable  (I got this when my IDE was building a new folder for the executable and I did not put the image in this directory). So....just be careful of your pathnames and file locations for images.

Now it is building fine with cmake, but not make or from the command line (see below).

### Building it
You can build it a few of ways: currently the first two ways are yielding an error, but `cmake` is working. The first two ways don't
show the image, but the error:

    JPEG file "image.jpg" is too large or contains errors!

This has come up before from someone teaching a course on C++ and he wrote:
> You'll now see the window contents that you expect,
 except for one error (at least when I ran this): You'll get an error
 message
  *JPEG file "image.jpg" is too large or contains errors!*
 I don't know what to do about that.  Note that if you double-click the
 file image.jpg in the Finder, it gets nicely displayed by Preview.
 I'm not about to attempt tracing this bug, which may be in the JPEG
 software or in Bjarne's GUI.

That is from here:
http://www.dsm.fordham.edu/pipermail/programming-c++/2015-August/000019.html

Nice to see the professor showing so much grit to get his code working :) 

The image opens fine from cmake, or when I open it using FLTK's pixmap_browser example (which you can find in  fltk/build/bin/examples). So it isn't a problem with the image. The fact that it works when I use cmake, which just makes another `Makefile`, suggests there is some weird and tough to track down bug going on here. Maybe it is important that I generated my FLTK build using cmake. Not sure.


### Build from command line
It should work with:

    g++ -w -Wall -std=c++11 Graph.cpp Window.cpp GUI.cpp Simple_window.cpp main.cpp `fltk-config --ldflags --use-images` -o image_tester
    ./image_tester


### Build using make

    make
    ./image_tester


### Build using cmake
Go to the project directory and run the following from the command line:

    mkdir build  
    cmake ..  #cmake makes the Makefile, using CMakeLists.txt
    make      #builds the executable using the Makefile
    ./image_tester

Note if you don't have cmake installed: `sudo apt-get install cmake`.
