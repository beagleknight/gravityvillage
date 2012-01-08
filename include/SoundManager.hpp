#ifndef CLASS_SOUND_MANAGER_H
#define CLASS_SOUND_MANAGER_H

#include <AL/alut.h>

class SoundManager
{
  public:
    SoundManager();
    ~SoundManager();
    void init(int argc, char** argv);
    void playHelloWorld();
    void playMusic();
    void playFX();
};

#endif
