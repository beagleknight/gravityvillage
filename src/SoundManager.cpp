#include "SoundManager.hpp"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
  alutExit ();
}

void SoundManager::init(int argc, char** argv)
{
  alutInit (&argc, argv);
}

void SoundManager::playHelloWorld()
{
  ALuint helloBuffer, helloSource;
  helloBuffer = alutCreateBufferHelloWorld();
  alGenSources (1, &helloSource);
  alSourcei (helloSource, AL_BUFFER, helloBuffer);
  alSourcePlay (helloSource);
  alutSleep (1);
}

void SoundManager::playMusic()
{
  ALuint buffer, source;
  buffer = alutCreateBufferFromFile("res/sounds/mario.wav");
  alGenSources (1, &source);
  alSourcei (source, AL_BUFFER, buffer);
  alSourcePlay (source);
  alutSleep (1);
}

void SoundManager::playFX()
{
  ALuint buffer, source;
  buffer = alutCreateBufferFromFile("res/sounds/jump.wav");
  alGenSources (1, &source);
  alSourcei (source, AL_BUFFER, buffer);
  alSourcePlay (source);
}
