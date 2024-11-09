#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template<class T>
class Vector{
	private:
		T* data;
		int size;
		int capacity;
	public:
		// Ham tao
		Vector(): size(0), capacity(1){
			data = new T[capacity];
		}
		// Ham huy
		~Vector(){
			delete []data;
		}
		// Lay kich thuoc hien tai
		int get_size(){
			return size;
		}
		// gioi han kich thuoc
		void resize(int new_size) {
		    if (new_size <= capacity) return; 
		    capacity = new_size;
		    T* new_data = new T[capacity];
		    for (int i = 0; i < size; ++i) {
		        new_data[i] = data[i];
		    }
		    delete[] data;
		    data = new_data;
		}
		// Them phan tu vao vector
		void push_back(const T& v){
			if(size == capacity){
				capacity *= 2;
				T* new_data = new T[capacity];
				for(int i=0; i < size; i++){
					new_data[i] = data[i];
				}
				delete []data;
				data = new_data;
			}
			data[size++] = v;
		}
		// Lay phan tu theo chi so
		T& operator[](int index){
			return data[index];
		}
		//Hien thi vector
		void display() const {
			for(int i=0; i<size; i++){
				cout<<data[i]<<endl;
			}
		}
		//Xoa phan tu
		void erase(const T& value){
			int index = -1;
			for(int i=0; i<size; i++){
				if(data[i] == value){
					index = i;
					break;
				}
			}
			if(index != -1){
				for(int i=index; i<size-1; i++){
					data[i] = data[i+1];
				}
				--size;
			}
			else{
				cout<<"Khong tim thay phan tu"<<endl;
			}
		}
		//Them phan tu
		void insert(int index, const T& value){
			if(index < 0 || index > size){
				cout<<"\nNgoai pham vi"<<endl;
				return;
			}
			if(size == capacity){
				capacity *= 2;
				T* new_data = new T[capacity];
				for(int i=0; i<size; i++){
					new_data[i] = data[i];
				}
				delete[] data;
			}
			for(int i=size; i>index; i--){
					data[i] = data[i-1];
			}
			data[index] = value;
			++size;
		}
		// Clear
		void clear(){ 
			size = 0;
		}
		// Assign
		void assign(int count, const T& value) {
			if (count > capacity) { 
				resize(count);
			}
			for(int i = 0; i < count; ++i){
				data[i] = value; 
			} 
			size = count;
		}
		// Reserve 
		void reserve(int new_capacity){
			if(new_capacity > capacity){
				resize(new_capacity); 
			}
		} 
		// Swap 
		void swap(Vector& other){ 
			swap(data, other.data);
			swap(size, other.size); 
			swap(capacity, other.capacity); 
		}
		// Max_size 
		int max_size() const {
			return capacity; 
		}
		// Empty 
		bool empty() const{ 
			return size == 0;
		}
};

class DanhMuc{
	private:
		string mahang;
		string tenhang;
		string nsx;
		int sl;
	public:
		DanhMuc(): mahang(""), tenhang(""), nsx(""), sl(0){}
		
		DanhMuc(string ma, string ten, string sx): mahang(ma), tenhang(ten), nsx(sx), sl(sl){}
		
		void display(){
			cout<<"Ma hang: "<<mahang<<" , Ten hang: "<<tenhang<<" , Nha san xuat: "<<nsx<<" , So luong: "<<sl<<endl;
		}
				
		string get_mahang(){
			return mahang;
		}		
		
		string get_tenhang(){
			return tenhang;
		}
		
		int get_sl() {
            return sl;
        }

        void set_sl(int sl) {
            this->sl = sl;
        }
		
		bool operator==(const DanhMuc& other) const {
            return (mahang == other.mahang) && (tenhang == other.tenhang) && (nsx == other.nsx) && (sl == other.sl);
        }
        
		friend ostream& operator<<(ostream& os, const DanhMuc& mathang) {
		    os << mathang.mahang << "," << mathang.tenhang << "," << mathang.nsx << ","<< mathang.sl << endl;
		    return os;
		}		
				
		friend istream& operator>>(istream& is, DanhMuc& mathang){
			cout<<"Nhap ma hang: "<<mathang.mahang;
			is >> mathang.mahang;
			cout<<"Nhap ten hang: "<<mathang.tenhang;
			is >> mathang.tenhang;
			cout<<"Nhap nha san xuat: ";
			is >> mathang.nsx;
			cout<<"Nhap so luong: ";
			is >> mathang.sl;
			return is;
		}
		
		friend ofstream& operator<<(ofstream& os,const DanhMuc& mathang){
			os<< mathang.mahang <<","<<mathang.tenhang<<","<<mathang.nsx<<","<<mathang.sl<<endl;
			return os;
		}
		
		friend ifstream& operator>>(ifstream& is, DanhMuc& mathang){
			getline(is, mathang.mahang, ',');
			getline(is, mathang.tenhang, ',');
			getline(is, mathang.nsx, ',');
			is >> mathang.sl;
			is.ignore();
			return is;
		}
};

class HoaDon{
	private:
		string mahd;
		string mahang;
		string loaihd;
		int slg;
		int ngay;
		int gia;
	public:
		HoaDon():mahd(""),mahang(""),loaihd(""),slg(0),ngay(0),gia(0){}
		
		HoaDon(string hd, string ma, string loai, int solg, int day, int price):mahd(hd), mahang(ma), loaihd(loai), slg(solg), ngay(day), gia(price){}
		
		void display(){
			cout<<mahd<<" , "<<mahang<<" , "<<loaihd<<" , "<<slg<<" , "<<ngay<<" , "<<gia<<endl;
		}
		
		string get_loaihd(){
			return loaihd;
		}
		
		string get_mahang(){
			return mahang;
		}
		
		int get_slg(){
			return slg;
		}
		
		friend ostream& operator<<(ostream& os, const HoaDon& hd) {
		    os << hd.mahd << "," << hd.mahang << "," << hd.loaihd << "," << hd.slg << "," << hd.ngay << "," << hd.gia << endl;
		    return os;
		}

		friend istream& operator>>(istream& is, HoaDon& hd){
			cout<<"Nhap ma hoa don: ";
			is>>hd.mahd;
			cout<<"Nhap ma hang: ";
			is>>hd.mahang;
			cout<<"Nhap loai hoa don: ";
			is>>hd.loaihd;
			cout<<"Nhap so luong hoa don: ";
			is>>hd.slg;
			cout<<"Nhap ngay mua ban: ";
			is>>hd.ngay;
			cout<<"Nhap gia mua ban: ";
			is>>hd.gia;
			return is;
		}
		
		friend ofstream& operator<<(ofstream& os,const HoaDon& hd){
			os<<hd.mahd<<","<<hd.mahang<<","<<hd.loaihd<<","<<hd.slg<<","<<hd.ngay<<","<<hd.gia<<endl;
			return os;
		}
		
		friend ifstream& operator>>(ifstream& is, HoaDon& hd){
			getline(is, hd.mahd, ',');
			getline(is, hd.mahang, ',');
			getline(is, hd.loaihd, ',');
			is >> hd.slg;
			is.ignore();
			is >> hd.ngay;
			is.ignore();
			is >> hd.gia;
			is.ignore();
			return is;
		}
};

class CuaHang{
	private:
		Vector<DanhMuc> mathang;
		Vector<HoaDon> hd;
		Vector<DanhMuc> newmh;
		Vector<HoaDon> newhd;
	public:
		void laydl(const string& filename, bool isMathang){
			ifstream file(filename);
			if(!file){
				cout<<"Khong mo duoc file"<<endl;
				return;
			}
			if (isMathang) {
		    	DanhMuc mh;
		        while(file >> mh) {
		            mathang.push_back(mh);
		        }
		    } 
			else {
		        HoaDon hoadon;
		        while(file >> hoadon) {
		            hd.push_back(hoadon);
		        }
		    }
			file.close();
		}
		
		void ghidl(const string& filename, bool isMathang){
			ofstream file(filename);
			if(!file){
				cout<<"Khong the mo file"<<endl;
				return;
			}
			if (isMathang){
				if (mathang.get_size() == 0) {
			        cout << "Khong co mat hang de ghi vao file." << endl;
			        return;
			    }
				for(int i=0; i<mathang.get_size(); i++){
					file << mathang[i];
				}
			}
			else{
				if (hd.get_size() == 0) {
			        cout << "Khong co hoa don de ghi vao file." << endl;
			        return;
			    }
				for(int i=0; i<hd.get_size(); i++){
					file << hd[i];
				}
			}
			
			file.close();
			cout << "Da ghi du lieu vao file " << filename << endl;
		}
		
		void nhapmathang(){
			int s; 
			cout<<"\nSo luong mat hang can nhap: ";
			cin>>s;
			if(s<=0){
				return;
			}
			for (int i = 0; i < s; i++){
				DanhMuc mh;
				cin >> mh;
				mathang.push_back(mh);
				newmh.push_back(mh);
			}
			cout<<"\nDa nhap mat hang."<<endl;
		}
		
		void xuatmathang(){
			if(newmh.get_size()==0){
				cout<<"\nKhong co mat hang nao"<<endl;
			}
			else{
				cout<<"\nDanh sach mat hang la: "<<endl;
				newmh.display();
			}
		}
		
		void nhaphoadon(){
			int s; 
			cout<<"\nSo luong hoa don can nhap: ";
			cin>>s;
			if(s<=0){
				return;
			}
			for (int i = 0; i < s; i++){
				HoaDon hoadon;
				cin >> hoadon;
				hd.push_back(hoadon);
				newhd.push_back(hoadon);
			}
			cout<<"\nDa nhap hoa don."<<endl;
		}
		
		void xuathoadon(){
			if(newhd.get_size()==0){
				cout<<"\nKhong co hoa don nao"<<endl;
			}
			cout<<"\nDanh sach hoa don: "<<endl;
			newhd.display();
		}
		
		void hienthimathang(const string& filename){
			ifstream file(filename);
			if(!file){
				cout<<"Khong mo duoc file"<<endl;
				return;
			}
			DanhMuc mh;
			cout<<"\nDanh sach mat hang tu file: "<<endl;
			while(file >> mh){
				mh.display();
			}
			file.close();
			if(newmh.get_size()==0){
				cout<<"\nKhong co mat hang nao duoc nhap tu nguoi dung"<<endl;
			}
			else{
				cout<<"\nDanh sach mat hang da nhap tu nguoi dung: "<<endl;
				newmh.display();
			}
		}
		
		void thongke() {
		    cout << "\nThong ke so luong mat hang ton kho: " << endl;
		    for (int i = 0; i < mathang.get_size(); i++) {
		        int soLuongTon = 0;
		        for (int j = 0; j < mathang.get_size(); j++) {
		            if (mathang[i].get_mahang() == mathang[j].get_mahang()) {
		                soLuongTon += mathang[j].get_sl();
		            }
		        }

				for (int j = 0; j < newmh.get_size(); j++) {
		            if (newmh[j].get_mahang() == mathang[i].get_mahang()){
		                soLuongTon += newmh[j].get_sl();
		            }
		        }
				for (int j = 0; j < hd.get_size(); j++) {
		            if (hd[j].get_loaihd() == "Sell" && hd[j].get_mahang() == mathang[i].get_mahang()) {
		                soLuongTon -= hd[j].get_slg();
		            }
		        }
		        cout << "Ma hang: " << mathang[i].get_mahang() << " , Ten hang: " << mathang[i].get_tenhang() << " , So luong ton kho: " << soLuongTon << endl;
		    }
		    if (newmh.get_size() == 0) {
		        cout << "Khong co mat hang nao duoc nhap." << endl;
		    }
		    for (int i = 0; i < newmh.get_size(); i++) {
		        bool found = false;
		        for (int j = 0; j < mathang.get_size(); j++) {
		            if (newmh[i].get_mahang() == mathang[j].get_mahang()) {
		                found = true;
		                break;
		            }
		        }
		
		        if (!found) {
		            int soLuongTon = newmh[i].get_sl();
		            for (int j = 0; j < hd.get_size(); j++) {
		                if (hd[j].get_loaihd() == "Sell" && hd[j].get_mahang() == newmh[i].get_mahang()) {
		                    soLuongTon -= hd[j].get_slg();
		                }
		            }
		            cout << "Ma hang: " << newmh[i].get_mahang() << " , Ten hang: " << newmh[i].get_tenhang() << " , So luong ton kho: " << soLuongTon << endl;
		        }
		    }
		}
};

int main(){
	CuaHang ch;
	int choice;
	
	ch.laydl("mathang.txt", true);
	ch.laydl("hoadon.txt", false);
	
	do{
		cout << "-------MENU-------"<< endl;
        cout << "1. Nhap mat hang" << endl;
        cout << "2. Hien thi mat hang da nhap"<<endl;
        cout << "3. Nhap hoa don" << endl;
        cout << "4. Hien thi hoa don da nhap"<<endl;
        cout << "5. Hien thi danh sach mat hang" << endl;
        cout << "6. Thong ke mat hang ton kho" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> choice;
        
        switch(choice){
        	case 1:
        		ch.nhapmathang();
        		ch.ghidl("output1.txt", true);
        		break;
        	case 2:
        		ch.xuatmathang();
        		break;
        	case 3:
        		ch.nhaphoadon();
        		ch.ghidl("output2.txt", false);
        		break;
        	case 4:
                ch.xuathoadon();
                break;
            case 5:
                ch.hienthimathang("mathang.txt"); 
                break;
            case 6:
                ch.thongke();
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
            }
		} while(choice != 0);
}

