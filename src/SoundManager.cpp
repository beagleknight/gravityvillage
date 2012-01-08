#include "SoundManager.hpp"

SoundManager::SoundManager()
{
  buffers = vector<ALuint> (100);
  sources = vector<ALuint> (100);
}

SoundManager::~SoundManager()
{
  alutExit ();
}

void SoundManager::init(int argc, char** argv)
{
  alutInit (&argc, argv);
}

void SoundManager::addSound(int id, const char* filename)
{
  ALuint buffer, source;
  buffer = alutCreateBufferFromFile(filename);
  alGenSources (1, &source);

  buffers[id] = buffer;
  sources[id] = source;
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

void SoundManager::playMusic(int id)
{
  alSourcei (sources[id], AL_BUFFER, buffers[id]);
  alSourcePlay (sources[id]);
}

void SoundManager::playFX(int id)
{
  alSourcei (sources[id], AL_BUFFER, buffers[id]);
  alSourcePlay (sources[id]);
}
