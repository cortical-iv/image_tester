#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //Graphics facilities are in Graph_lib defined in Graph.h

  //Create simple_window
  Point top_left{600, 200};
  int window_width {800};
  int window_height {700};
  Simple_window win {top_left, window_width, window_height, "Canvas 1"};

  //Add image
  Image image1{Point{100,50}, "simple_image.jpg"};
  win.attach(image1);

  //General stuff to finish
  win.set_label("My first image");
  win.wait_for_button();  //give control to the display engine
}
