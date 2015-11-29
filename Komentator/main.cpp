#include "tubes.h"

using namespace std;

int main()
{
    list l;
    createlist(l);
    list l2;
    list l3;
    list l4;
    list l5;
    createlist(l2);
    createlist(l3);
    createlist(l4);
    createlist(l5);
    int pil;
    int pil2;
    infostatus x;
    infokomentar xanak;
    int idkomen;
    int idstat;
    int iduser;
    string coba;
    string nama;
    address p,q;
    address_k c;
    int curstat=10426;
    int curkom=3523;
    int curser=5219;
    char ch='Y';
    while (ch=='Y')
    {
        system("cls");
        cout <<"===========APLIKASI KOMENTATOR=========="<<endl;
        cout <<"||                                     ||"<<endl;
        cout <<"||              1. Beranda             ||"<<endl;
        cout <<"||            2. Buat Status           ||"<<endl;
        cout <<"||            3. Edit Status           ||"<<endl;
        cout <<"||          4. Trending Status         ||"<<endl;
        cout <<"||         5. Stalk Status User        ||"<<endl;
        cout <<"||           6. Delete Status          ||"<<endl;
        cout <<"||           7. Komen Status           ||"<<endl;
        cout <<"||      8. View Status dan Komentar    ||"<<endl;
        cout <<"||          9. Delete Komentar         ||"<<endl;
        cout <<"||     10. Lihat status[Descending]    ||"<<endl;
        cout <<"|| 11.Cari Komentar yang paling banyak ||"<<endl;
        cout <<"||              0. Selesai             ||"<<endl;
        cout <<"||                                     ||"<<endl;
        cout <<"========================================="<<endl;
        cout<<endl;
        cout<<"Masukan pilihan : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            system("cls");
            viewStatus(l);
            getch();
            break;
        case 2:
            system("cls");
            cin.ignore();
            cout<<"Input Nama User            : ";
            getline(cin,x.nama);
            cout<<"Input Status               : ";
            getline(cin,x.status);
            do{
            cout<<"Masukkan Tahun[2000-2300]  : ";
            cin>>x.tanggal.tahun;}
            while(x.tanggal.tahun<2000 || x.tanggal.tahun>=2300);
            cin.ignore();
            do{
            cout<<"Masukkan Bulan[1-12]       : ";
            cin>>x.tanggal.bulan;}
            while(x.tanggal.bulan<=0 || x.tanggal.bulan>12);
            do{
            cout<<"Masukkan Tanggal[1-31]     : ";
            cin>>x.tanggal.tanggal;}
            while(x.tanggal.tanggal<1 || x.tanggal.tanggal>31);
            p=tambahstatus(l,x,curser,curstat);
            cout<<endl;
            cout<<"======================================"<<endl;
            cout<<"ID Status anda             : "<<info(p).idstatus<<endl;
            curstat=info(p).idstatus;
            if(info(p).iduser>curser)
            {
                curser=info(p).iduser;
                cout<<"ID user baru anda          : "<<info(p).iduser<<endl;
            }
            else
            {
                cout<<"ID User pembuat status     : "<<info(p).iduser<<endl;
            }
            getch();
            break;
        case 3:
            system("cls");
            cout<<"====================================EDIT STATUS======================================"<<endl;
            cout<<"Anda harus menginput ID status . Apakah anda tahu ID Status yang ingin anda edit? (Y/N)";
            cout<<endl<<"(Y/N) = ";
            cin>>coba;
            if (coba=="N")
            {
                viewStatus(l);
            }
            cout<<"Masukkan ID Status : ";
            cin>>idstat;
            editstatus(l,idstat);
            getch();
            break;
        case 4:
            system("cls");
            cout<<"********TRENDING STATUS********"<<endl;
            trendingstatus(l);
            getch();
            break;
        case 5:
            system("cls");
            cout<<"1. Stalk dengan ID User"<<endl
                <<"2. Stalk dengan Nama User"<<endl
                <<"Pilih : ";
            cin>>pil2;
            switch(pil2)
            {
            case 1 :
                system("cls");
                cout<<"Masukkan ID yang ingin distalk : ";
                cin>>iduser;
                cout<<"Riwayat Status"<<endl;
                caristatusID(l,iduser);
                cout<<"Riwayat Komentar"<<endl;
                carikomentarID(l,iduser);
                getch();
                break;
            case 2:
                system("cls");
                cout<<"Masukkan Nama yang ingin distalk : ";
                cin.ignore();
                getline(cin,nama);
                cin.ignore();
                caristatusnama(l,nama);
                getch();
                break;
            default:
                break;
            }
            break;

        case 6:
            system("cls");
            cout<<"====================================DELETE STATUS======================================"<<endl;
            cout<<"Anda harus menginput ID status . Apakah anda tahu ID Status yang ingin anda edit? (Y/N)";
            cout<<endl<<"(Y/N) = ";
            cin>>coba;
            if (coba=="N")
            {
                viewStatus(l);
            }
            cout<<"Masukkan ID Status :";
            cin>>idstat;
            q=deletestatusdankomentar(l,idstat);
            if(q==NULL)
            {
                cout<<"ID Tidak ditemukan . Maaf, DELETE STATUS tidak berhasil .";
                getch();
            }
            else
            {
                cout<<"DELETE STATUS dengan ID Status "<<idstat<<" berhasil .";
            }
            getch();
            break;

        case 7:
            system("cls");
            cout<<"Masukkan ID yang ingin di komentari: ";
            cin>>idstat;
            q=findStat(l,idstat);
            if (q!=NULL){
            cout<<"Status                    : "<<info(q).status<<endl;
            cout<<"Tanggal Status            : "<<info(q).tanggal.tanggal<<"-"<<info(q).tanggal.bulan<<"-"<<info(q).tanggal.tahun<<endl<<endl;
            cout<<"Input Komentar "<<endl<<"------------------------------------------"<<endl;
            cin.ignore();
            cout<<"Input Nama User           : ";
            getline(cin,xanak.nama);
            cout<<"Input Komentar            : ";
            getline(cin,xanak.komentar);
            do{
            cout<<"Masukkan Tahun[2000-2300] : ";
            cin>>xanak.tanggal.tahun;}
            while(xanak.tanggal.tahun<2000 || xanak.tanggal.tahun>=2300);
            cin.ignore();
            do{
            cout<<"Masukkan Bulan[1-12]      : ";
            cin>>xanak.tanggal.bulan;}
            while(xanak.tanggal.bulan<1 || xanak.tanggal.bulan>12);
            do{
            cout<<"Masukkan Tanggal[1-31]    : ";
            cin>>xanak.tanggal.tanggal;}
            while(xanak.tanggal.tanggal<1 || xanak.tanggal.tanggal>31);
            c=tambahkomentar(l,q,xanak,curser,curkom);
            cout<<endl;
            cout<<"======================================"<<endl;
            cout<<"ID Komentar anda : "<<infok(c).idkomentar;
            curkom=infok(c).idkomentar;
            if(infok(c).iduser>curser)
            {
                curser=infok(c).iduser;
                cout<<"ID user baru anda : "<<infok(c).iduser<<endl;
            }
            else
            {
                cout<<"ID User pembuat komentar : "<<infok(c).iduser<<endl;
            }}
            else{
                cout<<"ID status tidak ditemukan. "<<endl;
            }
            getch();
            break;
        case 8:
            system("cls");
            cout<<"====================================VIEW STATUS======================================"<<endl;
            cout<<"Masukkan ID Status  : ";
            cin>>idstat;
            q=findStat(l,idstat);
            if(q!=NULL)
            {
                cout<<"ID Status           : "<<idstat<<endl;
                cout<<"Isi Status          : "<<info(q).status<<endl;
                cout<<"Tanggal Status      : "<<info(q).tanggal.tanggal<<"-"<<info(q).tanggal.bulan<<"-"<<info(q).tanggal.tahun<<endl<<endl;
                cout<<"-------------------------------------------------------"<<endl;
                viewlistkomentar(l,idstat);
            }
            else
            {
                cout<<"ID status tidak ditemukan.";
            }
            getch();
            break;
        case 9:
            system("cls");
            cout<<"============================DELETE KOMENTAR==============================="<<endl;
            cout<<"Input ID Status : ";
            cin>>idstat;
            cout<<"Input ID Komentar : ";
            cin>>idkomen;
            q=findStat(l,idstat);
            if(q!=NULL)
            {
                c=deletekomentar(q,idkomen);
                if(c==NULL)
                {
                    cout<<"ID Komentar tidak ditemukan . DELETE KOMENTAR tidak berhasil .";
                }
                else{
                    cout<<"ID Status berhasil di hapus ";
                }
            }
            else
            {
                cout<<"ID Status tidak ditemukan"<<endl;
            }
            getch();
            break;

        case 10:
            system("cls");
            sortingstatus(l);
            /*sortingtanggalstatus(l,l2,l3,l4,l5);*/
            getch();
            break;
        case 11:
            system("cls");
            cout<<"Input ID Status : ";
            cin>>idstat;
            q=findStat(l,idstat);
            if(q!=NULL){
            akunterbanyakkomen(l,q);}
             else{
            cout<<"ID tidak ditemukan";
            }
            getch();
            break;
        case 0:
            cout<<"Selesai"<<endl;
            ch='N';
            break;
        default:
            ch='Y';
            getch();
        }
    }
}
