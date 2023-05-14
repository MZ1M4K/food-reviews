#ifndef SERIALISATION_H
#define SERIALISATION_H


void save_file(struct rest*,struct rest*, struct hodnoceni*, struct hodnoceni*);
void read_file(struct rest**,struct rest*, struct hodnoceni*, struct hodnoceni*);

#endif