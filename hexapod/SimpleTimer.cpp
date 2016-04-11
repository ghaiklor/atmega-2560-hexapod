#include "SimpleTimer.h"

static inline unsigned long elapsed() {
  return millis();
}

SimpleTimer::SimpleTimer() {
  unsigned long current_millis = elapsed();

  for (int i = 0; i < MAX_TIMERS; i++) {
    enabled[i] = false;
    callbacks[i] = 0;
    prev_millis[i] = current_millis;
    numRuns[i] = 0;
  }

  numTimers = 0;
}

void SimpleTimer::run() {
  int i;
  unsigned long current_millis;

  current_millis = elapsed();

  for (i = 0; i < MAX_TIMERS; i++) {
    toBeCalled[i] = DEFCALL_DONTRUN;

    if (callbacks[i]) {
      if (current_millis - prev_millis[i] >= delays[i]) {
        prev_millis[i] += delays[i];

        if (enabled[i]) {
          if (maxNumRuns[i] == RUN_FOREVER) {
            toBeCalled[i] = DEFCALL_RUNONLY;
          } else if (numRuns[i] < maxNumRuns[i]) {
            toBeCalled[i] = DEFCALL_RUNONLY;
            numRuns[i]++;

            if (numRuns[i] >= maxNumRuns[i]) {
              toBeCalled[i] = DEFCALL_RUNANDDEL;
            }
          }
        }
      }
    }
  }

  for (i = 0; i < MAX_TIMERS; i++) {
    switch (toBeCalled[i]) {
      case DEFCALL_DONTRUN:
        break;

      case DEFCALL_RUNONLY:
        (*callbacks[i])();
        break;

      case DEFCALL_RUNANDDEL:
        (*callbacks[i])();
        deleteTimer(i);
        break;
    }
  }
}


int SimpleTimer::findFirstFreeSlot() {
  int i;

  if (numTimers >= MAX_TIMERS) {
    return -1;
  }

  for (i = 0; i < MAX_TIMERS; i++) {
    if (callbacks[i] == 0) {
      return i;
    }
  }

  return -1;
}

int SimpleTimer::setTimer(long d, timer_callback f, int n) {
  int freeTimer;

  freeTimer = findFirstFreeSlot();
  if (freeTimer < 0) {
    return -1;
  }

  if (f == NULL) {
    return -1;
  }

  delays[freeTimer] = d;
  callbacks[freeTimer] = f;
  maxNumRuns[freeTimer] = n;
  enabled[freeTimer] = true;
  prev_millis[freeTimer] = elapsed();

  numTimers++;

  return freeTimer;
}

int SimpleTimer::setInterval(long d, timer_callback f) {
  return setTimer(d, f, RUN_FOREVER);
}

int SimpleTimer::setTimeout(long d, timer_callback f) {
  return setTimer(d, f, RUN_ONCE);
}

void SimpleTimer::deleteTimer(int timerId) {
  if (timerId >= MAX_TIMERS) {
    return;
  }

  if (numTimers == 0) {
    return;
  }

  if (callbacks[timerId] != NULL) {
    callbacks[timerId] = 0;
    enabled[timerId] = false;
    toBeCalled[timerId] = DEFCALL_DONTRUN;
    delays[timerId] = 0;
    numRuns[timerId] = 0;

    numTimers--;
  }
}

void SimpleTimer::restartTimer(int numTimer) {
  if (numTimer >= MAX_TIMERS) {
    return;
  }

  prev_millis[numTimer] = elapsed();
}


boolean SimpleTimer::isEnabled(int numTimer) {
  if (numTimer >= MAX_TIMERS) {
    return false;
  }

  return enabled[numTimer];
}

void SimpleTimer::enable(int numTimer) {
  if (numTimer >= MAX_TIMERS) {
    return;
  }

  enabled[numTimer] = true;
}

void SimpleTimer::disable(int numTimer) {
  if (numTimer >= MAX_TIMERS) {
    return;
  }

  enabled[numTimer] = false;
}

void SimpleTimer::toggle(int numTimer) {
  if (numTimer >= MAX_TIMERS) {
    return;
  }

  enabled[numTimer] = !enabled[numTimer];
}

int SimpleTimer::getNumTimers() {
  return numTimers;
}
