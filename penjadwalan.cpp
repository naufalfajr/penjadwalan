/*File		  : penjadwalan.cpp
  Deskripsi	  : memilih pertandingan dengan waktu yang tidak bentrok
  Pembuat	  : Muhammad Naufal Fajri/24060118130087
  Tanggal	  : 19 Desember 2020
*/
#include <iostream>
#include <vector>

using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void BubbleSort(int *nomor, int *mulai, int *selesai, int N){
    int pass, i;

    for(pass = 0; pass < N-1; pass++){
        for(i = 0; i < N-pass-1; i++){
            if(selesai[i] > selesai[i+1]){
                swap(&selesai[i],&selesai[i+1]);
                swap(&nomor[i],&nomor[i+1]);
                swap(&mulai[i],&mulai[i+1]);
            }
        }
    }
}

void penjadwalan(int *nomor, int *mulai, int *selesai, vector<int> &jadwal, int N){
    int j = 0;

    jadwal.push_back(nomor[0]); // deklarasi jadwal pertama pasti yang selesai pertama
    for (int i = 1; i < N; i++)
    {
        if (mulai[i] >= selesai[j])
        {
            jadwal.push_back(nomor[i]);
            j = i;
        }   
    }
}

int main(){
    // kamus
    int n;
    // algoritma
    // inputan
    cout << "--- Masukkan jumlah pertandingan ---" << endl;
    cin >> n;
    int nomor[n];
    int mulai[n];
    int selesai[n];
    vector<int> jadwal;

    cout << "--- Masukkan: waktu mulai   waktu selesai ---" << endl;
    for (int i = 0; i < n; i++)
    {
        nomor[i] = i+1;
        cout << "pertandingan nomor " << nomor[i] << " :";
        cin >> mulai[i];
        cin >> selesai[i];
    }
    //asumsi awal jadwal terurut
    BubbleSort(nomor,mulai,selesai,n);
    // jadwal terurut menurut waktu selesai
    cout << endl << "--- Pertandingan terurut ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "pertandingan nomor " << nomor[i] << " : " << mulai[i] << " " << selesai[i];
        cout << endl;
    }
    // activity selection
    penjadwalan(nomor,mulai,selesai,jadwal,n);
    // print jadwal
    cout << endl << "--- Pertandingan yang dipilih ---" << endl;
    for(auto it = jadwal.begin(); it != jadwal.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}