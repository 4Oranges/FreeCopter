//
//  raspberry_pi.h
//  Free-Copter
//
//  Created by Master on 7/5/15.
//
//

#ifndef __RASPBERRY_PI_H__
#define __RASPBERRY_PI_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

#include "gpio_mem_dump.h"


// raspberry_pi_clock_type_interrupt, raspberry_pi_clock_type_chrono
// raspberry_pi_clock_type_interrupt for use system clock interrupts or raspberry_pi_clock_type_chrono for use cpp header <chrono>
#define raspberry_pi_clock_type_chrono

// raspberry_pi_gpio_poll_type_poll or raspberry_pi_gpio_poll_type_interrupt
// raspberry_pi_gpio_poll_type_poll for polling gpio pins every clock tick, while raspberry_pi_gpio_poll_type_interrupt uses gpio interrupts.
#define raspberry_pi_gpio_poll_type_poll

struct bcm2708_peripheral {
    unsigned long addr_p;
    int mem_fd;
    void *map;
    volatile unsigned int *addr;
};

// temp use
extern struct bcm2708_peripheral gpio;

void raspberry_pi_start();

// call this function before exit. (in the SIGTERM or SIGINT handler)
void raspberry_pi_term();
#endif /* defined(__RASPBERRY_PI_H__) */
