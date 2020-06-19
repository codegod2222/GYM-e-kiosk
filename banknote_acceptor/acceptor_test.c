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
 * Pin 9 and 15 of NV10 should be grounded.
 * Pi's ground should be connected with NV10's ground.
 */
 
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

int ACCEPTED_PINS[] = {ACCEPTED_1, ACCEPTED_2, ACCEPTED_3, ACCEPTED_4};
int INHIBIT_PINS[] = {INHIBIT_1, INHIBIT_2, INHIBIT_3, INHIBIT_4};
int nominalsValues[] = {10, 20, 50, 100};
enum Nominals{
  TEN = 0,
  TWENTY,
  FIFTY,
  HUNDRET
};

// wait for pin pin_number to be in state state
int wait_for(int pin_number, int state, int timeout_allowed)
{
  printf("Waiting for pin %d...\n", pin_number);
  int checks_needed = 5;
  int delay_between_checks = 10;
  int stable_state_counter = checks_needed; // if pin pin_number happens to be in a state state iterations_needed times 
  int timeout_counter = 1000; // 10s        // in a row with delay between checks delay_between_checks, we treat it as a stable state and return from the function
  while(stable_state_counter && (!timeout_allowed || timeout_counter))
  {
    if(digitalRead(pin_number) == state)
    {
      stable_state_counter--;
    }
    else{
      stable_state_counter = checks_needed;
      timeout_counter--;
    }
    delay(delay_between_checks);
  }
  printf("Done waiting. Result: ");
  printf("%s", stable_state_counter == 0 ? "GOOD" : "TIMEOUT");
  printf("\n");
  if(stable_state_counter == 0) return 1; // stable state has been achieved
  else return 0; // return 0 in case of timeout
}

int pay(int nominal)
{
  printf("Initializing payment of %d PLN\n", nominalsValues[nominal]);
  digitalWrite(INHIBIT_PINS[nominal], LOW); // allow corresponding channel
  int result = wait_for(ACCEPTED_PINS[nominal], LOW, 1); // "if a note is recognised, the relevant channel line is set LOW for 100 +- 3 milliseconds."
  digitalWrite(INHIBIT_PINS[nominal], HIGH);
  return result;
}

int main() {
  wiringPiSetupGpio();
  int result = pay(FIFTY);
  printf(result != 0 ? "\tSuccessfully paid." : "Error occured during payment.");
}

//gcc -Wall -o acceptor_test acceptor_test.c -lwiringPi
//sudo ./acceptor_test