#ifndef CLASS_SOUND_MANAGER_H
#define CLASS_SOUND_MANAGER_H

#include <vector>
#include <AL/alut.h>
using namespace std;

#define SOUND_MARIO_OST 0
#define SOUND_JUMP 1

class SoundManager
{
  public:
    SoundManager();
    ~SoundManager();
    void init(int argc, char** argv);
    void addSound(int id, const char* filename);
    void playHelloWorld();
    void playMusic(int id);
    void playFX(int id);
  private:
    vector<ALuint> buffers; 
    vector<ALuint> sources; 
};

#endif
