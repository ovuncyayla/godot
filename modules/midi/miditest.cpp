/* miditest.cpp */

#include "miditest.h"

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
}

MidiTest::MidiTest() {
    count = 0;
}
