/*
DuinoDouse V1 - Server

Midi Controlled Arduino Douser

 - Requires two Arduino Uno's. One to recieve midi signal from QLab (requires SparkFun midi shield)
   and one connected by two conductors at the projector itself
 - Arduino MIDI library by FortySevenEffects is used. It can be found at
   https://github.com/FortySevenEffects/arduino_midi_library
*/

#include <MIDI.h>                       //Include the Arduino MIDI library

MIDI_CREATE_DEFAULT_INSTANCE();

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  int ClientOutput = 2;
  pinMode(2, OUTPUT);
  digitalWrite(ClientOutput, HIGH);     //When MIDI Note On is received, output HIGH to client Arduino.
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  int ClientOutput = 2;
  pinMode(2, OUTPUT);
  digitalWrite(ClientOutput, LOW);      //When MIDI Note Off is received, output LOW to client Arduino.
}

void setup()
{
  // Connect the handleNoteOn function to the library,
  // so it is called upon reception of a NoteOn.
  MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function

  //  Do the same for NoteOffs
  MIDI.setHandleNoteOff(handleNoteOff);

  // Initiate MIDI communications, listen to all channels
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
  MIDI.read(); // Nothing else is needed due to handleNoteOn callback
}
