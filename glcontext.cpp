#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

using std::cout;

int main(int argc, char* argv[]){

  SDL_Init(SDL_INIT_VIDEO); // Init SDL2
  
  // Create a window. Window mode MUST include SDL_WINDOW_OPENGL for use with OpenGL.
  SDL_Window *window = SDL_CreateWindow(
    "SDL2/OpenGL Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE
  );
  
  // Create an OpenGL context associated with the window.
  SDL_GLContext glcontext = SDL_GL_CreateContext(window);

  // Now, regular OpenGL functions ...
  glMatrixMode(GL_PROJECTION|GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(-320,320,240,-240,0,1);
 
  // ... can be used alongside SDL2.
  SDL_Event e; 
  float x = 0.0, y = 30.0;
  
  while(e.type!=SDL_KEYDOWN&&e.type!=SDL_QUIT){  // Enter main loop.
    
    SDL_PollEvent(&e);      // Check for events.
    
    glClearColor(0,0,0,1);          // Draw with OpenGL.
    glClear(GL_COLOR_BUFFER_BIT);   
    glRotatef(10.0,0.0,0.0,1.0);     
    // Note that the glBegin() ... glEnd() OpenGL style used below is actually 
    // obsolete, but it will do for example purposes. For more information, see
    // SDL_GL_GetProcAddress() or find an OpenGL extension loading library.
    glBegin(GL_TRIANGLES);          
      glColor3f(1.0,0.0,0.0); glVertex2f(x, y+90.0);
      glColor3f(0.0,1.0,0.0); glVertex2f(x+90.0, y-90.0);
      glColor3f(0.0,0.0,1.0); glVertex2f(x-90.0, y-90.0);
    glEnd();
    
    SDL_GL_SwapWindow(window);  // Swap the window/buffer to display the result.
    SDL_Delay(10);              // Pause briefly before moving on to the next cycle.
    
  } 

  // Once finished with OpenGL functions, the SDL_GLContext can be deleted.
  SDL_GL_DeleteContext(glcontext);  
  
  // Done! Close the window, clean-up and exit the program. 
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
  
}
