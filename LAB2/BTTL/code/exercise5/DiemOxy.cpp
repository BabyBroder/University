#include "../exercise1/Diem.cpp"

void NhanDoi(Diem &x)
{
    x.SetHoanhDo(x.GetHoanhDo() * 2);
    x.SetTungDo(x.GetTungDo() * 2);
}

void GanVeO(Diem &x)
{
    x.SetHoanhDo(0);
    x.SetTungDo(0);
}

void TinhTien(Diem& x)
{
    int k;
    float dolon;
    std::cin >> k >> dolon;
    if(k){
        x.SetTungDo(x.GetTungDo() + dolon);
    }else{
        x.SetHoanhDo(x.GetHoanhDo() + dolon);
    }
}
