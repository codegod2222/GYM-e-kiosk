#include "PaperPayment.h"
#include "ui_PaperPayment.h"
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

PaperPayment::PaperPayment(QWidget *parent, int price) :
    QDialog(parent),
    ui(new Ui::PaperPayment)
{
    ui->setupUi(this);
    this->ui->kwota->setText(QString::number(price));
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    wiringPiSetupGpio();
    int result = pay(TEN);
    if(result){
        if(registrationInfoScreen == nullptr){
            registrationInfoScreen = new RegistrationInfoScreen(this, "ZAPACONO POMY—LNIE");
            registrationInfoScreen->move(0,0);
            registrationInfoScreen->show();
            while(registrationInfoScreen->isActiveWindow()){

            }
            delete registrationInfoScreen;
        }
    }else{
        if(registrationInfoScreen == nullptr){
            registrationInfoScreen = new RegistrationInfoScreen(this, "SPRàBUJ JESZCZE RAZ");
            registrationInfoScreen->move(0,0);
            registrationInfoScreen->show();
            while(registrationInfoScreen->isActiveWindow()){

            }
            delete registrationInfoScreen;
        }
    }
}

PaperPayment::~PaperPayment()
{
    delete ui;
}
