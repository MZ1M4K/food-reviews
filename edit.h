#ifndef EDIT_H
#define EDIT_H

void rest_add(struct rest**, struct rest*);
rest* rest_id(struct rest*,struct rest*);
void rest_hodn_add(struct rest*,struct rest*,struct hodnoceni*,struct hodnoceni*);
void rest_del(rest**,rest*);

#endif