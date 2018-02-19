/* summator.h */
#ifndef MIDITEST_H
#define MIDITEST_H

#include "reference.h"

class MidiTest : public Reference {
    GDCLASS(MidiTest, Reference);

    int count;

protected:
    static void _bind_methods();

public:
    void add(int value);
    void reset();
    int get_total() const;
    int asd();
    int fsynthTest();

    MidiTest();
};

#endif
