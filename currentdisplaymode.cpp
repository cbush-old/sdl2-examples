// Using SDL_GetCurrentDisplayMode()
#include <SDL2/SDL.h>   
#include <iostream>   

using namespace std;

int main(int argc, char* argv[]){

  SDL_Init(SDL_INIT_VIDEO); 
  
  // Declare display mode structure to be filled in.
  SDL_DisplayMode current;

  // Get current display mode of all displays.
  for(int i=0; i < SDL_GetNumVideoDisplays(); ++i){
  
    int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);
    
    if(should_be_zero != 0)
      // In case of error...
      cout << "Could not get display mode for video display #" << i << ": " << SDL_GetError();
    
    else 
      // On success, print the current display mode.
      cout << "Display #" << i 
        << ": current display mode is " << current.w << 'x' << current.h 
        << "px @ " << current.refresh_rate << "hz. \n";

  }
 
  // Clean up and exit the program.
  SDL_Quit();     
  return 0;   
 
}

