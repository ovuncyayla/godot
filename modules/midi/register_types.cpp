/* register_types.cpp */

#include "register_types.h"
#include "class_db.h"
#include "miditest.h"

void register_midi_types() {

        ClassDB::register_class<MidiTest>();
}

void unregister_midi_types() {
   //nothing to do here
}
