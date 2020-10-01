#include "Time.h"

static float OldTimeTick;
static float NewTimeTick;


void Time::Init()
{
    OldTimeTick = 0;
    NewTimeTick = 0;
}

float Time::GetTime()
{
    return NewTimeTick/1000.;
}

float Time::GetDeltaTime()
{
    return (NewTimeTick-OldTimeTick)/1000.;
}

void Time::Tick()
{
    OldTimeTick = NewTimeTick;
    NewTimeTick = SDL_GetTicks();

    //std::cout << GetDeltaTime() << std::endl;
}
