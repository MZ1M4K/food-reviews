#ifndef MAIN_H
#define MAIN_H
#define SNAME 50
#define SREW 300


typedef struct hodnoceni {
	int znamka;
	char recenze[SREW];
	struct hodnoceni* next;
}hodnoceni;
/*
typedef struct menu {
	char jidlo[SNAME];
	double cena;
	struct menu* next;
}menu;*/
typedef struct rest {
	int id;
	char nazev[SNAME];
	char adresa[SNAME];
	char kuchyne[SNAME];
	char popis[SREW];
	double avg_znamka;
	hodnoceni * prvni_hodn;
	//menu* prvni_menu;
	struct rest* next;
}rest;

void menu(rest**,rest*,hodnoceni*,hodnoceni*);
void rest_detail(rest**,rest*);
void rest_detail_call(int);
int rest_count(rest*,rest*);
void rest_hodn_add(rest*,rest*,hodnoceni*,hodnoceni*);
void rest_edit(rest*);
#endif 