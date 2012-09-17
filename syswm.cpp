#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

using std::cout;

int main(int argc, char* argv[]){

  SDL_Init(0);
  SDL_Window* window = SDL_CreateWindow("",0,0,0,0,SDL_WINDOW_HIDDEN);
  
  SDL_SysWMinfo info;
  
  SDL_VERSION(&info.version); // initialize info structure with SDL version info
  
  if(SDL_GetWindowWMInfo(window,&info)){ // the call returns true on success
    // success
    cout << "This program is running SDL version " 
      << (int)info.version.major << "."
      << (int)info.version.minor << "."
      << (int)info.version.patch << " on ";
    switch(info.subsystem){
      case SDL_SYSWM_UNKNOWN:   cout << "an unknown system!";     break;
      case SDL_SYSWM_WINDOWS:   cout << "Microsoft Windows(TM)";  break;
      case SDL_SYSWM_X11:       cout << "X Window System";        break;
      case SDL_SYSWM_DIRECTFB:  cout << "DirectFB";               break;
      case SDL_SYSWM_COCOA:     cout << "Apple OS X";             break;
      case SDL_SYSWM_UIKIT:     cout << "UIKit";                  break;
    }
    
  } else {
    // call failed
    cout << "Couldn't get window information: " << SDL_GetError();
  }
  
  SDL_DestroyWindow(window);
  SDL_Quit();
  
}
