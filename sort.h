#ifndef SORT_H
#define SORT_H

void rest_name_search(struct rest**,struct rest*);
rest* rest_id_search(struct rest*,struct rest*);
void sort_id(struct rest**,struct rest*);
void sort_abc(struct rest**,struct rest*);
void sort_hodn(struct rest**,struct rest*);
int rest_countf(struct rest*,struct rest*);

#endif