#include<iostream>
#include<list>
#include<string>
using namespace std;

class Employee{
	private:
		string empcode;
		string name;
		string dept;
		int day_working;
		float salary_perf;
	public:
		Employee(): empcode(""),name(""),dept(""),day_working(0),salary_perf(0.0f){}
		
		friend istream& operator>>(istream& is, Employee& emp){
			cout<<"Nhap ma nhan vien: ";
			is >> emp.empcode;
			cout<<"Nhap ten nhan vien: ";
			is >> emp.name;
			cout<<"Nhap ten bo phan: ";
			is >> emp.dept;
			cout<<"Nhap so ngay di lam: ";
			is >> emp.day_working;
			cout<<"Nhap he so luong: ";
			is >> emp.salary_perf;
			return is;
		}
		friend ostream& operator<<(ostream& os, const Employee& emp){
			os <<"---------------"<<endl;
			os <<"Ma nhan vien: "<<emp.empcode<<endl;
			os <<"Ten nhan vien: "<<emp.name<<endl;
			os <<"Ten bo phan: "<<emp.dept<<endl;
			os <<"So ngay di lam: "<<emp.day_working<<endl;
			os <<"He so luong: "<<emp.salary_perf<<endl;
			return os;
		}
		bool operator<(const Employee& other){
			return this->name < other.name;
		}
		float tinhLuong() const {
     	   return day_working * salary_perf;
    	}
		
		friend class Node;
		
		string get_empcode() const{return empcode;}
};

class Node{
	private:
		list<Employee> ds;
	public:
		Node(){}
		void themNV(){
			int n;
			cout<<"Nhap so luong nhan vien muon them: ";
			cin>>n;
			for(int i=0; i<n; i++){
				Employee emp;
				cin>>emp;
				ds.push_back(emp);
			}
			if(n<=0){
				cout<<"\nKhong them nhan vien nao"<<endl;
			}
			else{
				cout<<"\nDa them nhan vien"<<endl;
			}
		}
		void inDs(){
			if(ds.empty()){
				cout<<"Danh sach rong"<<endl;
				return;
			}
			cout<<"\nDanh sach nhan vien la: "<<endl;
			for(const auto& emp : ds){
				cout<<emp<<endl;
			}
		}
		void tinhluong(){
			if(ds.empty()){
				cout<<"Danh sach rong"<<endl;
				return;
			}
			for(Employee emp : ds){
				cout<<"Luong cua nhan vien "<<emp.empcode<<" la: "<<emp.tinhLuong()<<endl;
			}
		}
		
		void inHsluong(){
			if(ds.empty()){
				cout<<"Danh sach rong"<<endl;
				return;
			}
			bool found = false;
			for(const auto& emp : ds){
				if(emp.salary_perf >= 2.5){
					if(!found){
						cout<<"Danh sach nhan vien co he so luong >= 2.5 la: "<<endl;
					}
					cout<<emp<<endl;
					found = true;
				}
			}
			if(!found){
				cout<<"\nKhong co nhan vien co he so luong >= 2.5"<<endl;
			}
		}
		void xoaNv(){
			if(ds.empty()){
				cout<<"Danh sach rong"<<endl;
				return;
			}
			string maNV;
            cout << "Nhap ma nhan vien can xoa: ";
            cin >> maNV;
			bool found = false;
		    for (auto it = ds.begin(); it != ds.end(); ++it) {
		        if (it->get_empcode() == maNV) {
		            ds.erase(it);
		            cout << "Da xoa nhan vien co ma: " << maNV << endl;
		            found = true;
		            break; 
		        }
		    }
		    if (!found) {
		        cout << "Khong tim thay nhan vien co ma: " << maNV << endl;
		    }
		}
		void sapxepTen(){
			if(ds.empty()){
				cout<<"Danh sach rong"<<endl;
				return;
			}
			ds.sort();
			cout<<"\nDa sap xep nhan vien\n";
		}
};

int main(){	
	Node dsnv;
	int choice;
	do {
        cout << "----- MENU -----" << endl;
        cout << "1. Them nhan vien" << endl;
        cout << "2. Xoa nhan vien theo ma" << endl;
        cout << "3. In danh sach nhan vien" << endl;
        cout << "4. Tinh luong nhan vien" << endl;
        cout << "5. In danh sach nhan vien co he so luong >= 2.5" << endl;
        cout << "6. Sap xep nhan vien"<<endl;
		cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dsnv.themNV();
                break;
            case 2:
                dsnv.xoaNv();
                break;
            case 3:
                dsnv.inDs();
                break;
            case 4: 
                dsnv.tinhluong();
                break;
            case 5: 
            	dsnv.inHsluong();
				break;
			case 6: 
				dsnv.sapxepTen();
				break;
			case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
            	cout<<"Ky tu khong hop le"<<endl;
				break;
        }
    } while (choice != 0);
}
