### What is this?
Attempt to get image to show using code from Chapter 12 of Principles and practice Chapter 12. Originally, the window is rendering fine, but the image was not opening, so I was getting  "cannot open simple_image.jpg". It turns out I wasn't putting the image in the same directory as the executable because my IDE was building a new folder for the executable and I did not put the image in this directory! So....just be careful of your pathnames and file locations.

Now it is building fine with cmake, but not make or from the command line (see below).

###Building it
You can build it a few of ways: currently the first two ways are yielding an error, but `cmake` is working. The first two ways don't
show the image, but the error:

    JPEG file "image.jpg" is too large or contains errors!

This has come up before from someone teaching a course on C++ and he wrote:
> You'll now see the window contents that you expect,
 except for one error (at least when I ran this): You'll get an error
 message
  JPEG file "image.jpg" is too large or contains errors!
 I don't know what to do about that.  Note that if you double-click the
 file image.jpg in the Finder, it gets nicely displayed by Preview.
 I'm not about to attempt tracing this bug, which may be in the JPEG
 software or in Bjarne's GUI.

That is from here:
http://www.dsm.fordham.edu/pipermail/programming-c++/2015-August/000019.html

Nice to see the professor showing so much grit with the code. :) 

The image opens fine from cmake, or when I open it using FLTK's pixmap_browser example (which you can find in  fltk/build/bin/examples). So it isn't a problem with the image. It is probably a problem with the fact that I built FLTK using cmake, and my system doesn't like to build things from the command line now. But I'm frankly not sure, because cmake just builds a makefile after all!


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
