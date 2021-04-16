#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	class zd {
		ifstream plik;
		
		public:
			zd();
			~zd();
			void wczyt();
			bool sprawdzenie(string s);
	};
	
	zd::zd() {
		plik.open("ciagi.txt");
	}
	
	void zd::wczyt() {
		string ciag;
		int ilosc=0;
		if(plik.good()) {
			while(!plik.eof()) {
			plik>>ciag;
			if(this->sprawdzenie(ciag)) {
			ilosc++;
				}
			}		
		}
		cout<<ilosc;
	}
	
	bool zd::sprawdzenie(string ciag) {
		for(int i=0; i<ciag.length(); i++) {
		if(ciag[i]=='1' && ciag[i+1]=='1') {
		return false;
		}
	}
		return true;
	}
	
	zd::~zd() {
		plik.close();
	}

int main(int argc, char** argv) {
	zd a;
	a.wczyt();
	return 0;
}
