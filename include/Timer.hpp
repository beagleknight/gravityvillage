#ifndef CLASS_TIMER_H
#define CLASS_TIMER_H

class Timer
{
  public:
    Timer();
    ~Timer();
    void init();
    float tick();
    float getFPS();
  private:
    int current_time;
    int frame_time;
    float fps;
    int frames;
};

#endif
