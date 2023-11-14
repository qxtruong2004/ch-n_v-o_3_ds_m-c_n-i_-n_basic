#include <iostream>
#include <iomanip>
using namespace std;
// Cho m?t danh sách móc n?i don ch?a thông tin v? 5 thí sinh, m?i thí sinh g?m: S? báo 
//danh, h? và tên thí sinh, t?ng di?m thi
struct sinhvien{
	string sbd;
	string hoten;
	double bangdiem;
};
struct Node{
	sinhvien infor;
	Node *next = NULL; 
};
//khai bao kieu con tro Node
typedef Node *tro;
//khoi tao danh sach rong
void create (tro &L){
	L = NULL;
}
void nhap(sinhvien &x){
	cout<< "Nhap SBD cho sinh vien: ";
	cin >> x.sbd;
	fflush(stdin);
	cout << "Nhap ho ten cho sinh vien: ";
	getline(cin, x.hoten);
	cout << "Nhap diem cho sinh vien: ";
	cin >> x.bangdiem;
}
void nhapds(tro &L){
	tro P, Q;
	int result;
	sinhvien x;
	int d = 0; // so luong sinh vien co trong danh sach
	L = NULL;
	do{
		nhap(x);
		P = new Node;
		P->infor = x;
		P->next = NULL;
		if( L == NULL){
			L = P;
		}
		else{
			Q->next = P;
		}
		Q=P;
		d++;
		cout << "Nhap 0 neu ban muon dung lai: ";
		cin >> result;
	} while (result != 0);
}
void inds(tro &L){
	cout << setw(8) << "Ma";
	cout << setw(15) << "Ho va ten";
	cout << setw(6) << "Diem" << endl;
	if(L == NULL) {
		cout << "Danh sach rong";
		return ;
	}
	tro Q = L;
	while(Q != NULL){
		sinhvien x = Q->infor;
		cout << setw(8) << x.sbd;
		cout << setw(15) << x.hoten;
		cout << setw(6) << x.bangdiem << endl;
		Q = Q->next;
	}
}
// tim vi tri de chen vao
tro timvt(int &vt, tro L){
	int dem = 0;
	tro Q;
	Q = L;
	if (vt == 0) return L;
	else{
		while (Q->next != NULL && dem < vt -1){
			Q = Q->next;
			dem++;
		}
		return Q;
	}
}
tro chen(tro &L, int k, sinhvien x){
	tro P, Q;
	int Z = k-1;
		P = timvt(Z, L);// con tro dung truoc cho can chen VD: chen 3 thi P = 2
		if(P == NULL){
			cout << "Danh sach rong khong the chen vao ";
			return NULL;
	    }
	    else {
	    	Q = new Node;
	    	nhap(x);
			Q->infor = x;
	        Q->next = P->next;
	        P->next = Q;
	        return Q;
	    }
}
void chenvaovitri(tro L){
	sinhvien X;
	int k;
	cout << "Nhap vao vi tri can chen: ";
	cin >> k;
	chen(L, k, X);
	cout << "\nDa chen thanh cong";
}
int main(){
	sinhvien x;
	tro L;
	nhapds(L);
	cout << "Danh sach sinh vien vua nhap la: \n";
	inds(L);
	chenvaovitri(L);
	cout << "Danh sach sau khi chen la: \n";
	inds(L);
	return 0;
}

