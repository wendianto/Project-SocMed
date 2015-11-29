#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>


#define info(p) (p)->info
#define next(p) (p)->next
#define prev(p) (p)->prev
#define first(l) ((l).first)
#define last(l) ((l).last)
#define infok(p) (p)->infok
#define nextk(p) (p)->nextk
#define prevk(p) (p)->prevk
#define firstchild(p) p->firstchild
#define lastchild(p) p->lastchild


using namespace std;

struct date
{
    int tahun;
    int bulan;
    int tanggal;
};

struct infostatus
{
    int iduser;
    int idstatus;
    string nama;
    string status;
    date tanggal;
};

struct infokomentar
{
    int iduser;
    int idkomentar;
    string nama;
    string komentar;
    date tanggal;
};

typedef struct elmstatus *address;
typedef struct elmkomentar *address_k;

struct elmstatus
{
    infostatus info;
    address next;
    address prev;
    address_k firstchild;
    address_k lastchild;
    //address_k firstk;
    //address_k lastk;
};

struct elmkomentar
{
    infokomentar infok;
    address_k nextk;
    address_k prevk;
};

struct list{
    address first;
    address last;
};


void createlist(list &l);
address alokasistatus (infostatus x);
address_k alokasikomentar (infokomentar xanak);
void dealokasistatus(address p);
void dealokasikomentar(address_k p);
address findStat (list l,int idstat);
void insertFirstStatus (list &l, address p);
void insertLastStatus (list &l, address p);
void insertAfterStatus (list &l, address p,address prec);
address deleteFirstStatus (list &l);
address deleteLastStatus (list &l);
address deleteAfterStatus (list &l,address prec);
void insertFirstKomen (address &p, address_k c);
void insertLastKomen (address &p, address_k c);
void insertAfterKomen (address &p, address_k c,address_k prec);
address_k deleteFirstKomen (address &p);
address_k deleteLastKomen (address &p);
address_k deleteAfterKomen (address &p,address_k idkomen);
int incrementstatus(int x);
int incrementkomentar(int x);
int incrementuser(int x);
address tambahstatus (list &l,infostatus x,int curser,int curstat);
address deletestatusdankomentar (list &l, int idstatus);
address_k deletekomentar (address &p,int idkomentar);
address_k tambahkomentar(list l,address &p,infokomentar i,int curser,int curkom);
void viewStatus(list l);
int cariuser(list l,string nama);
void caristatusID (list l,int idser);
void caristatusnama (list l,string nama);
void carikomentarID (list l,int idser);
void editstatus (list &l,int idyangdiedit);
void trendingstatus (list l);
void sortingtanggalstatus(list l,list l2,list l3,list l4,list &l5);
void sortingstatus(list l);
void viewlistkomentar(list l,int x);
void akunterbanyakkomen(list l,address p);
address_k findKomentar(address p,int idkomentar);
#endif // TUBES_H_INCLUDED
