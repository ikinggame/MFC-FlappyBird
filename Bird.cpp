#include "pch.h"
#include "Bird.h"
#include <afxwin.h> 
Bird::Bird() : position(100, 300), radius(20), velocity(0), gravity(0.5), Died(false), Trang_thai_chet(0) {}

void Bird::Draw(CDC* pDC) {
    //// Tạo đối tượng CImage để chứa hình ảnh chim
    CImage birdImage;

    //// Tải hình ảnh PNG vào CImage (Đảm bảo đường dẫn đúng)
    HRESULT hr = birdImage.Load(_T(".\\res\\bird.png"));

    //// Nếu tải hình ảnh thành công, vẽ nó
    if (SUCCEEDED(hr)) {
        // Vẽ hình ảnh chim vào bối cảnh vẽ, với vị trí được xác định bởi 'position'
        birdImage.Draw(pDC->m_hDC, position.x - radius, position.y - radius, radius * 2, radius * 2);
    }
    else {
        // Nếu không tải được hình ảnh, có thể vẽ hình ellipse như một fallback
        pDC->Ellipse(position.x - radius, position.y - radius,
            position.x + radius, position.y + radius);
    }
 
}

void Bird::Update() {

    if (!Died) {
        velocity += gravity;
        position.y += static_cast<int>(velocity);
    }
    else {
        velocity += gravity;
        position.y += static_cast<int>(velocity);
    }
   
}

void Bird::Flap() {
    velocity = -8; // Chim nhảy lên
}

void Bird::Reset()
{
    position = { 100, 300 }; // Đặt vị trí mặc định (100, 300)
    velocity = 0;          // Đặt tốc độ ban đầu bằng 0
    Died = false;
    Trang_thai_chet = 0;
}

void Bird::Die()
{
    Died = true;
    velocity = -8;
    Trang_thai_chet = 90;
}
