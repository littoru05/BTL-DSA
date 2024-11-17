#include<iostream>
#include<iterator>
#include<fstream>
#include<string>
#include<stdexcept>
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
	//Iterators
		// Tra ve iterator toi phan tu dau tien
	    	T* begin(){
			return data;
	    	}
	
		 // Tra ve iterator toi phan tu ngay sau phan tu cuoi cung
		T* end(){
			return data + size;
		}
		
	    	// Tra ve reverse iterator toi phan tu cuoi cung
		reverse_iterator<T*> rbegin(){
			return reverse_iterator<T*>(end());
		}
		
		// Tra ve reverse iterator toi phan tu ngay truoc phan tu dau tien
		reverse_iterator<T*> rend(){
			return reverse_iterator<T*>(begin());
		}
	//Modifiers
		// Gan gia tri cho cac phan tu trong vector
		void assign(int count, const T& value) {
			if(count > capacity){ 
				resize(count);
			}
			for(int i = 0; i < count; ++i){
				data[i] = value; 
			} 
			size = count;
		}
		// Them phan tu vao cuoi vector
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
		//Xoa phan tu o cuoi vector
		void pop_back() {
		    if(size > 0){
		        --size; 
		    } 
			else{
				cout << "Vector da rong" << endl;
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
				data = new_data;
			}
			for(int i=size; i>index; i--){
					data[i] = data[i-1];
			}
			data[index] = value;
			++size;
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
		// Xoa phan tu tu start den end
		void erase(int start, int end){
		    if(start < 0 || end >= size || start > end){
		        cout << "Vi tri khong hop ly" << endl;
		        return;
		    }
		    for (int i = end + 1; i < size; ++i) {
		        data[i - (end - start + 1)] = data[i];
		    }
		    size -= (end - start + 1);
		}
		// Them phan tu tai vi tri cu the
		void emplace(int index, T&& value) {
		    if(index < 0 || index > size){
		        cout << "\nNgoai pham vi" << endl;
		        return;
		    }
		    if(size == capacity){
		        capacity *= 2;
		        T* new_data = new T[capacity];
		        for(int i = 0; i < size; i++){
		            new_data[i] = data[i];
		        }
		        delete[] data;
		        data = new_data;
		    }
		    for(int i = size; i > index; i--){
		        data[i] = data[i - 1];
		    }
		    data[index] = value;
		    ++size;
		}
		//Them phan tu vao vi tri cuoi
		void emplace_back(const T& value){
		    if(size == capacity){
		        capacity *= 2;
		        T* new_data = new T[capacity];
		        for(int i = 0; i < size; ++i){
		            new_data[i] = data[i];
		        }
		        delete[] data;
		        data = new_data;
		    }
		    data[size++] = value;
		}
		// Xoa cac phan tu trong vector
		void clear(){ 
			size = 0;
		}
		// Gan gia tri cho cac phan tu trong vector
		void assign(int count, const T& value) {
			if (count > capacity) { 
				resize(count);
			}
			for(int i = 0; i < count; ++i){
				data[i] = value; 
			} 
			size = count;
		}
		// Cap du dung luong cho vector ma ko thay doi bo nho
		void reserve(int new_capacity){
			if(new_capacity > capacity){
				resize(new_capacity); 
			}
		} 
		// Hoan vi 
		void swap(Vector& other){ 
			swap(data, other.data);
			swap(size, other.size); 
			swap(capacity, other.capacity); 
		}
		// Xoa cac phan tu trong vector
		void clear(){ 
			size = 0;
		}
	//Capacity
		// Lay kich thuoc hien tai cua vector
		int get_size(){
			return size;
		}
		// Tra ve kich thuoc toi da cua vector
		int max_size() const{
			return capacity; 
		}
		//Tra ve dung luong hien tai cua vector
		int get_capacity(){
			return capacity;
		}
		// Thay doi kich thuoc
		void resize(int new_size){
		    if(new_size <= capacity){
		    	return; 	
			}
		    capacity = new_size;
		    T* new_data = new T[capacity];
		    for(int i = 0; i < size; ++i){
		        new_data[i] = data[i];
		    }
		    delete[] data;
		    data = new_data;
		}
		//Thay doi kich thuoc va gan gia tri
		void resize(int new_size, const T& value){
		    if(new_size <= capacity){
		        size = new_size;
		    } 
			else{
		        capacity = new_size;
		        T* new_data = new T[capacity];
		        for(int i = 0; i < size; ++i){
		            new_data[i] = data[i];
		        }
		        for(int i = size; i < new_size; ++i){
		            new_data[i] = value;
		        }
		        delete[] data;
		        data = new_data;
		        size = new_size;
		    }
		}
		//Hien thi vector
		void display() const{
			for(int i=0; i<size; i++){
				cout<<data[i]<<endl;
			}
		}
		// Tra ve dung luong toi da 
		int max_size() const {
			return capacity; 
		}
		// Kiem tra rong 
		bool empty() const{ 
			return size == 0;
		}
		// Thu gon dung luong cua vector va kich thuoc phan tu
		void shrink_to_fit(){
		    if(size < capacity){
		        capacity = size;
		        T* new_data = new T[capacity];
		        for(int i = 0; i < size; ++i){
		            new_data[i] = data[i];
		        }
		        delete[] data;
		        data = new_data;
		    }
		}
		// Cap du dung luong cho vector ma ko thay doi bo nho
		void reserve(int new_capacity){
			if(new_capacity > capacity){
				resize(new_capacity); 
			}
		} 
	//Element access
		//Truy cap phan tu va kiem tra loi
		T& at(int index){
		    if(index < 0 || index >= size){
		        throw out_of_range("Phan tu ngoai pham vi"); 
		    }
		    return data[index];
		}
		// Lay du lieu cua vector
		T& get_data(){
		    return data;
		}
		// Lay phan tu dau tien
		T& front(){
		    if(size == 0){
		        throw out_of_range("Vector rong");
		    }
		    return data[0];
		}
		// Lay phan tu cuoi cung
		T& back(){
		    if(size == 0){
		        throw out_of_range("Vector rong");
		    }
		    return data[size - 1];
		}
		// Lay phan tu theo chi so
		T& operator[](int index){
		    return data[index];
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
		
		DanhMuc(string ma, string ten, string sx, int sl): mahang(ma), tenhang(ten), nsx(sx), sl(sl){}
		
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
            return (this->mahang == other.mahang) && (this->tenhang == other.tenhang);
        }
        
		friend ostream& operator<<(ostream& os, const DanhMuc& mathang) {
			os<<"Ma hang: "<<mathang.mahang<<" , Ten hang: "<<mathang.tenhang<<" , Nha san xuat: "<<mathang.nsx<<" , So luong: "<<mathang.sl<<endl;
		    return os;
		}		
				
		friend istream& operator>>(istream& is, DanhMuc& mathang){
			cout<<"Nhap ma hang: ";
			is >> mathang.mahang;
			cout<<"Nhap ten hang: ";
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
			cout<<"Ma hoa don: "<<mahd<<" ,Ma hang: "<<mahang<<" ,Loai hoa don: "<<loaihd<<" ,So luong hoa don: "<<slg<<" ,Ngay mua/ban: "<<ngay<<" ,Gia: "<<gia<<endl;
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
			os<<"Ma hoa don: "<<hd.mahd<<" ,Ma hang: "<<hd.mahang<<" ,Loai hoa don: "<<hd.loaihd<<" ,So luong hoa don: "<<hd.slg<<" ,Ngay mua/ban: "<<hd.ngay<<" ,Gia: "<<hd.gia<<endl;
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
				bool trunglap = false;
				do {
		            cout << "Nhap mat hang thu " << (i + 1) << ":\n";
		            cin >> mh;
		            trunglap = false;
		            for(int j = 0; j < mathang.get_size(); j++){
		                if(mh.get_mahang() == mathang[j].get_mahang() || mh.get_tenhang() == mathang[j].get_tenhang()){ 
		                    trunglap = true;
		                    cout << "Da co mat hang nay, vui long nhap lai...\n";
		                    break;
		                }
		            }
		        } while (trunglap); 
		        newmh.push_back(mh);
			mathang.push_back(mh);			
			}
			cout<<"\nDa nhap mat hang."<<endl;
		}
		
		void xuatmathang(){
			if(newmh.get_size()==0){
				cout<<"\nKhong co mat hang nao duoc nhap."<<endl;
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
				cout<<"\nKhong co hoa don nao duoc nhap."<<endl;
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

		void hienthihoadon(const string& filename){
			ifstream file(filename);
			if(!file){
				cout<<"Khong mo duoc file"<<endl;
				return;
			}
			HoaDon hoadon;
			cout<<"\nDanh sach hoa don tu file: "<<endl;
			while(file >> hoadon){
				hoadon.display();
			}
			file.close();
			if(newhd.get_size()==0){
				cout<<"\nKhong co hoa don nao duoc nhap tu nguoi dung"<<endl;
			}
			else{
				cout<<"\nDanh sach hoa don da nhap tu nguoi dung: "<<endl;
				newhd.display();
			}
		}
				
		void thongke() {
		    cout << "\nThong ke so luong mat hang ton kho: " << endl;
		    for (int i = 0; i < mathang.get_size(); i++) {
		        int soLuongTon_file = 0;
		        int vt=0;
		        for (int j = 0; j < mathang.get_size(); j++) {
		            if (mathang[i].get_mahang() == mathang[j].get_mahang()) {
		                soLuongTon_file += mathang[j].get_sl();
		            }
		        }
				for (int j = 0; j < hd.get_size(); j++) {
		            if (hd[j].get_loaihd() == "Sell" && hd[j].get_mahang() == mathang[i].get_mahang()) {
		                soLuongTon_file -= hd[j].get_slg();
		                vt += j;
		            }
		        }
		        if(soLuongTon_file<0){
		            	cout << "\nMa hang: " << mathang[i].get_mahang() << endl;
						cout << "Ten hang: " << mathang[i].get_tenhang() << endl;
						cout << "So luong ton kho: Chi ban duoc "<<mathang[i].get_sl()<<" mat hang , con "<<hd[vt].get_slg() - mathang[i].get_sl()<<" mat hang khong the ban duoc vi het hang"<<endl;
					}
					else{
		          		cout << "\nMa hang: " << mathang[i].get_mahang() << endl;
						cout << "Ten hang: " << mathang[i].get_tenhang() << endl;
						cout << "So luong ton kho: " << soLuongTon_file << endl;
					}
		        }
		    if (newmh.get_size() == 0) {
		        cout << "\nKhong co mat hang nao duoc nhap." << endl;
		    }
		    for (int i = 0; i < newmh.get_size(); i++) {
		        bool found = false;
		        for (int j = 0; j < mathang.get_size(); j++) {
		            if (newmh[i].get_mahang() == mathang[j].get_mahang()) {
		                found = true;
		                break;
		            }
		        }
				int soLuongTon_nhap = 0;
				for (int j = 0; j < newmh.get_size(); j++) {
		            if (newmh[j].get_mahang() == mathang[i].get_mahang()){
		                soLuongTon_nhap += newmh[j].get_sl();
		            }
		        }
		        if (!found) {
		            int soLuongTon_nhap = newmh[i].get_sl();
		            int pos = 0;
		            for (int j = 0; j < hd.get_size(); j++) {
		                if (hd[j].get_loaihd() == "Sell" && hd[j].get_mahang() == newmh[i].get_mahang()) {
		                    soLuongTon_nhap -= hd[j].get_slg();
		                    pos += j;
		                }
		            }
		            if(soLuongTon_nhap<0){
		            	cout << "\nMa hang: " << newmh[i].get_mahang() << endl;
						cout << "Ten hang: " << newmh[i].get_tenhang() << endl;
						cout << "So luong ton kho: Chi ban duoc "<<newmh[i].get_sl()<<" mat hang , con "<<hd[pos].get_slg() - newmh[i].get_sl()<<" mat hang khong the ban duoc vi het hang"<<endl;
					}
					else{
		          		cout << "\nMa hang: " << newmh[i].get_mahang() << endl;
						cout << "Ten hang: " << newmh[i].get_tenhang() << endl;
						cout << "So luong ton kho: " << soLuongTon_nhap << endl;
					}
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
        cout << "6. Hien thi danh sach hoa don" << endl;
        cout << "7. Thong ke mat hang ton kho" << endl;
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
                ch.hienthihoadon("hoadon.txt"); 
                break;
            case 7:
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
