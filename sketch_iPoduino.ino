#include <HardwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int TX_PIN = 21;
const int RX_PIN = 20;
const int PAUSE = 4;
const int SKIP = 3;
bool state = 1;
int song = 1;
int stop;
int next;

//need to include button pins

HardwareSerial mySerial1(1);

DFRobotDFPlayerMini player;


void setup() {

  pinMode(PAUSE, INPUT_PULLUP);
  pinMode(SKIP, INPUT_PULLUP);
  Serial.begin(115200);
  mySerial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  delay(1000);


  //player.begin(mySerial1);

  if (!player.begin(mySerial1)){
    	Serial.println("Connecting to DFPlayer Mini failed!");
	}
  
  player.volume(30);
  player.play(1);

}

void loop() {

  next = digitalRead(SKIP);
  if(next == LOW) {
    /*song++;
    
    if (song > 3) {
      song = 1;
    }

    player.play(song);*/

    player.next();
  }

  stop = digitalRead(PAUSE);

  if(stop == LOW) {
    if (state) {
      player.pause();
      state = 0;
    } else {
      player.start();
      state = 1;
    }
  }

}
