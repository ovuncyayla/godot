/* miditest.cpp */

#include "miditest.h"
#include <MidiFile.h>
#include <Options.h>
#include <iostream>
#include <iomanip>
#include <fluidsynth.h>

void MidiTest::add(int value) {

    count += value;
}

void MidiTest::reset() {

    count = 0;
}

int MidiTest::get_total() const {

    return count;
}

void MidiTest::_bind_methods() {

    ClassDB::bind_method(D_METHOD("add", "value"), &MidiTest::add);
    ClassDB::bind_method(D_METHOD("reset"), &MidiTest::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &MidiTest::get_total);
    ClassDB::bind_method(D_METHOD("asd"), &MidiTest::asd);
    ClassDB::bind_method(D_METHOD("fs"), &MidiTest::fsynthTest);
}

MidiTest::MidiTest() {
    count = 0;
}

#define HIGH_HAT    59
#define SNARE       38
#define BASS_DRUM   41

#define QUARTER   120        /* ticks per quarter note */
#define SIXTEENTH 30         /* ticks per sixteenth note */

typedef unsigned char uchar;
//void AddDrumTrack(MidiFile& midifile, int* data, int instrument, int ticks);



int MidiTest::fsynthTest(){
  fluid_settings_t* settings = new_fluid_settings();
  fluid_settings_setint(settings, "synth.polyphony", 128);
  /* ... */
  delete_fluid_settings(settings);
  return 0;
}

int MidiTest::asd() {
   MidiFile outputfile;        // create an empty MIDI file with one track
   outputfile.absoluteTicks(); // time information stored as absolute time
                               // (will be coverted to delta time when written)
   outputfile.setTicksPerQuarterNote(QUARTER);

   int hhdata[50] = {'x', '-', 'x', '-', 'x', '-', 'x', '-', -1};
   int sndata[50] = {'-', '-', 'x', '-', '-', '-', 'x', '-', -1};
   int bsdata[50] = {'x', '-', '-', '-', 'x', '-', '-', '-', -1};

   // AddDrumTrack(outputfile, hhdata, HIGH_HAT,  SIXTEENTH);
   // AddDrumTrack(outputfile, sndata, SNARE,     SIXTEENTH);
   // AddDrumTrack(outputfile, bsdata, BASS_DRUM, SIXTEENTH);

   outputfile.sortTracks();         // make sure data is in correct order
   outputfile.write("/home/spak/Desktop/rhythm.mid");  // write Standard MIDI File twinkle.mid

   return 0;
}

// void AddDrumTrack(MidiFile& midifile, int* data, int instrument, int ticks) {
//    vector<uchar> midievent;   // temporary storage for MIDI events
//    midievent.resize(3);       // set the size of the array to 3 bytes
//    midievent[2] = 64;         // set the loudness to a constant value
//    int notestate = 0;         // 0 = off, 1 = on
//    int i         = 0;
//    int actiontime;
//    int track = midifile.addTrack();      // Add a track to the MIDI file

//    while (data[i] >= 0) {
//       switch (data[i]) {
//          case 'x': case 'X':
//             if (notestate) {
//                // turn off previous note
//                midievent[0] = 0x89;
//                midievent[1] = instrument;
//                actiontime = ticks * i - 1;
//                midifile.addEvent(track, actiontime, midievent);
//             }
//             // turn on current note
//             midievent[0] = 0x99;
//             midievent[1] = instrument;
//             actiontime = ticks * i;
//             midifile.addEvent(track, actiontime, midievent);
//             notestate = 1;
//             break;
//          case '0': case 'o': case 'O':
//             // turn off previous note
//             if (notestate) {
//                midievent[0] = 0x89;
//                midievent[1] = instrument;
//                actiontime = ticks * i - 1;
//                midifile.addEvent(track, actiontime, midievent);
//                notestate = 0;
//             }
//          break;
//       }
//       i++;
//    }

//    if (notestate) {
//       // turn off last note
//       midievent[0] = 0x89;
//       midievent[1] = instrument;
//       actiontime = ticks * i;
//       midifile.addEvent(track, actiontime, midievent);
//    }

// }
