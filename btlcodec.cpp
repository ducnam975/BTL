#include <stdio.h>
#include <string.h>
#include <windows.h>

// Khai báo struct HocSinh
typedef struct {
    char ten[50];
    int maSo;
    float diemTK;
} HocSinh;

// Khai báo struct GiaoVien
typedef struct {
    char ten[50];
    char monDay[50];
} GiaoVien;

// Hàm hiển thị thông tin học sinh
void hienThiThongTin(HocSinh hs) {
    printf("Ten: %s, Ma so: %d, DiemTK: %.2f\n", hs.ten, hs.maSo, hs.diemTK);
}

// Hàm tìm kiếm học sinh
int timKiemHocSinh(HocSinh danhSach[], int soLuong, int maSo) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].maSo == maSo) {
            return i; 
        }
    }
    return -1;
}

// Hàm sắp xếp danh sách học sinh
void sapXepDanhSachHocSinh(HocSinh danhSach[], int soLuong) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (danhSach[i].diemTK < danhSach[j].diemTK) {
                HocSinh temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

// Hàm thêm mới giáo viên
void themGiaoVien(GiaoVien danhSachGiaoVien[], int* soLuongGiaoVien) {
    if (*soLuongGiaoVien < 100) {
        printf("Nhap ten giao vien: ");
        scanf("%s", danhSachGiaoVien[*soLuongGiaoVien].ten);
        printf("Nhap mon day cua giao vien: ");
        scanf("%s", danhSachGiaoVien[*soLuongGiaoVien].monDay);
        (*soLuongGiaoVien)++;
    } else {
        printf("Danh sach giao vien da day.\n");
    }
}

// Hàm hiển thị danh sách giáo viên
void hienThiDanhSachGiaoVien(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien) {
    printf("Danh sach giao vien:\n");
    for (int i = 0; i < soLuongGiaoVien; ++i) {
        printf("Ten: %s, Mon day: %s\n", danhSachGiaoVien[i].ten, danhSachGiaoVien[i].monDay);
    }
}

// Hàm sửa thông tin giáo viên
void suaGiaoVien(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien, char* tenCanSua) {
    for (int i = 0; i < soLuongGiaoVien; ++i) {
        if (strcmp(danhSachGiaoVien[i].ten, tenCanSua) == 0) {
            printf("Nhap ten moi cho giao vien: ");
            scanf("%s", danhSachGiaoVien[i].ten);
            printf("Nhap mon day moi cho giao vien: ");
            scanf("%s", danhSachGiaoVien[i].monDay);
            printf("Thong tin giao vien da duoc cap nhat.\n");
            return;
        }
    }
    printf("Khong tim thay giao vien co ten %s.\n", tenCanSua);
}

// Hàm xóa giáo viên khỏi danh sách
void xoaGiaoVien(GiaoVien danhSachGiaoVien[], int* soLuongGiaoVien, char* tenCanXoa) {
    int viTriXoa = -1;
    for (int i = 0; i < *soLuongGiaoVien; ++i) {
        if (strcmp(danhSachGiaoVien[i].ten, tenCanXoa) == 0) {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1) {
        for (int i = viTriXoa; i < *soLuongGiaoVien - 1; ++i) {
            strcpy(danhSachGiaoVien[i].ten, danhSachGiaoVien[i + 1].ten);
            strcpy(danhSachGiaoVien[i].monDay, danhSachGiaoVien[i + 1].monDay);
        }
        (*soLuongGiaoVien)--;
        printf("Da xoa giao vien %s khoi danh sach.\n", tenCanXoa);
    } else {
        printf("Khong tim thay giao vien co ten: %s.\n", tenCanXoa);
    }
}

// Hàm tìm kiếm giáo viên
void timKiemGiaoVien(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien, char* tenCanTim) {
    int timThay = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < soLuongGiaoVien; ++i) {
        if (strcmp(danhSachGiaoVien[i].ten, tenCanTim) == 0) {
            printf("Ten: %s, Mon day: %s\n", danhSachGiaoVien[i].ten, danhSachGiaoVien[i].monDay);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay giao vien co ten: %s.\n", tenCanTim);
    }
}

// Hàm sắp xếp giáo viên theo tên
void sapXepTheoTen(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien) {
    for (int i = 0; i < soLuongGiaoVien - 1; ++i) {
        for (int j = i + 1; j < soLuongGiaoVien; ++j) {
            if (strcmp(danhSachGiaoVien[i].ten, danhSachGiaoVien[j].ten) > 0) {
                GiaoVien temp = danhSachGiaoVien[i];
                danhSachGiaoVien[i] = danhSachGiaoVien[j];
                danhSachGiaoVien[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach giao vien theo ten.\n");
}

typedef struct {
    int ma_so;
    char ten[50];
    char mon_hoc[50];
    char lop_hoc[10];
} TaiNguyenTaiLieu;

TaiNguyenTaiLieu tai_lieu[1000];
int so_luong = 0;
int ma_so_counter = 1;

void hien_thi_tai_lieu(TaiNguyenTaiLieu* tl) {
    printf("Ma so: %d\n", tl->ma_so);
    printf("Ten: %s\n", tl->ten);
    printf("Mon hoc: %s\n", tl->mon_hoc);
    printf("Lop hoc: %s\n", tl->lop_hoc);
}

void hien_thi_danh_sach() {
    for (int i = 0; i < so_luong; i++) {
        hien_thi_tai_lieu(&tai_lieu[i]);
        printf("\n");
    }
}

void them_tai_lieu() {
    if (so_luong >= 1000) {
        printf("Danh sach tai lieu da day.\n");
        return;
    }

    TaiNguyenTaiLieu* new_tl = &tai_lieu[so_luong];
    new_tl->ma_so = ma_so_counter++;
    printf("Nhap ten tai lieu: ");
    scanf(" %[^\n]", new_tl->ten);
    printf("Nhap mon hoc: ");
    scanf(" %[^\n]", new_tl->mon_hoc);
    printf("Nhap lop hoc: ");
    scanf(" %[^\n]", new_tl->lop_hoc);

    so_luong++;
    printf("Them tai lieu thanh cong.\n");
}

void sua_tai_lieu(int ma_so) {
    for (int i = 0; i < so_luong; i++) {
        if (tai_lieu[i].ma_so == ma_so) {
            printf("Nhap ten tai lieu moi: ");
            scanf(" %[^\n]", tai_lieu[i].ten);
            printf("Nhap mon hoc moi: ");
            scanf(" %[^\n]", tai_lieu[i].mon_hoc);
            printf("Nhap lop hoc moi: ");
            scanf(" %[^\n]", tai_lieu[i].lop_hoc);
            printf("Sua tai lieu thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay tai lieu voi ma so: %d\n", ma_so);
}

void xoa_tai_lieu(int ma_so) {
    int found = 0;
    for (int i = 0; i < so_luong; i++) {
        if (tai_lieu[i].ma_so == ma_so) {
            found = 1;
        }
        if (found && i < so_luong - 1) {
            tai_lieu[i] = tai_lieu[i + 1];
        }
    }
    if (found) {
        so_luong--;
        printf("Xoa tai lieu thanh cong.\n");
    } else {
        printf("Khong tim thay tai lieu voi ma so: %d\n", ma_so);
    }
}

void tim_kiem_tai_lieu(char* ten) {
    for (int i = 0; i < so_luong; i++) {
        if (strstr(tai_lieu[i].ten, ten)) {
            hien_thi_tai_lieu(&tai_lieu[i]);
            printf("\n");
        }
    }
}

void sap_xep_tai_lieu() {
    for (int i = 0; i < so_luong - 1; i++) {
        for (int j = i + 1; j < so_luong; j++) {
            if (strcmp(tai_lieu[i].ten, tai_lieu[j].ten) > 0) {
                TaiNguyenTaiLieu temp = tai_lieu[i];
                tai_lieu[i] = tai_lieu[j];
                tai_lieu[j] = temp;
            }
        }
    }
    printf("Sap xep tai lieu thanh cong.\n");
}

typedef struct {
    char maLop[20];
    char tenGV[50];
} LopHoc;

void themLopHoc(LopHoc danhSachLopHoc[], int* soLuongLopHoc) {
    if (*soLuongLopHoc < 1000) {
        printf("Nhap ma lop hoc: ");
        scanf("%s", danhSachLopHoc[*soLuongLopHoc].maLop);
        printf("Nhap ten cua giao vien chu nhiem: ");
        scanf("%s", danhSachLopHoc[*soLuongLopHoc].tenGV);
        (*soLuongLopHoc)++;
        printf("Them lop hoc thanh cong.\n");
    } else {
        printf("Danh sach lop hoc da day.\n");
    }
}

void hienThiDanhSachLopHoc(const LopHoc danhSachLopHoc[], int soLuongLopHoc) {
    printf("Danh sach lop hoc:\n");
    for (int i = 0; i < soLuongLopHoc; ++i) {
        printf("Ma Lop: %s, Ten giao vien chu nhiem: %s\n", danhSachLopHoc[i].maLop, danhSachLopHoc[i].tenGV);
    }
}

void suaLopHoc(LopHoc danhSachLopHoc[], int soLuongLopHoc, const char* tenCanSua) {
    int timThay = 0;
    for (int i = 0; i < soLuongLopHoc; ++i) {
        if (strcmp(danhSachLopHoc[i].tenGV, tenCanSua) == 0) {
            printf("Nhap ma moi cho lop hoc: ");
            scanf("%s", danhSachLopHoc[i].maLop);
            printf("Nhap ten moi cho giao vien: ");
            scanf("%s", danhSachLopHoc[i].tenGV);
            printf("Thong tin lop hoc da duoc cap nhat.\n");
            timThay = 1;
            break;
        }
    }
    if (!timThay) {
        printf("Khong tim thay lop hoc co ten %s.\n", tenCanSua);
    }
}

void xoaLopHoc(LopHoc danhSachLopHoc[], int* soLuongLopHoc, const char* tenCanXoa) {
    int timThay = 0;
    for (int i = 0; i < *soLuongLopHoc; ++i) {
        if (strcmp(danhSachLopHoc[i].tenGV, tenCanXoa) == 0) {
            for (int j = i; j < *soLuongLopHoc - 1; ++j) {
                danhSachLopHoc[j] = danhSachLopHoc[j + 1];
            }
            (*soLuongLopHoc)--;
            printf("Da xoa lop hoc %s khoi danh sach.\n", tenCanXoa);
            timThay = 1;
            break;
        }
    }
    if (!timThay) {
        printf("Khong tim thay lop hoc co ten %s.\n", tenCanXoa);
    }
}

void timKiemLopHoc(const LopHoc danhSachLopHoc[], int soLuongLopHoc, const char* tenCanTim) {
    int timThay = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < soLuongLopHoc; ++i) {
        if (strcmp(danhSachLopHoc[i].tenGV, tenCanTim) == 0) {
            printf("Ma Lop: %s, Ten giao vien chu nhiem: %s\n", danhSachLopHoc[i].maLop, danhSachLopHoc[i].tenGV);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay lop hoc co ten %s.\n", tenCanTim);
    }
}

void sapXepTheoTen(LopHoc danhSachLopHoc[], int soLuongLopHoc) {
    for (int i = 0; i < soLuongLopHoc - 1; ++i) {
        for (int j = i + 1; j < soLuongLopHoc; ++j) {
            if (strcmp(danhSachLopHoc[i].tenGV, danhSachLopHoc[j].tenGV) > 0) {
                LopHoc temp = danhSachLopHoc[i];
                danhSachLopHoc[i] = danhSachLopHoc[j];
                danhSachLopHoc[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach lop hoc.\n");
}
// Hàm khai báo struct Diem
struct Diem {
    char hoTen[50];
    float diemToan, diemVan, diemAnh;
    float diemTB;
    char xepLoai[15];
};
// Hàm nhâp diêm
void nhapDiem(struct Diem *d) {
    printf("Nhap ho ten hoc sinh: ");
    fgets(d->hoTen, 50, stdin);
    d->hoTen[strcspn(d->hoTen, "\n")] = '\0'; // Loai bo ky tu xuong dong
    printf("Nhap diem Toan: ");
    scanf("%f", &d->diemToan);
    printf("Nhap diem Van: ");
    scanf("%f", &d->diemVan);
    printf("Nhap diem Anh: ");
    scanf("%f", &d->diemAnh);
    getchar(); // Loai bo ky tu xuong dong sau khi doc diem Anh
    tinhDiemTB(d);
    xepLoaiHocLuc(d);
}
// Hàm tính diemTb
void tinhDiemTB(struct Diem *d) {
    d->diemTB = (d->diemToan + d->diemVan + d->diemAnh) / 3;
}
// Ham xep loai hoc luc
void xepLoaiHocLuc(struct Diem *d) {
    if (d->diemTB >= 9)
        strcpy(d->xepLoai, "Xuat sac");
    else if (d->diemTB >= 8)
        strcpy(d->xepLoai, "Gioi");
    else if (d->diemTB >= 7)
        strcpy(d->xepLoai, "Kha");
    else if (d->diemTB >= 5)
        strcpy(d->xepLoai, "Trung binh");
    else
        strcpy(d->xepLoai, "Yeu");
}
// Ham hien thi diem cua hoc sinh
void hienThiDiem(struct Diem d) {
    printf("%-20s %-10.1f %-10.1f %-10.1f %-10.1f %-15s\n",
           d.hoTen, d.diemToan, d.diemVan, d.diemAnh, d.diemTB, d.xepLoai);
}
// Hàm sua diem
void suaDiem(struct Diem *d, char *mon, float diemMoi) {
    if (strcmp(mon, "Toan") == 0)
        d->diemToan = diemMoi;
    else if (strcmp(mon, "Van") == 0)
        d->diemVan = diemMoi;
    else if (strcmp(mon, "Anh") == 0)
        d->diemAnh = diemMoi;
    tinhDiemTB(d);
    xepLoaiHocLuc(d);
}
// Hàm khai báo stuct Phuhuynh
 struct {
    char tenPH[50];
    char tenHS[50];
    char SDT[20];
} PhuHuynh;

// Hàm thêm moi phu huynh
void themPhuHuynh(PhuHuynh danhsachPhuHuynh[], int* soLuongPhuHuynh) {
    if (*soLuongPhuHuynh < 100) {
        printf("Nhap ten phu huynh: ");
        fgets(danhsachPhuHuynh[*soLuongPhuHuynh].tenPH, sizeof(danhsachPhuHuynh[*soLuongPhuHuynh].tenPH), stdin);
        danhsachPhuHuynh[*soLuongPhuHuynh].tenPH[strlen(danhsachPhuHuynh[*soLuongPhuHuynh].tenPH) - 1] = '\0';  

        printf("Nhap ten hoc sinh: ");
        fgets(danhsachPhuHuynh[*soLuongPhuHuynh].tenHS, sizeof(danhsachPhuHuynh[*soLuongPhuHuynh].tenHS), stdin);
        danhsachPhuHuynh[*soLuongPhuHuynh].tenHS[strlen(danhsachPhuHuynh[*soLuongPhuHuynh].tenHS) - 1] = '\0'; 

        printf("Nhap so dien thoai: ");
        fgets(danhsachPhuHuynh[*soLuongPhuHuynh].SDT, sizeof(danhsachPhuHuynh[*soLuongPhuHuynh].SDT), stdin);
        danhsachPhuHuynh[*soLuongPhuHuynh].SDT[strlen(danhsachPhuHuynh[*soLuongPhuHuynh].SDT) - 1] = '\0'; 

        (*soLuongPhuHuynh)++;
    } else {
        printf("Danh sach phu huynh da day.\n");
    }
}

// Hàm hiên thi danh sach phu huynh
void hienThiDanhsachPhuHuynh(const PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh) {
    printf("Danh sach phu huynh:\n");
    for (int i = 0; i < soLuongPhuHuynh; ++i) {
        printf("Ten phu huynh: %s, Ten hoc sinh: %s, So dien thoai phu huynh: %s\n",
               danhsachPhuHuynh[i].tenPH, danhsachPhuHuynh[i].tenHS, danhsachPhuHuynh[i].SDT);
    }
}

// Hàm xóa phu huynh khoi danh sach
void xoaPhuHuynh(PhuHuynh danhsachPhuHuynh[], int* soLuongPhuHuynh, const char* tenCanXoa) {
    int viTriXoa = -1;
    for (int i = 0; i < *soLuongPhuHuynh; ++i) {
        if (strcmp(danhsachPhuHuynh[i].tenPH, tenCanXoa) == 0) {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1) {
        for (int i = viTriXoa; i < *soLuongPhuHuynh - 1; ++i) {
            danhsachPhuHuynh[i] = danhsachPhuHuynh[i + 1];
        }
        (*soLuongPhuHuynh)--;
        printf("Da xoa phu huynh %s khoi danh sach.\n", tenCanXoa);
    } else {
        printf("Khong tim thay phu huynh co ten %s.\n", tenCanXoa);
    }
}

// Ham tim kiem phu huynh
void timKiemPhuHuynh(const PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh, const char* tenCanTim) {
    printf("Ket qua tim kiem:\n");
    int timThay = 0;
    for (int i = 0; i < soLuongPhuHuynh; ++i) {
        if (strcmp(danhsachPhuHuynh[i].tenPH, tenCanTim) == 0) {
            printf("Ten phu huynh: %s, Ten hoc sinh: %s, So dien thoai phu huynh: %s\n",
                   danhsachPhuHuynh[i].tenPH, danhsachPhuHuynh[i].tenHS, danhsachPhuHuynh[i].SDT);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay phu huynh co ten %s.\n", tenCanTim);
    }
}

// Ham sap xep phu huynh theo ten
void sapXepTheoTen(PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh) {
    for (int i = 0; i < soLuongPhuHuynh - 1; ++i) {
        for (int j = i + 1; j < soLuongPhuHuynh; ++j) {
            if (strcmp(danhsachPhuHuynh[i].tenPH, danhsachPhuHuynh[j].tenPH) > 0) {
                PhuHuynh temp = danhsachPhuHuynh[i];
                danhsachPhuHuynh[i] = danhsachPhuHuynh[j];
                danhsachPhuHuynh[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach phu huynh theo ten.\n");
}

#define THONG_BAO 10
#define LIEN_LAC 20
// Ham khai bao stuct ThongBao
typedef struct {
    char tieuDe[100];
    char noiDung[500];
} ThongBao;
// Hàm khai báo struct LienLac
typedef struct {
    char tenPhuHuynh[100];
    char hinhThuc[50];
    char noiDung[500];
} LienLac;
// Hàm khai báo struct QuanLy
typedef struct {
    ThongBao danhSachThongBao[THONG_BAO];
    LienLac danhSachLienLac[LIEN_LAC];
    int soLuongThongBao;
    int soLuongLienLac;
} QuanLy;
// Hàm tao thông bao
void taoThongBao(QuanLy *quanLy, char *tieuDe, char *noiDung) {
    if (quanLy->soLuongThongBao < THONG_BAO) {
        strcpy(quanLy->danhSachThongBao[quanLy->soLuongThongBao].tieuDe, tieuDe);
        strcpy(quanLy->danhSachThongBao[quanLy->soLuongThongBao].noiDung, noiDung);
        quanLy->soLuongThongBao++;
        printf("Thong bao da duoc gui: %s\n", tieuDe);
    } else {
        printf("Danh sach thong bao da day!\n");
    }
}
// Hàm ghi nhân liên lac 
void ghiNhanLienLac(QuanLy *quanLy, char *tenPhuHuynh, char *hinhThuc, char *noiDung) {
    if (quanLy->soLuongLienLac < LIEN_LAC) {
        strcpy(quanLy->danhSachLienLac[quanLy->soLuongLienLac].tenPhuHuynh, tenPhuHuynh);
        strcpy(quanLy->danhSachLienLac[quanLy->soLuongLienLac].hinhThuc, hinhThuc);
        strcpy(quanLy->danhSachLienLac[quanLy->soLuongLienLac].noiDung, noiDung);
        quanLy->soLuongLienLac++;
        printf("Da ghi nhan %s tu phu huynh: %s\n", hinhThuc, tenPhuHuynh);
    } else {
        printf("Danh sach lien lac da day!\n");
    }
}
// Hàm hiên thi thông báo
void hienThiThongBao(QuanLy *quanLy) {
    printf("\nDanh sach thong bao:\n");
    for (int i = 0; i < quanLy->soLuongThongBao; i++) {
        printf("Tieu de: %s\nNoi dung: %s\n", quanLy->danhSachThongBao[i].tieuDe, quanLy->danhSachThongBao[i].noiDung);
    }
}
// Hàm hiên thi liên lac
void hienThiLienLac(QuanLy *quanLy) {
    printf("\nDanh sach lien lac tu phu huynh:\n");
    for (int i = 0; i < quanLy->soLuongLienLac; i++) {
        printf("Phu huynh: %s\nHinh thuc: %s\nNoi dung: %s\n", quanLy->danhSachLienLac[i].tenPhuHuynh, quanLy->danhSachLienLac[i].hinhThuc, quanLy->danhSachLienLac[i].noiDung);
    }
}




int main() {
    HocSinh danhSachHocSinh[100];
    GiaoVien danhSachGiaoVien[100];
    int soLuongHocSinh = 0;
    int soLuongGiaoVien = 0;
    int choice, Choice;
    TaiNguyenTaiLieu tai_lieu[1000];
     int so_luong = 0;

    LopHoc danhSachLopHoc[100];
    int soLuongLopHoc = 0;

    struct Diem dsDiem[100];
    int soLuongDiem = 0;

    PhuHuynh dsPhuHuynh[100];
    int soLuongPhuHuynh = 0;

    QuanLy quanLy = { .soLuongThongBao = 0, .soLuongLienLac = 0 };

    while (1) {
        printf("\n===== MENU CHINH =====\n");
        printf("1. Quan ly hoc sinh\n");
        printf("2. Quan ly giao vien\n");
        printf("3. Quan ly lop hoc\n");
        printf("6. Quan ly tai lieu tai nguyen\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
                printf("\n===== QUAN LY HOC SINH =====\n");
                printf("1. Them hoc sinh\n");
                printf("2. Hien thi thong tin hoc sinh\n");
                printf("3. Tim kiem hoc sinh\n");
                printf("4. Sap xep danh sach hoc sinh\n");
                printf("0. Quay lai menu chinh\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &Choice);

                switch (Choice) {
                    case 0:
                        break;
                    case 1:{
						system("cls");//Clear screen
                        if (soLuongHocSinh < 100) {
                            printf("Nhap ten hoc sinh: ");
                            scanf("%s", danhSachHocSinh[soLuongHocSinh].ten);
                            printf("Nhap ma so hoc sinh: ");
                            scanf("%d", &danhSachHocSinh[soLuongHocSinh].maSo);
                            printf("Nhap diem tong ket: ");
                            scanf("%f", &danhSachHocSinh[soLuongHocSinh].diemTK);
                            soLuongHocSinh++;
                        } else {
                            printf("Danh sach hoc sinh da day.\n");
                        }
                        break;}
                    case 2:{
						system("cls");//Clear screen
                        for (int i = 0; i < soLuongHocSinh; i++) {
                            hienThiThongTin(danhSachHocSinh[i]);
                        }
                        break;}
                    case 3: {
                    	system("cls");//Clear screen
                        int maSo;
                        printf("Nhap ma so hoc sinh can tim: ");
                        scanf("%d", &maSo);
                        int viTri = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSo);
                        if (viTri != -1) {
                            hienThiThongTin(danhSachHocSinh[viTri]);
                        } else {
                            printf("Khong tim thay hoc sinh co ma so %d.\n", maSo);
                        }
                        break;
                    }
                    case 4:{
						system("cls");//Clear screen
                        sapXepDanhSachHocSinh(danhSachHocSinh, soLuongHocSinh);
                        printf("Da sap xep danh sach hoc sinh theo diem tong ket.\n");
                        break;}
                    default:
                        printf("Lua chon khong hop le.\n");
                        break;
                }
                break;
            case 2:
                printf("\n===== QUAN LY GIAO VIEN =====\n");
                printf("1. Them giao vien\n");
                printf("2. Hien thi danh sach giao vien\n");
                printf("3. Sua thong tin giao vien\n");
                printf("4. Xoa giao vien\n");
                printf("5. Tim kiem giao vien\n");
                printf("6. Sap xep giao vien theo ten\n");
                printf("0. Quay lai menu chinh\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &Choice);

                switch (Choice) {
                    case 0:
                        break;
                    case 1:{system("cls");//Clear screen
						
					
                        themGiaoVien(danhSachGiaoVien, &soLuongGiaoVien);
                        break;}
                    case 2:{
						system("cls");//Clear screen
			
                        hienThiDanhSachGiaoVien(danhSachGiaoVien, soLuongGiaoVien);
                        break;}
                    case 3: {
                    	system("cls");//Clear screen
                        char tenCanSua[50];
                        printf("Nhap ten giao vien can sua: ");
                        scanf("%s", tenCanSua);
                        suaGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanSua);
                        break;
                    }
                    case 4: {
                    	system("cls");//Clear screen
                        char tenCanXoa[50];
                        printf("Nhap ten giao vien can xoa: ");
                        scanf("%s", tenCanXoa);
                        xoaGiaoVien(danhSachGiaoVien, &soLuongGiaoVien, tenCanXoa);
                        break;
                    }
                    case 5: {
                    	system("cls");//Clear screen
                        char tenCanTim[50];
                        printf("Nhap ten giao vien can tim: ");
                        scanf("%s", tenCanTim);
                        timKiemGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanTim);
                        break;
                    }
                    case 6:{
						system("cls");//Clear screen
                        sapXepTheoTen(danhSachGiaoVien, soLuongGiaoVien);
                        break;}
                    default:
                        printf("Lua chon khong hop le.\n");
                        break;
                }
                break;
                
                case 6:
                	
                	
               while (1) {
        printf("\nQuan ly tai lieu\n");
        printf("1. Them tai lieu\n");
        printf("2. Sua tai lieu\n");
        printf("3. Xoa tai lieu\n");
        printf("4. Hien thi danh sach tai lieu\n");
        printf("5. Tim kiem tai lieu\n");
        printf("6. Sap xep tai lieu\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                them_tai_lieu();
                break;
            case 2:
                printf("Nhap ma so tai lieu can sua: ");
                scanf("%d", &ma_so);
                sua_tai_lieu(ma_so);
                break;
            case 3:
                printf("Nhap ma so tai lieu can xoa: ");
                scanf("%d", &ma_so);
                xoa_tai_lieu(ma_so);
                break;
            case 4:
                hien_thi_danh_sach();
                break;
            case 5:
                printf("Nhap ten tai lieu can tim: ");
                scanf(" %[^\n]", ten);
                tim_kiem_tai_lieu(ten);
                break;
            case 6:
                sap_xep_tai_lieu();
                break;
            case 7:
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
    
    case 3:
    	do {
        printf("\nCHUONG TRINH QUAN LY LOP HOC\n");
        printf("1. Them lop hoc\n");
        printf("2. Sua thong tin lop hoc\n");
        printf("3. Xoa lop hoc\n");
        printf("4. Hien thi danh sach lop hoc\n");
        printf("5. Tim kiem lop hoc\n");
        printf("6. Sap xep lop hoc theo ten\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themLopHoc(danhSach, &soLuong);
                break;
            case 2:
                printf("Nhap ten giao vien can sua: ");
                scanf("%s", tenGV);
                suaLopHoc(danhSach, soLuong, tenGV);
                break;
            case 3:
                printf("Nhap ten giao vien can xoa: ");
                scanf("%s", tenGV);
                xoaLopHoc(danhSach, &soLuong, tenGV);
                break;
            case 4:
                hienThiDanhSachLopHoc(danhSach, soLuong);
                break;
            case 5:
                printf("Nhap ten giao vien can tim: ");
                scanf("%s", tenGV);
                timKiemLopHoc(danhSach, soLuong, tenGV);
                break;
            case 6:
                sapXepTheoTen(danhSach, soLuong);
                break;
            case 7:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }

    } while (luaChon != 7);

  
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    }

    return 0;
}
