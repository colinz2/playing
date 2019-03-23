//
// Created by colin on 2018/11/13.
//

#ifndef PLAY_CLOCK_TIME_H
#define PLAY_CLOCK_TIME_H

#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

class ClockTime {
public:
    ClockTime(bool print = false)
            : idx_(0),
              is_print_destroy_(print) {
        memset(val_, 0, sizeof(val_));
        memset(rdtsc_, 0, sizeof(rdtsc_));
        //this->GetClockTime(&val_[1]);
        //this->GetClockTime(&val_[0]);
    }

    ~ClockTime() {
        if (is_print_destroy_) {
            PrintDuration();
        }
    }

    void GatherNow() {
        this->GetClockTime(&val_[idx_ & 1]);
        idx_++;
    }

    bool CheckUpdateLater() {
        if (val_[1].tv_sec < val_[0].tv_sec) {
            return true;
        } else if (val_[1].tv_sec == val_[0].tv_sec) {
            if (val_[1].tv_nsec < val_[0].tv_nsec) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    double PrintDuration() {
        if (CheckUpdateLater()) {
            this->GetClockTime(&val_[1]);
        }
        this->MinusTimespec(val_[1], val_[0]);
        struct timespec &tp = val_[1];
        uint64_t ms = tp.tv_nsec / 1000 / 1000;
        uint64_t vs = (tp.tv_nsec % (1000 * 1000)) / 1000;
        uint64_t ns = tp.tv_nsec % 1000;
        double vsm = (double) tp.tv_nsec / 1000 + tp.tv_sec * 1000 * 1000;
        double cycle = (double) (rdtsc_[1] - rdtsc_[0]) / 1000 / 1000;
        printf("[%ld秒, %" PRIu64"毫秒, %" PRIu64"微妙, %" PRIu64"ns], "
                                                          "[%6.3fus], "
                                                          "[%6.6fM cycles]\n",
               tp.tv_sec, ms, vs, ns,
               vsm,
               cycle);
        return vsm;
    }

private:
    void MinusTimespec(struct timespec &tp1, struct timespec &tp2) {
        assert(tp1.tv_sec >= tp2.tv_sec);
        if (tp1.tv_sec > tp2.tv_sec) {
            if (tp1.tv_nsec < tp2.tv_nsec) {
                tp1.tv_sec -= 1;
                tp1.tv_nsec += (1000 * 1000 * 1000 - tp2.tv_nsec);
            } else {
                tp1.tv_nsec -= tp2.tv_nsec;
            }
            tp1.tv_sec -= tp2.tv_sec;
        } else {
            tp1.tv_sec = 0;
            tp1.tv_nsec -= tp2.tv_nsec;
        }
    }

    int GetClockTime(struct timespec *tp) {
        rdtsc_[idx_ & 1] = Rdtsc();
        return clock_gettime(CLOCK_MONOTONIC, tp);
    }

    uint64_t Rdtsc() {
        uint32_t lo, hi;
        __asm__ __volatile__ (
        "rdtsc":"=a"(lo), "=d"(hi)
        );
        return (uint64_t) hi << 32 | lo;
    }

private:
    struct timespec val_[2];
    uint64_t rdtsc_[2];
    size_t idx_;
    bool is_print_destroy_;
};

#endif //PLAY_CLOCK_TIME_H
