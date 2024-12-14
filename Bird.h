#pragma once
class Bird
{
public:
    Bird();
    void Draw(CDC* pDC);
    void Update();
    void Flap();
    void Reset();
    CPoint position;
    int radius;
    double velocity;
    double gravity;
    void Die();//chet
    int Died;
    double Trang_thai_chet;
};

