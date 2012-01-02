#ifndef CLASS_TEXTURE_H
#define CLASS_TEXTURE_H

#include <GL/glut.h>

class Texture
{
  public:
    Texture();
    ~Texture();
    bool load(const char *filename,int type = GL_RGBA,int wraps = GL_REPEAT,int wrapt = GL_REPEAT, 
        int magf = GL_NEAREST,int minf = GL_NEAREST,bool mipmap = false);
    GLuint getId();
    int getWidth();
    int getHeight();
  private:
    GLuint id;
    int width;
    int height;
};

#endif
