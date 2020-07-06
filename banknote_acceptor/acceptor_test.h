/*
 *
 * Before any use, add following lines to /boot/config.txt

#setting input pins with pull up
gpio=2,3,4,17=ip,pu

#setting output pins with value high
gpio=27,22,10,9=op,dh

 * to make Pi configure its GPIOs during startup.
 *
 *
 * Controlling NV10 Banknote Acceptor using Raspberry Pi 2B
 * reference: http://www.coinoperatorshop.com/media/products/manual/NV/NV10%20_Manual%20Englisch.pdf
 *
 * NV10 interface: Parallel (all dipswitches should be DOWN)
 * WARNING: connecting directly to Raspberry Pi can damage the Pi (it operates on 3.3V when NV10 uses 5V signals)
 *
 * NV10 pinout (all data pins expect or send 5V signals):
 *
 * ____________----------_______________
 * | 1 | 3 | 5 | 7 |  9 | 11 | 13 | 15 |
 * | 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 |
 * -------------------------------------
 *
 * 1 (OUTPUT) - if LOW for 100 ms - correct nominal-1 banknote accepted
 * 2 (OUTPUT) - if LOW for 100 ms - correct nominal-2 banknote accepted
 * 3 (OUTPUT) - if LOW for 100 ms - correct nominal-3 banknote accepted
 * 4 (OUTPUT) - if LOW for 100 ms - correct nominal-4 banknote accepted
 * 5 (INPUT) - inhibit 1 - HIGH prevents the machine from accepting nominal-1
 * 6 (INPUT) - inhibit 2 - HIGH precents the machine from accepting nominal-2
 * 7 (INPUT) - inhibit 3 - HIGH prevents the machine from accepting nominal-3
 * 8 (INPUT) - inhibit 4 - HIGH prevents the machine from accepting nominal-4
 * 9 (OUTPUT) - the machine is busy
 * 10 (INPUT) - escrow control - if LOW, freezes accepted banknote and waits for further commands, HIGH accepts banknotes immediately (connect to +5V)
 * 11-14 - unused
 * 15 - +12V DC power supply
 * 16 - ground
 *
 * Connect Raspberry GPIO pins (through 3V3<->5V converter!) to 1-8 pins of NV10
 * according to this mapping (we are using BCM pin coding):
 * NV10 <-> Raspberry
 *   1  <->  GPIO2
 *   2  <->  GPIO3
 *   3  <->  GPIO4
 *   4  <->  GPIO17
 *   5  <->  GPIO27
 *   6  <->  GPIO22
 *   7  <->  GPIO10
 *   8  <->  GPIO9
 * Pin 10 and 16 of NV10 should be grounded.
 * Pi's ground should be connected with NV10's ground.
 */

//gcc -Wall -o acceptor_test acceptor_test.c -lwiringPi
//sudo ./acceptor_test

#ifndef E_KIOSK_ACCEPTOR_TEST_H
#define E_KIOSK_ACCEPTOR_TEST_H

#include <wiringPi.h>
#include <stdio.h>

#define ACCEPTED_1 2
#define ACCEPTED_2 3
#define ACCEPTED_3 4
#define ACCEPTED_4 17
#define INHIBIT_1 27
#define INHIBIT_2 22
#define INHIBIT_3 10
#define INHIBIT_4 9

enum Nominals{
    TEN = 0,
    TWENTY,
    FIFTY,
    HUNDRET
};

// wait for pin pin_number to be in state state
int wait_for(int pin_number, int state, int timeout_allowed);

// makes acceptor wait for users banknote
int pay(int nominal);

#endif //E_KIOSK_ACCEPTOR_TEST_H
