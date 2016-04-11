#ifndef SIMPLETIMER_H
#define SIMPLETIMER_H

#include <Arduino.h>

typedef void (*timer_callback)(void);

class SimpleTimer {
  public:
    const static int MAX_TIMERS = 10;
    const static int RUN_FOREVER = 0;
    const static int RUN_ONCE = 1;

    SimpleTimer();
    void run();
    int setInterval(long d, timer_callback f);
    int setTimeout(long d, timer_callback f);
    int setTimer(long d, timer_callback f, int n);
    void deleteTimer(int numTimer);
    void restartTimer(int numTimer);
    boolean isEnabled(int numTimer);
    void enable(int numTimer);
    void disable(int numTimer);
    void toggle(int numTimer);
    int getNumTimers();
    int getNumAvailableTimers() {
      return MAX_TIMERS - numTimers;
    };

  private:
    const static int DEFCALL_DONTRUN = 0;       // don't call the callback function
    const static int DEFCALL_RUNONLY = 1;       // call the callback function but don't delete the timer
    const static int DEFCALL_RUNANDDEL = 2;      // call the callback function and delete the timer

    int findFirstFreeSlot();
    unsigned long prev_millis[MAX_TIMERS];
    timer_callback callbacks[MAX_TIMERS];
    long delays[MAX_TIMERS];
    int maxNumRuns[MAX_TIMERS];
    int numRuns[MAX_TIMERS];
    boolean enabled[MAX_TIMERS];
    int toBeCalled[MAX_TIMERS];
    int numTimers;
};

#endif
