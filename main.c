#include <GLES3/gl3.h>
#include <SDL2/SDL.h>

int main() {
    SDL_GLContext context;
    SDL_Window *window;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    window = SDL_CreateWindow("OpenGL", 0, 0, 0, 0, SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(window);

    const char *info = glGetString(GL_VERSION);
    if (info == 0) {
        SDL_Log("OpenGL ES error: %d", glGetError());
        return 2;
    }
    SDL_Log("%s\n", info);

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
