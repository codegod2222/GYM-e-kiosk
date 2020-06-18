/* 
 * Controlling NV10 Banknote Acceptor using Arduino Uno
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
 * 10 (INPUT) - escrow control - if LOW, freezes accepted banknote and waits for further commands, HIGH accepts banknotes immediately
 * 11-14 - unused
 * 15 - +12V DC power supply
 * 16 - ground
 * 
 * Connect Arduino GPIO pins to 1-10 pins and the ground of NV10, according to this mapping:
 * NV10 <-> Arduino
 *   1  <->  2
 *   2  <->  3
 *   3  <->  4
 *   4  <->  5
 *   5  <->  6
 *   6  <->  7
 *   7  <->  8
 *   8  <->  9
 *   9  <->  10
 *  10  <->  11
 *  16  <-> GND
 * In fact you can use any GPIO pin set.
 */
#define ACCEPTED_1 2
#define ACCEPTED_2 3
#define ACCEPTED_3 4
#define ACCEPTED_4 5
#define INHIBIT_1 6
#define INHIBIT_2 7
#define INHIBIT_3 8
#define INHIBIT_4 9
#define MACHINE_BUSY 10
//#define FREEZE_ESCROW 11

byte ACCEPTED_PINS[] = {ACCEPTED_1, ACCEPTED_2, ACCEPTED_3, ACCEPTED_4};
byte INHIBIT_PINS[] = {INHIBIT_1, INHIBIT_2, INHIBIT_3, INHIBIT_4};
byte nominalsValues[] = {10, 20, 50, 100};
enum Nominals{
  TEN = 0,
  TWENTY,
  FIFTY,
  HUNDRET
};

// wait for pin 'pin_number' to be in state 'state'
bool wait_for(byte pin_number, byte state, bool timeout_allowed=true)
{
  Serial.print("Waiting for pin ");
  Serial.print(pin_number);
  Serial.println("...");
  int checks_needed = 5;
  int delay_between_checks = 10;
  int stable_state_counter = checks_needed; // if pin pin_number happens to be in a state state iterations_needed times in a row with delay between checks delay_between_checks, we treat it as a stable state and return from the function
  int timeout_counter = 1000; // 10s
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
  Serial.print("Done waiting. Result: ");
  Serial.println(stable_state_counter == 0 ? "GOOD" : "TIMEOUT");
  if(stable_state_counter == 0) return true; // stable state has been achieved
  else return false; // return false in case of timeout
}

void setup() {
  Serial.begin(9600);
  pinMode(ACCEPTED_1, INPUT_PULLUP);
  pinMode(ACCEPTED_2, INPUT_PULLUP);
  pinMode(ACCEPTED_3, INPUT_PULLUP);
  pinMode(ACCEPTED_4, INPUT_PULLUP);
  pinMode(INHIBIT_1, OUTPUT);
  pinMode(INHIBIT_2, OUTPUT);
  pinMode(INHIBIT_3, OUTPUT);
  pinMode(INHIBIT_4, OUTPUT);
  pinMode(MACHINE_BUSY, INPUT_PULLUP);
  //pinMode(FREEZE_ESCROW, OUTPUT);

  digitalWrite(INHIBIT_1, HIGH); // not accepting anything at first
  digitalWrite(INHIBIT_2, HIGH);
  digitalWrite(INHIBIT_3, HIGH);
  digitalWrite(INHIBIT_4, HIGH);
  //digitalWrite(FREEZE_ESCROW, HIGH);
  
  Serial.println("Pins all set up!");
  wait_for(MACHINE_BUSY, HIGH, false); // if machine doesnt respond, throw an exception, wait till dead
}

bool pay(Nominals nominal)
{
  Serial.print("Initializing payment of ");
  Serial.println(nominalsValues[nominal]);
  Serial.println(nominal);
  digitalWrite(INHIBIT_PINS[nominal], LOW); // allow corresponding channel
  bool result = wait_for(ACCEPTED_PINS[nominal], LOW); // "if a note is recognised, the relevant channel line is set LOW for 100 +- 3 milliseconds."
  digitalWrite(INHIBIT_PINS[nominal], HIGH);
  return result;
}

void loop() {
  bool result = pay(FIFTY);
  Serial.println(result ? "\tSuccessfully paid." : "Error occured during payment.");
}
