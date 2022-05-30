#include <iostream>
#include <fstream>
using namespace std;

class olshop {
	public :
		void login();
		void saldo();
		void menu();
		void barang_dibeli();
		void kota_tujuan();
		void data_diri();
		void voucher_barang();
		void proteksi();
		void ekspedisi();
		void voucher_ongkir();
		void output();
		
	private :
		ofstream file;
		string user, password, nama, alamat, nama_barang[20], pilihan, jasa;
		char coba, ulang, top_up, pil_proteksi;
		int barang[20], harga[20], jumlah[20], total_harga[20];
		int point, total_belanja, total_ulang, vc_brg;
		float diskon, hasil_diskon;
    float hasil_proteksi, hasil_ongkir, hasil_akhir;
		int kota, jnt, jne, ongkir, jasa_kirim, vc_ongkir, sisa_saldo;
};

void olshop::login() {
	do {
		cout<<"Menu Login"<<endl;
		cout<<"User     : ";
		cin>>user;
		cout<<"Password : ";
		cin>>password;
		cout<<endl;
		cout<<"============================================================="<<endl;
		
		if(user == "alpro", password == "responsi") {
			olshop out;
			
			out.saldo();
			out.menu();
			out.barang_dibeli();
			out.kota_tujuan();
			out.data_diri();
			out.voucher_barang();
			out.proteksi();
			out.ekspedisi();
			out.voucher_ongkir();
			out.output();
			
			
			cout<<endl<<"= Terima Kasih ="<<endl;
		} else {
			cout<<"Maaf user atau password yang anda masukkan salah"<<endl;
			cout<<endl;
		}
		
		cout<<"Apakah ingin mencoba lagi ? (y/t) : ";
			cin>>coba;
			cout<<endl;
			cout<<"============================================================="<<endl;
	} while(coba == 'y');
}

void olshop::saldo() {
  point = 0;
	cout<<"Saldo : "<<point<<endl;
	cout<<"Apakah ingin top up ? (y/t) : ";
	cin>>top_up;
	if(top_up == 'y') {
		cout<<"Jumlah yang ingin ditop up kan : ";
		cin>>point;
	}
	cout<<"Saldo : "<<point<<endl<<endl;
}

void olshop::menu() {
	cout<<"============================================================="<<endl;
	cout<<"=====                      El-Shop                      ====="<<endl;
	cout<<"============================================================="<<endl;
	cout<<"== 1. Lampu LED RGB                             = Rp 24999 =="<<endl;
	cout<<"== 2. Lampu Tumbler                             = Rp 14700 =="<<endl;
	cout<<"== 3. Lampu Disco LED                           = Rp 12999 =="<<endl;
	cout<<"== 4. Lampu Tidur LED                           = Rp 12000 =="<<endl;
	cout<<"== 5. Lampu Disco Speaker                       = Rp 30999 =="<<endl;
	cout<<"============================================================="<<endl<<endl;
}

void olshop::barang_dibeli() {
	int i = 1;
	total_belanja = 0;
	do {
		cout<<"Pilih barang yang dibeli dengan menggunakan opsi angka !"<<endl;
		cout<<"Barang yang akan dibeli : ";
		cin>>barang[i];
		switch(barang[i]) {
			case 1 :
				nama_barang[i] = "Lampu LED RGB";
				harga[i] = 24999;
				break;
			case 2 :
				nama_barang[i] = "Lampu Tumbler";
				harga[i] = 14700;
				break;
			case 3 :
				nama_barang[i] = "Lampu Disco LED";
				harga[i] = 12999;
				break;
			case 4 :
				nama_barang[i] = "Lampu Tidur LED";
				harga[i] = 12000;
				break;
			case 5 :
				nama_barang[i] = "Lampu Disco Speaker";
				harga[i] = 30999;
				break;
		}
		cout<<"Harga barang = "<<harga[i]<<endl;
		cout<<"Jumlah barang yang dipilih : ";
		cin>>jumlah[i];
		total_harga[i] = harga[i] * jumlah[i];
		cout<<"Total harga barang = "<<total_harga[i]<<endl<<endl;
		total_belanja = total_belanja + total_harga[i];
		
		cout<<"Masih ada barang yang ingin dibeli ? (y/t) : ";
		cin>>ulang;
		cout<<endl<<"============================================================="<<endl;
		
		i++;
		total_ulang = total_ulang + 1;
	} while(ulang == 'y');
	
	cout<<"Total harga belanja = "<<total_belanja<<endl<<endl<<endl;
}

void olshop::kota_tujuan() {
	cout<<"============================================================="<<endl;
	cout<<"=====                    Kota Tujuan                    ====="<<endl;
	cout<<"============================================================="<<endl;
	cout<<"== 1. Jakarta                        3. Surabaya           =="<<endl;
	cout<<"== 2. Bandung                        4. Yogyakarta         =="<<endl;
	cout<<"============================================================="<<endl<<endl;
	cout<<"Kota yang tempat tinggal : ";
	cin>>kota;
	switch(kota) {
		case 1 :
			jnt = 14000;
			jne = 16000;
			break;
		case 2 :
			jnt = 11000;
			jne = 13000;
			break;
		case 3 :
			jnt = 8000;
			jne = 10000;
			break;
		case 4 :
			jnt = 5000;
			jne = 7000;
			break;
	}
}

void olshop::data_diri() {
	cout<<endl;
	cout<<"Data Diri Pemesan"<<endl;
	cout<<"Nama   : ";
	cin>>nama;
	cout<<"Alamat : ";
	cin>>alamat;
	cout<<endl;
}

void olshop::voucher_barang() {
	if(total_belanja > 30000) {
		cout<<"1. voucher diskon 10%"<<endl;
		cout<<"2. no voucher"<<endl;
		cout<<"Pilih voucher diskon : ";
		cin>>vc_brg;
		if(vc_brg == 1) {
			diskon = total_belanja * 0.1;
			hasil_diskon = total_belanja - diskon;
		} else {
			hasil_diskon = total_belanja;
		}
	} else if(total_belanja > 50000) {
		cout<<"1. voucher diskon 10%"<<endl;
		cout<<"2. voucher diskon 20%"<<endl;
		cout<<"3. no voucher"<<endl;
		cout<<"Pilih voucher diskon : ";
		cin>>vc_brg;
		switch(vc_brg) {
			case 1 :
				diskon = total_belanja * 0.1;
				hasil_diskon = total_belanja - diskon;
				break;
			case 2 :
				diskon = total_belanja * 0.2;
				hasil_diskon = total_belanja - diskon;
				break;
			case 3 :
				hasil_diskon = total_belanja;
				break;
		}
	}
	cout<<"Total biaya = "<<hasil_diskon<<endl<<endl;
}

void olshop::proteksi() {
	cout<<"Apakah anda ingin menggunakan proteksi dengan biaya Rp 500,- atau tidak?"<<endl;
	cout<<"(y/t) : ";
	cin>>pil_proteksi;
	if(pil_proteksi == 'y') {
		pilihan = "menggunakan";
		hasil_proteksi = hasil_diskon + 500;
	} else {
		pilihan = "tidak menggunakan";
		hasil_proteksi = hasil_diskon;
	}
	cout<<"Total biaya = "<<hasil_proteksi<<endl<<endl;
}

void olshop::ekspedisi() {
	cout<<"Ekspedisi Pengiriman"<<endl;
	cout<<"1.JNE"<<endl;
	cout<<"2.JNT"<<endl;
	cout<<"Silahkan pilih ekspedisi pengiriman yang anda inginkan : ";
	cin>>jasa_kirim;
	if(jasa_kirim == 1) {
		jasa = "JNE";
		ongkir = jne;
		hasil_ongkir = hasil_proteksi + ongkir;
	} else {
		jasa = "JNT";
		ongkir = jnt;
		hasil_ongkir = hasil_proteksi + ongkir;
	}
	cout<<"Total biaya = "<<hasil_ongkir<<endl<<endl;
}

void olshop::voucher_ongkir() {
	if(total_belanja > 30000) {
		cout<<"1. voucher gratis ongkir"<<endl;
		cout<<"2. no voucher"<<endl;
		cout<<"Pilih voucher : ";
		cin>>vc_ongkir;
		if(vc_ongkir == 1) {
			hasil_akhir = hasil_ongkir - ongkir;
		} else {
			hasil_akhir = hasil_ongkir;
		}
	}
	cout<<"Total biaya = "<<hasil_akhir<<endl<<endl;
	sisa_saldo = point - hasil_akhir;
}

void olshop::output() {
	file.open("struk.txt");
	
	file<<"============================================================="<<endl;
	file<<"=====                  Struk Pembelian                  ====="<<endl;
	file<<"============================================================="<<endl;
	file<<"Barang yang dibeli : "<<endl;
	for(int i = 1; i <= total_ulang; i++) {
		file<<i<<". Nama Barang        = "<<nama_barang[i]<<endl;
		file<<"   Harga Barang       = "<<harga[i]<<endl;
		file<<"   Jumlah Barang      = "<<jumlah[i]<<endl;
		file<<"   Total Harga Barang = "<<total_harga[i]<<endl;
	}
	file<<"============================================================="<<endl;
	file<<"Nama                = "<<nama<<endl;
	file<<"Alamat              = "<<alamat<<endl;
	file<<"Total Biaya Pesanan = "<<total_belanja<<endl;
	file<<"Diskon              = "<<diskon<<endl;
	file<<"Ongkir              = "<<ongkir<<endl;
	file<<"Proteksi            = "<<pilihan<<endl;
	file<<"Jasa Pengiriman     = "<<jasa<<endl;
	file<<"Biaya Akhir         = "<<hasil_akhir<<endl;
	file<<"Sisa Saldo          = "<<sisa_saldo<<endl;
	file<<"============================================================="<<endl;
}

int main() {
	olshop out;
	
	out.login();
	
	return 0;
}

