#ifndef CLASS_SOUND_MANAGER_H
#define CLASS_SOUND_MANAGER_H

#include <vector>
#include <AL/alut.h>
using namespace std;

#define SOUND_MARIO_OST 0
#define SOUND_JUMP 1
#define SOUND_PICK_ITEM 2
#define SOUND_PICK_QUEST 3
#define SOUND_HURT 4
#define SOUND_MARIO_WIN 5
#define SOUND_HIT_ENEMY 6
#define SOUND_MORE_ITEMS 7

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
