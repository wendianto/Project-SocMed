#include "tubes.h"

using namespace std;

void createlist(list &l)
{
    first(l)=NULL;
    last(l)=NULL;
};

void dealokasistatus(address p)
{
    free(p);
};

void dealokasikomentar(address_k p)
{
    free(p);
};

address alokasistatus (infostatus x)
{
    address p = new elmstatus;
    info(p)=x;
    next(p)=NULL;
    prev(p)=NULL;
    firstchild(p)=NULL;
    lastchild(p)=NULL;
    return p;
};


address_k alokasikomentar (infokomentar xanak)
{
    address_k c = new elmkomentar;
    infok(c)=xanak;
    nextk(c)=NULL;
    prevk(c)=NULL;
    return c;
};

int incrementstatus (int x)
{
    x=x+47;
    return x;
}

int incrementkomentar (int x)
{
    x=x+17;
    return x;
}

int incrementuser (int x)
{
    x=x+38;
    return x;
}

address findStat (list l,int idstat)
{
    address p;
    p=first(l);
    if(first(l)!=NULL)
    {
        while (p!=NULL)
        {
            if(info(p).idstatus==idstat)
            {
                return p;
            }
            p=next(p);
        }

    }
    return NULL;
}

void insertFirstKomen(address &p,address_k c)
{
    if (firstchild(p)!=NULL)
    {
        nextk(c)=firstchild(p);
        prevk(firstchild(p))=c;
        firstchild(p)=c;
    }
    else
    {
        firstchild(p)=c;
        lastchild(p)=c;
    }
}

void insertLastKomen(address &p,address_k c)
{
    if (firstchild(p) != NULL)
    {
        prevk(c)=lastchild(p);
        nextk(lastchild(p))=c;
        lastchild(p)=c;
    }
    else
    {
        firstchild(p)=c;
        lastchild(p)=c;
    }
}

void insertAfterKomen(address &p,address_k c,int idkomenprec)
{
    address_k z;
    if(firstchild(p) != NULL)
    {
        z=firstchild(p);
        while((infok(z).idkomentar)!=(idkomenprec) || (z!=lastchild(p)))
        {
            z=nextk(z);
        }
        if((infok(z).idkomentar)==idkomenprec && z!=lastchild(p))
        {
            prevk(c)=z;
            nextk(c)=nextk(z);
            prevk(nextk(z))=c;
            nextk(z)=c;
        }
        else if (z==lastchild(p))
        {
            insertLastKomen(p,c);
        }
        else
        {
            cout<<"Id komentar tidak ditemukan ";
        }
    }
    else
    {
        insertFirstKomen(p,c);
    }
}



void insertFirstStatus (list &l, address p)
{
    if (first(l)!=NULL)
    {
        next(p)=first(l);
        prev(first(l))=p;
        first(l)=p;
    }
    else
    {
        first(l)=p;
        last(l)=p;
    }

}
void insertLastStatus (list &l, address p)
{
    if (first(l)!=NULL)
    {
        prev(p)=last(l);
        next(last(l))=p;
        last(l)=p;
    }
    else
    {
        first(l)=p;
        last(l)=p;
    }
}
void insertAfterStatus (list &l, address p,int idstatprec)
{
    address z;
    if(first(l) != NULL)
    {
        z=first(l);
        while((info(z).idstatus)!=(idstatprec) || (z!=last(l)))
        {
            z=next(z);
        }
        if((info(z).idstatus)==idstatprec && z!=last(l))
        {
            prev(p)=z;
            next(p)=next(z);
            prev(next(z))=p;
            next(z)=p;
        }
        else if (z==last(l))
        {
            insertLastStatus(l,p);
        }
        else
        {
            cout<<"Id komentar tidak ditemukan ";
        }
    }
    else
    {
        insertFirstStatus(l,p);
    }
}


address deleteFirstStatus(list &l)
{
    address P=first(l);
    if (first(l)!=NULL)
    {
        if (next(P)==NULL)
        {
            first(l)=NULL;
            last(l)=NULL;
            return P;
        }
        else
        {
            first(l)=next(first(l));
            next(P)=NULL;
            prev(P)=NULL;
            prev(first(l))=NULL;
            return P;
        }
    }
    return NULL;
}
address deleteLastStatus(list &l)
{

    if (first(l)!=NULL)
    {
        address P=first(l);
        if (next(P)==NULL)
        {
            deleteFirstStatus(l);
        }
        else
        {
            address Q=last(l);
            last(l)=prev(last(l));
            prev(Q)=NULL;
            next(last(l))=NULL;
            return Q;
        }
    }
    return NULL;
}

address deleteAfterStatus(list &l, address prec)
{
    if(first(l)!=NULL)
    {
        address P = first(l);
        if(next(P) == NULL)
        {
            deleteFirstStatus(l);
        }
        else
        {
            while(P != NULL)
            {
                if(P == prec)
                {
                    if(next(next(P)) == NULL)
                    {
                        deleteLastStatus(l);
                    }
                    else
                    {
                        address Q = next(P);
                        next(P) = next(next(P));
                        prev(next(P)) = P;
                        next(Q) = NULL;
                        prev(Q) = NULL;
                        return Q;
                    }
                }
                P = next(P);
            }
        }
    }
    return NULL;
}

int cariuser(list l,string nama)
{
    address p=first(l);
    address_k pencari;
    if(first(l)!=NULL)
    {
        do
        {
            if (info(p).nama==nama)
            {
                return info(p).iduser;
            }
            if(firstchild(p)!=NULL)
            {
                pencari=firstchild(p);
                do
                {
                    if(infok(pencari).nama==nama)
                    {
                        return infok(pencari).iduser;
                    }
                    else
                    {
                        pencari=nextk(pencari);
                    }
                }
                while(pencari!=NULL);
            }
            p=next(p);
        }
        while(p!=NULL);
    }
    return -1;

}

address_k tambahkomentar(list l,address &p,infokomentar i,int curser,int curkom)
{
    if(cariuser(l,i.nama)!=-1)
    {
        i.iduser=cariuser(l,i.nama);
    }
    else
    {
        i.iduser=incrementuser(curser);
    }
    i.idkomentar=incrementkomentar(curkom);

    address_k elko=alokasikomentar(i);
    insertLastKomen(p,elko);
    return elko;
};



address tambahstatus (list &l,infostatus x,int curser,int curstat)
{
    if(cariuser(l,x.nama)!=-1)
    {
        x.iduser=cariuser(l,x.nama);
    }
    else
    {
        x.iduser=incrementuser(curser);
    }
    x.idstatus=incrementstatus(curstat);

    address z=alokasistatus(x);
    insertFirstStatus(l,z);
    return z;
}

void carikomentarID(list l,int idser)
{
    address p=first(l);
    address_k pencari;
    if(first(l)!=NULL)
    {
        do
        {
            if(firstchild(p)!=NULL)
            {
                pencari=firstchild(p);
                do
                {
                    if(infok(pencari).iduser==idser)
                    {
                        cout<<"Status                : "<<info(p).status<<
                            endl<<"Nama pembuat Status   : "<<info(p).nama<<
                            endl<<"Komentar "<<infok(pencari).nama<<"  : "<<infok(pencari).komentar<<
                            endl<<"Tanggal komentar      : "<<infok(pencari).tanggal.tanggal<<"-"<<infok(pencari).tanggal.bulan<<"-"<<infok(pencari).tanggal.tahun;
                    }
                    pencari=nextk(pencari);
                }
                while(pencari!=NULL);
            }
            p=next(p);
        }
        while(p!=NULL);
    }
}

void trendingstatus(list l)
{
    address p=first(l);
    address adrtrend;
    address_k pencari;
    int cari=0;
    int c=0;
    int terbesar=0;
    if(first(l)!=NULL)
    {
        do
        {
            if(firstchild(p)!=NULL)
            {
                pencari=firstchild(p);
                do
                {
                    c=c+1;
                    pencari=nextk(pencari);
                }
                while(pencari!=NULL);
                if (c>terbesar)
                {
                    terbesar=c;
                    adrtrend=p;
                }
            }
            p=next(p);
        }
        while(p!=NULL);
        if(c!=0)
        {
            cout<<"ID Status Trending : "<<info(adrtrend).idstatus<<
                endl<<"Status             :"<<info(adrtrend).status<<
                endl<<"Feedback status    :"<<terbesar<<
                endl<<"Pembuat Status     :"<<info(adrtrend).nama;
        }
        else
        {
            cout<<"Tidak ada status yang di feedback .";
        }
    }
    else
    {
        cout<<"Beranda tidak memiliki aktivitas status. ";
    }
}

void caristatusID (list l,int idser)
{
    address p;
    int x=0;
    p=first(l);
    if(first(l)!=NULL)
    {
        while (p!=NULL)
        {
            if(info(p).iduser==idser)
            {
                cout<<"ID Status    : "<<info(p).idstatus<<endl
                    <<"Nama         : "<<info(p).nama<<endl
                    <<"Stat         : "<<info(p).status<<endl
                    <<"Tanggal Post : "<<info(p).tanggal.tanggal<<"-"<<info(p).tanggal.bulan<<"-"<<info(p).tanggal.tahun;
                cout<<endl;
                cout<<endl;
                x=x+1;
            }
            p=next(p);
        }
        if (x!=0)
        {
            cout<<"---------------------------------------------------------------------"<<endl;
        }
        else
        {
            cout<<"Tidak ada ID User yang ditemukan . ";
        }
    }
    else
    {
        cout<<"Tidak ada status";
    }
}


void caristatusnama (list l, string nama)
{
    address p;
    address q;
    int x=0;
    p=first(l);
    if(first(l)!=NULL)
    {
        while (p!=NULL)
        {
            if(info(p).nama==nama)
            {
                cout<<"ID Status    : "<<info(p).idstatus<<endl
                    <<"Nama         : "<<info(p).nama<<endl
                    <<"Stat         : "<<info(p).status<<endl
                    <<"Tanggal Post : "<<info(p).tanggal.tanggal<<"-"<<info(p).tanggal.bulan<<"-"<<info(p).tanggal.tahun;
                cout<<endl;
                cout<<"---------------------------------------------------------------------";
                cout<<endl;
                q=p;
                x=x+1;
            }
            p=next(p);
        }
        if (x!=0)
        {
            carikomentarID(l,info(q).iduser);
        }
        else
        {
            cout<<"Tidak ada ID user yang ditemukan .";
        }
    }
    else
    {
        cout<<"Tidak ada status";
    }
}

void editstatus (list &l,int idyangdiedit)
{
    string n;
    address p=findStat(l,idyangdiedit);
    if (p!=NULL)
    {
        cout<<"Masukkan Isi Status : ";
        cin.ignore();
        getline(cin,n);
        cin.ignore();
        info(p).status=n;
        cout<<"Nama     : "<<info(p).nama<<endl;
        cout<<"ID User  : "<<info(p).iduser<<endl;
        cout<<"Status   : "<<info(p).status<<endl;
        cout<<endl;
        cout<<"EDIT STATUS berhasil. "<<endl;
    }
    else
    {
        cout<<"EDIT STATUS tidak berhasil. ID Status tidak ditemukan.";
    }
}
address_k findKomentar(address p,int idkomentar)
{
    address_k c=firstchild(p);
    if (firstchild(p)!=NULL)
    {
        while (c!=NULL)
        {
            if (infok(c).idkomentar==idkomentar)
            {
                return c;
            }
            c=nextk(c);
        }
    }
    return NULL;
}
address_k deleteFirstKomen (address &p)
{
    address_k con;
    if (firstchild(p)!=NULL && firstchild(p)!=lastchild(p))
    {
        con=firstchild(p);
        firstchild(p)=nextk(firstchild(p));
        prevk(firstchild(p))=NULL;
        return con;
    }
    else if(firstchild(p)==lastchild(p))
    {
        con=firstchild(p);
        firstchild(p)=NULL;
        lastchild(p)=NULL;
        return con;
    }
    else
    {
        return NULL;
    }
}


address_k deleteLastKomen(address &p)
{
    address_k con;
    if (firstchild(p)!=NULL && firstchild(p)!=lastchild(p))
    {
        con = lastchild(p);
        lastchild(p)=prevk(lastchild(p));
        nextk(lastchild(p))=NULL;
        return con;
    }
    else if(firstchild(p)==lastchild(p))
    {
        con=lastchild(p);
        firstchild(p)=NULL;
        lastchild(p)=NULL;
        return con;
    }
    else
    {
        return NULL;
    }
}

address_k deleteAfterKomen(address &p,address_k idkomen)
{
    address_k q;
    if(idkomen!=(firstchild(p)))
    {
        q=nextk(idkomen);
        idkomen=nextk(q);
        prevk(nextk(q))=idkomen;
        nextk((q))=NULL;
        prevk((q))=NULL;
        return q;
    }
    else
    {
        return NULL;
    }
}

address_k deletekomentar(address &p,int idkomentar)
{
    address_k c=findKomentar(p,idkomentar);
    address_k d;
    if (c==firstchild(p))
    {
        d=deleteFirstKomen(p);
        return d;
    }
    else if (c==lastchild(p))
    {
        d=deleteLastKomen(p);
        return d;
    }
    else if(c==NULL)
    {
        return NULL;
    }
    else
    {
        d=deleteAfterKomen(p,prevk(c));
        return d;
    }

}

address deletestatusdankomentar(list &l,int idstatus)
{
    address q;
    address p=findStat(l,idstatus);
    if (p==first(l))
    {
        q=deleteFirstStatus(l);
        return q;
    }
    else if (p==last(l))
    {
        q=deleteLastStatus(l);
        return q;
    }
    else if(p==NULL)
    {
        return NULL;
    }
    else
    {
        q=deleteAfterStatus(l,prev(p));
        return q;
    }

}
void viewlistkomentar(list l,int x)

{
    address p=findStat(l,x);
    address_k c=firstchild(p);
    while (c!=NULL)
    {
        cout<<"Nama User           : "<<infok(c).nama<<endl
            <<"ID User             : "<<infok(c).iduser<<endl
            <<"ID Komentar         : "<<infok(c).idkomentar<<endl
            <<"Komentar            : "<<infok(c).komentar<<endl
            <<"Tanggal Komentar    : "<<infok(c).tanggal.tanggal<<"-"<<infok(c).tanggal.bulan<<"-"<<infok(c).tanggal.tahun<<endl<<endl;
        c=nextk(c);
    }
}


void viewStatus(list l)
{
    address p=first(l);
    if (first(l)!=NULL)
    {
        while (p!=NULL)
        {
            cout<<"ID User           : "<<info(p).iduser<<endl
                <<"ID Status         : "<<info(p).idstatus<<endl
                <<"Nama              : "<<info(p).nama<<endl
                <<"Status            : "<<info(p).status<<endl<<endl;
            p=next(p);
        }
    }
    else
    {
        cout<<"Tidak ada aktivitas .";
    }
}

void akunterbanyakkomen(list l,address p)
{
    address temp;
    address_k tempk;
    address_k c;
    string nama,namafix;
    int id;
    int b=0;
    int z=0;
    int i=0;
    int max=0;
    temp=alokasistatus(info(p));
    c=firstchild(p);
    while(c!=NULL)
    {
        tempk=alokasikomentar(infok(c));
        insertLastKomen(temp,tempk);
        z=z+1;
        c=nextk(c);
    }
    while(b!=z)
    {
        tempk=firstchild(temp);
        id=infok(tempk).iduser;
        while(tempk!=NULL)
        {
            if(infok(tempk).iduser<id)
            {
                id=infok(tempk).iduser;
            }
            tempk=nextk(tempk);
        }

        tempk=firstchild(temp);
        i=0;
        do
        {
            if(infok(tempk).iduser==id)
            {
                i=i+1;
                nama=infok(tempk).nama;
                b=b+1;
                infok(tempk).iduser=999999;
            }
            tempk=nextk(tempk);
        }
        while(tempk!=NULL);
        if(i>max)
        {
            max=i;
            namafix=nama;
        }
    }
    cout<<"ID paling banyak berkontribusi adalah "<<namafix<<endl
        <<"Dengan Jumlah Komentar : "<<max;
}



void sortingstatus(list l)
{
    address p=last(l);
    while(p!=NULL)
    {
        cout<<"15"<<endl;
        cout<<"ID Status        : "<<info(p).idstatus<<
            endl<<"ID User      : "<<info(p).iduser<<
            endl<<"Status       : "<<info(p).status<<
            endl<<"Tanggal      :"<<info(p).tanggal.tanggal<<"-"<<info(p).tanggal.bulan<<"-"<<info(p).tanggal.tahun<<endl<<endl<<"---------------------------------------"<<endl;
        p=prev(p);
    }

}

/*
void sortingtanggalstatus(list l,list l2,list l3,list l4,list &l5)
{
    address p=first(l);
    address p2;
    address p3;
    address p4;
    address p5;
    int sc=0;
    string n;
    while(p!=NULL)
    {
        cout<<"1";
        insertLastStatus(l2,p);
        p=next(p);
    }
    p5=first(l5);
    while(p5!=NULL)
    {
            deletestatusdankomentar(l5,info(p5).idstatus);
            p5=next(p5);
    }
    while (first(l2)!=NULL)
    {
        cout<<"2";
        p2=first(l2);
        while (p2!=NULL)
        {
            cout<<"3";
            if(info(p2).tanggal.tahun>=sc)
            {
                sc=info(p2).tanggal.tahun;
            }
            p2=next(p2);
        }
        cout<<"4";
        p2=first(l2);
        while(p2!=NULL)
        {
            cout<<"5";
            if(info(p2).tanggal.tahun==sc)
            {
                insertLastStatus(l3,p2);
                deletestatusdankomentar (l2, info(p2).idstatus);
            }
            p2=next(p2);
        }
        p2=first(l2);
        cout<<"6";
        while(first(l3)!=NULL)
        {
            sc=0;
            cout<<"7";
            p3=first(l3);
            while(p3!=NULL)
            {
                cout<<"8";
                if(info(p3).tanggal.bulan>=sc)
                {
                    sc=info(p3).tanggal.bulan;
                }
                p3=next(p3);
            }
            p3=first(l3);
            while(p3!=NULL)
            {
                cout<<"9";
                if(info(p3).tanggal.bulan==sc)
                {
                    insertLastStatus(l4,p3);
                    deletestatusdankomentar(l3,info(p3).idstatus);
                }
                p3=next(p3);
            }
            p3=first(l3);

            while(first(l4)!=NULL)
            {
                sc=0;
                cout<<"10";
                p4=first(l4);
                while(p4!=NULL)
                {
                    cout<<"11";
                    if(info(p4).tanggal.tanggal>=sc)
                    {
                        sc=info(p4).tanggal.tanggal;
                    }
                    p4=next(p4);
                }
                p4=first(l4);
                while(p4!=NULL)
                {
                    cout<<"12";
                    if(info(p4).tanggal.tanggal==sc)
                    {
                        insertLastStatus(l5,p4);
                        deletestatusdankomentar(l4,info(p4).idstatus);
                    }
                    p4=next(p4);
                }
                p4=first(l4);
            }
            cout<<"13";
        }
    }
    cout<<"14";
    p5=first(l5);
    while(p5!=NULL)
    {
        cout<<"15";
        cout<<"ID Status    : "<<info(p5).idstatus<<
            endl<<"ID User      : "<<info(p5).iduser<<
            endl<<"Status       : "<<info(p5).status<<
            endl<<"Tanggal      :"<<info(p5).tanggal.tanggal<<"-"<<info(p5).tanggal.bulan<<"-"<<info(p5).tanggal.tahun<<endl<<"---------------------------------------";
        p5=next(p5);
    }
    p5=first(l5);

}
*/
