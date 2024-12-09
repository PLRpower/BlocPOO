#ifndef INSTRUMENT_H
#define INSTRUMENT_H

class Instrument {
public:
    virtual ~Instrument() = default;
    virtual void jouer() = 0;
};



#endif //INSTRUMENT_H
