// Using SDL2's SDL_GetClosestDisplayMode()
#include <SDL2/SDL.h>   
#include <cstdio>   

int main(int argc, char* argv[]){

  SDL_Init(SDL_INIT_VIDEO); 
  
  // Declare structures to be filled in.
  SDL_DisplayMode target, closest;
  
  // Set the target properties.
  target.w = 600;     // weird request, but ok
  target.h = 500;
  target.format = 0;  // don't care 
  target.refresh_rate = 0; // don't care
  target.driverdata   = 0; // initialize to 0
  
  printf("Requesting: \t%dx%dpx @ %dhz \n", target.w, target.h, target.refresh_rate);
  
  // Pass the display mode structures by reference to SDL_GetClosestDisplay
  // and check that the result is not a null pointer.
  if(SDL_GetClosestDisplayMode(0, &target, &closest)==NULL){

    // If the returned pointer is null ...
    printf("\nNo match was found!\n\n");
    SDL_Quit();
    return 1;
   
  } 
  // Otherwise, a display mode close to the target is available.
  // Access the SDL_DisplayMode structure to see what was received.
  printf("  Received: \t%dx%dpx @ %dhz \n", closest.w, closest.h, closest.refresh_rate);

  // Now you can set up your SDL_Window* with SDL_CreateWindow()
  // and change the display mode with SDL_SetWindowDisplayMode().
  SDL_Window* window = SDL_CreateWindow(
    "SDL2 Window",closest.w,closest.h,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL
  );
  if(SDL_SetWindowDisplayMode(window, &closest)){
    // ... handle error, clean up and exit
  }
  
  // Wait for a keypress, then exit the program
  for(SDL_Event e; e.type!=SDL_KEYDOWN; SDL_PollEvent(&e)); 
  
  SDL_DestroyWindow(window);
  SDL_Quit();     
  return 0;   
 
}
